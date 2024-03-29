/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wht_spc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 09:30:21 by gmange            #+#    #+#             */
/*   Updated: 2014/01/14 10:14:37 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_is_wht_spc(const char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
