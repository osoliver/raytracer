/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:33:20 by gmange            #+#    #+#             */
/*   Updated: 2014/01/23 12:45:01 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_ptrlen(const void *p)
{
	size_t		i;
	char		**c;

	c = (char**)p;
	i = 0;
	while (c[i])
		i++;
	return (i);
}
