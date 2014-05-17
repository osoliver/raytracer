/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:44:08 by gmange            #+#    #+#             */
/*   Updated: 2013/12/26 15:17:50 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char			*cs1;
	const char		*cs2;

	if (!s1 || !s2)
		return (NULL);
	cs1 = (char*)s1;
	cs2 = (char*)s2;
	while (n-- > 0)
		*(cs1++) = *(cs2++);
	return (s1);
}
