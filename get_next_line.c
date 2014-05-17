/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:03:39 by gmange            #+#    #+#             */
/*   Updated: 2014/02/14 15:51:56 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

/*
** returns 0 when reading 0 and, leaves line == NULL
** ONLY if there is an empty end of line at the end of file...
*/

/*
** structures with the same fd are set in a row
*/

/*
** 3 reasons to come in:
** 1. chck, remaining struct with corresponding fd from previous read
** 2. chck buf after reading
** 3. read last bits.
*/

/*
** EOF == -1 in C or read == 0
*/

/*
** I check I have no new line already in memory
** would I have I fill line and send it already
** else
** I create a new structure to read in it
** I check it and read again until I find a line or finishes reading
*/
static int		del_cur(t_read **root, t_read *cur, int continu)
{
	t_read	*tmp;

	if (cur == *root)
		*root = GNL_NXT;
	else
	{
		tmp = *root;
		while (tmp->nxt != cur)
			tmp = tmp->nxt;
		tmp->nxt = GNL_NXT;
	}
	ft_memdel((void**)&GNL_BUF);
	ft_memdel((void**)&cur);
	return (continu);
}

static int		line_from_lst(char **line, t_read **root, int const fd)
{
	t_read		*cur;
	t_read		*tmp;
	size_t		i;

	cur = *root;
	while (GNL_FD != fd)
		cur = GNL_NXT;
	i = 0;
	while (cur && GNL_FD == fd)
	{
		while (GNL_IDX < GNL_SZE && GNL_BUF[GNL_IDX] != CHAR)
			(*line)[i++] = GNL_BUF[GNL_IDX++];
		if (GNL_BUF[GNL_IDX] == CHAR && ++GNL_IDX >= GNL_SZE)
			return (del_cur(root, cur, 1));
		if (GNL_IDX < GNL_SZE)
			return (1);
		tmp = GNL_NXT;
		if (GNL_IDX >= GNL_SZE)
			del_cur(root, cur, 1);
		cur = tmp;
	}
	return (0);
}

static int		find_endl(char **line, t_read **root, t_read *cur, int continu)
{
	t_read		*tmp;
	size_t		len;

	len = GNL_IDX;
	while (len < GNL_SZE && (unsigned char)GNL_BUF[len] != (unsigned char)CHAR)
		len++;
	if (!continu || (unsigned char)GNL_BUF[len] == (unsigned char)CHAR)
	{
		len -= GNL_IDX;
		tmp = *root;
		while (tmp->fd != GNL_FD)
			tmp = tmp->nxt;
		while (tmp != cur && (len += tmp->sze))
			tmp = tmp->nxt;
		if (!continu && len == 0)
			return (del_cur(root, cur, continu));
		if (!(*line = (char*)ft_memalloc(sizeof(char) * (len + 1))))
			return (-1);
		return (line_from_lst(line, root, GNL_FD));
	}
	return (0);
}

static t_read	*new_read(t_read **root, int const fd)
{
	t_read		*cur;

	if (!(cur = (t_read*)ft_memalloc(sizeof(*cur))))
		return (NULL);
	GNL_FD = fd;
	if (!(GNL_BUF = (char*)ft_memalloc(sizeof(*GNL_BUF) * GNL_BUF_SZE)))
	{
		ft_memdel((void**)&cur);
		return (NULL);
	}
	if ((int)(GNL_SZE = read(GNL_FD, GNL_BUF, GNL_BUF_SZE)) < 0)
	{
		ft_memdel((void**)&GNL_BUF);
		ft_memdel((void**)&cur);
		return (NULL);
	}
	GNL_IDX = 0;
	GNL_NXT = NULL;
	if (*root)
		GNL_NXT = (*root)->nxt;
	if (*root)
		(*root)->nxt = cur;
	else
		*root = cur;
	return (cur);
}

int				get_next_line(int const fd, char **line)
{
	size_t				ret;
	static t_read		*root = NULL;
	t_read				*cur;

	if (!line || (*line = NULL))
		return (-1);
	cur = root;
	while (cur && GNL_FD != fd)
		cur = GNL_NXT;
	if (cur && GNL_FD == fd && (ret = find_endl(line, &root, cur, 1)))
		return (ret);
	while (cur && GNL_FD == fd && GNL_NXT)
		cur = GNL_NXT;
	while (1)
	{
		if (root && !(cur = new_read(&cur, fd)))
			return (-1);
		if (!root && !(cur = new_read(&root, fd)))
			return (-1);
		if (!GNL_SZE)
			return (find_endl(line, &root, cur, 0));
		if ((ret = find_endl(line, &root, cur, 1)))
			return (ret);
	}
}
