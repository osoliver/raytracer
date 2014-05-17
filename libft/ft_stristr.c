/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 09:28:20 by gmange            #+#    #+#             */
/*   Updated: 2014/01/24 09:33:11 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_stristr(const char *s1, const char *s2)
{
	return ((unsigned char*)ft_strstr(s1, s2) - (unsigned char*)s1);
}
