/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:33:45 by gmange            #+#    #+#             */
/*   Updated: 2014/02/07 14:29:07 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** should not protect from !b, for as an argument it is necessarily non NULL
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char		*str;

	if (!b)
		return (NULL);
	str = b;
	while (len-- > 0)
		*(str++) = (unsigned char)c;
	return (b);
}
