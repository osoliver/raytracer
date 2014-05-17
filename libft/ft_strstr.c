/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:28:21 by gmange            #+#    #+#             */
/*   Updated: 2013/12/04 10:37:12 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t		i1;
	size_t		i2;

	if (!*s2)
		return ((char*)s1);
	i1 = 0;
	while (s1[i1])
	{
		i2 = 0;
		while (s1[i1 + i2] == s2[i2])
		{
			if (!s2[++i2])
				return ((char*)s1 + i1);
		}
		i1++;
	}
	return (NULL);
}
