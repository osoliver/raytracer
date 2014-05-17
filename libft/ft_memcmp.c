/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:53:35 by gmange            #+#    #+#             */
/*   Updated: 2013/12/26 15:21:10 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*cs1;
	const unsigned char		*cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (*cs1 != *cs2)
		{
			return (*cs1 - *cs2);
		}
		cs1++;
		cs2++;
	}
	return (0);
}
