/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:38:10 by gmange            #+#    #+#             */
/*   Updated: 2014/03/05 20:47:44 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*str;
	size_t		len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (len-- > 0 && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		(void)s;
	if (!(str = ft_strsub(s, 0, len + 1)))
		return (NULL);
	return (str);
}
