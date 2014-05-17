/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:27:40 by gmange            #+#    #+#             */
/*   Updated: 2014/01/10 16:09:04 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	size_t		i;
	int			j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i++] == (char)c)
			j = i - 1;
	}
	if (s[i] == (char)c)
		return ((char*)s + i);
	if (j >= 0)
		return ((char*)s + j);
	else
		return (NULL);
}
