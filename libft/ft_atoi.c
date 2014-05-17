/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:31:53 by gmange            #+#    #+#             */
/*   Updated: 2014/01/25 17:41:27 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		nb;
	int		sign;

	nb = 0;
	while (ft_is_wht_spc(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		sign = (*(str++) == '-') ? -1 : 1;
	while (*str && ft_isdigit(*str))
		nb = nb * 10 + *(str++) - '0';
	return (sign * nb);
}
