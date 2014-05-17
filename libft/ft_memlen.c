/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 14:03:26 by gmange            #+#    #+#             */
/*   Updated: 2013/12/28 14:27:53 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memlen(const void *s, int c, size_t n)
{
	return ((unsigned char*)ft_memchr(s, c, n) - (unsigned char*)s);
}
