/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strirchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 13:25:04 by gmange            #+#    #+#             */
/*   Updated: 2014/01/24 09:31:42 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strirchr(const char *s, int c)
{
	return ((unsigned char*)ft_strrchr(s, c) - (unsigned char*)s);
}
