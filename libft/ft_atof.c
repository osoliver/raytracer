/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:31:53 by gmange            #+#    #+#             */
/*   Updated: 2014/03/02 14:01:49 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(const char *str)
{
	float		nb;
	float		sign;
	int			dot;
	int			i;

	nb = 0;
	while (ft_is_wht_spc(*str))
		str++;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while ((unsigned int)i < sizeof(float) && str[i] && ft_isdigit(str[i]))
		nb = nb * 10 + str[i++] - '0';
	dot = sizeof(float) + 1;
	if (str[i] == '.')
		dot = ++i;
	while ((unsigned int)i < sizeof(float) && str[i] && ft_isdigit(str[i]))
		nb = nb * 10 + str[i++] - '0';
	while (i-- > dot)
		nb /= 10;
	return (sign * nb);
}
