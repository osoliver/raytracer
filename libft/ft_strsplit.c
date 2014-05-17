/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:39:04 by gmange            #+#    #+#             */
/*   Updated: 2014/03/06 16:16:18 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** it seem I should add a pointer to a string of only (char*)'\0',
** followed by a pointer to NULL, when receiving an empty string
** same with a string of 'c' separators only.
*/

static char		**ft_strsplit_sub(char *s, char c, size_t l_ptr)
{
	char		**tab;
	char		*ptr;
	size_t		i;

	if (!(tab = (char**)ft_memalloc(sizeof(*tab) * l_ptr)))
		return (NULL);
	i = 0;
	while (s && *s && i < l_ptr - 1)
	{
		while (*s == c && *s)
			s++;
		if ((ptr = (char*)ft_strchr(s, c)))
			tab[i++] = ft_strsub(s, 0, ptr - s);
		else
			tab[i++] = ft_strdup(s);
		s = ptr;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	char		*ptr;
	size_t		l_chr;
	size_t		l_ptr;
	size_t		i;

	if (!s)
		return (NULL);
	l_chr = ft_strlen(s);
	l_ptr = (l_chr == 0 || s[l_chr - 1] == c) ? 1 : 2;
	i = 0;
	ptr = (char*)s;
	while (ptr && i < l_chr)
	{
		while (s[i] == c && s[i])
			i++;
		if ((ptr = (char*)ft_strchr(s + i, c)) + 1 > s + i)
		{
			l_ptr++;
			i += ptr - (s + i) + 1;
		}
	}
	if (!(tab = ft_strsplit_sub((char*)s, c, l_ptr)))
		return (NULL);
	return (tab);
}
