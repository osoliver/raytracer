/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 13:33:19 by gmange            #+#    #+#             */
/*   Updated: 2013/12/20 13:34:40 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_swap(int *x, int *y)
{
	int		t;

	t = *x;
	*x = *y;
	*y = t;
}