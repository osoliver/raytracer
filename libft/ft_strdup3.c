/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 11:10:29 by gmange            #+#    #+#             */
/*   Updated: 2014/01/24 13:16:29 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup3(const char *s1, const char *s2, const char *s3)
{
	size_t	i;
	char	*s;

	if (!(s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3))))
		return (NULL);
	i = 0;
	while (*s1)
		s[i++] = *(s1++);
	while (*s2)
		s[i++] = *(s2++);
	while (*s3)
		s[i++] = *(s3++);
	s[i] = 0;
	return (s);
}
