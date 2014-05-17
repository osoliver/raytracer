/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:27:36 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 20:04:27 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "edit.h"

static t_list	*set_mode_coords(t_list **ptr, int i)
{
	t_list		*tmp;

	tmp = (*ptr);
	if (((t_buts *)tmp->content)->x == (I_WDT + 14))
		((t_buts *)tmp->next->content)->x = (I_WDT + 107);
	else
		((t_buts *)tmp->next->content)->x = (I_WDT + 14);
	if (((t_buts *)tmp->content)->x == (I_WDT + 107))
		((t_buts *)tmp->next->content)->y = (((t_buts *)tmp->content)->y + 60);
	else
		((t_buts *)tmp->next->content)->y = ((t_buts *)tmp->content)->y;
	((t_buts *)tmp->content)->mode = i;
	((t_buts *)tmp->content)->type = e_modeb;
	((t_buts *)tmp->content)->wdt = 79;
	((t_buts *)tmp->content)->hgt = 40;
	tmp = tmp->next;
	return (tmp);
}

t_list			*set_mode_buttons(t_list **ptr)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = (*ptr);
	((t_buts *)tmp->content)->x = (I_WDT + 14);
	((t_buts *)tmp->content)->y = 20;
	while (i < 5)
		tmp = set_mode_coords(&tmp, i++);
	return (tmp);
}

t_list			*set_more_less_buttons(t_list **ptr)
{
	t_list		*tmp;
	int			y;
	int			i;

	i = 8;
	tmp = (*ptr);
	y = 270;
	while (i < 16)
	{
		if (i == 10)
			y += 30;
		if (((t_buts *)tmp->content)->name[6] == 'm')
			((t_buts *)tmp->content)->x = (I_WDT + 30);
		else
			((t_buts *)tmp->content)->x = (I_WDT + 145);
		if (tmp != (*ptr) && ((t_buts *)tmp->content)->name[6] == 'm')
			y += 50;
		((t_buts *)tmp->content)->y = y;
		((t_buts *)tmp->content)->mode = i++;
		((t_buts *)tmp->content)->type = e_more_lessb;
		((t_buts *)tmp->content)->wdt = 50;
		((t_buts *)tmp->content)->hgt = 50;
		tmp = tmp->next;
	}
	return (tmp);
}

t_list			*set_done_buttons(t_list **ptr)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = (*ptr);
	((t_buts *)tmp->content)->mode = 16;
	((t_buts *)tmp->next->content)->mode = 17;
	((t_buts *)tmp->content)->type = e_doneb;
	((t_buts *)tmp->next->content)->type = e_doneb;
	((t_buts *)tmp->content)->x = (I_WDT + 14);
	((t_buts *)tmp->next->content)->x = (I_WDT + 107);
	((t_buts *)tmp->content)->y = 530;
	((t_buts *)tmp->next->content)->y = 530;
	((t_buts *)tmp->content)->wdt = 80;
	((t_buts *)tmp->next->content)->wdt = 80;
	((t_buts *)tmp->content)->hgt = 40;
	((t_buts *)tmp->next->content)->hgt = 40;
	return (tmp);
}

t_list			*set_axis_buttons(t_list **ptr)
{
	int			i;
	int			x;
	t_list		*tmp;

	i = 5;
	tmp = (*ptr);
	x = 828;
	while (i < 8)
	{
		((t_buts *)tmp->content)->mode = i++;
		((t_buts *)tmp->content)->type = e_axisb;
		((t_buts *)tmp->content)->y = 200;
		((t_buts *)tmp->content)->x = x;
		x += 57;
		((t_buts *)tmp->content)->wdt = 30;
		((t_buts *)tmp->content)->hgt = 30;
		tmp = tmp->next;
	}
	return (tmp);
}
