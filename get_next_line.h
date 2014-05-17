/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:55:17 by gmange            #+#    #+#             */
/*   Updated: 2014/03/06 14:34:08 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** BUFF_SIZE should be an exponential of 2. Have it 8192.
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>

# define	GNL_BUF_SZE	3200
# define	CHAR		'\n'

typedef struct			s_read
{
	int					fd;
	char				*buf;
	size_t				sze;
	size_t				idx;
	struct s_read		*nxt;
}						t_read;

# define	GNL_FD		cur->fd
# define	GNL_BUF		cur->buf
# define	GNL_SZE		cur->sze
# define	GNL_IDX		cur->idx
# define	GNL_NXT		cur->nxt

int						get_next_line(int const fd, char **line);
#endif
