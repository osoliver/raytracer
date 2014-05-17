/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:07:33 by gmange            #+#    #+#             */
/*   Updated: 2013/12/04 12:23:50 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((char*)s1)[i] = ((char*)s2)[i];
		if (((char*)s2)[i++] == (unsigned char)c)
			return ((char*)s1 + i);
	}
	return (NULL);
}
