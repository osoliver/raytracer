/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:11:53 by gmange            #+#    #+#             */
/*   Updated: 2013/12/04 10:33:30 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** function shall not work with n <= 0, nor n > sizeof(s1).
*/

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	if (s1 < s2)
	{
		i = 0;
		while (i < n)
		{
			*((char*)s1 + i) = *((char*)s2 + i);
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			*((char*)s1 + n) = *((char*)s2 + n);
	}
	return (s1);
}
