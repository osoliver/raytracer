/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:00:50 by gmange            #+#    #+#             */
/*   Updated: 2013/12/26 15:20:23 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*cs;

	if (!s)
		return (NULL);
	cs = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*cs == (unsigned char)c)
			return ((void*)cs);
		cs++;
	}
	return (NULL);
}
