/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_selections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 14:17:43 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:13:36 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "edit.h"

int				apply_modification(t_env *env, t_list *ptr)
{
	t_buts		*b;
	t_mod		mod[5];

	mod[0] = NULL;
	mod[1] = grab_mode;
	mod[2] = scale_mode;
	mod[3] = rotate_mode;
	mod[4] = color_mode;
	b = ((t_buts *)ptr->content);
	if (!b->type && (!b->mode || (!env->selected && b->mode == 1)))
		unselect_object(env);
	else if (!b->type)
		mod[b->mode](env);
	if (b->type == 1)
		env->axis = b->mode - 5;
	if (b->type == 2 && (b->mode == 8 || b->mode == 9))
		movement_selection(env, env->axis, b->mode % 2);
	else if (b->type == 2)
		ref_modification(env, b->mode);
	else if (b->type == 3 && b->mode == 16)
		close_edit_window(env, 1);
	else if (b->type == 3 && b->mode == 17)
		key_edit_hook(T_ENTER, env);
	return (1);
}

static int		check_area(t_env *env, int x, int y, int type)
{
	t_list		*tmp;
	t_buts		*but;

	tmp = env->panel;
	while (tmp && ((t_buts *)tmp->content)->type != type)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	while (tmp && ((t_buts *)tmp->content)->type == type)
	{
		but = (t_buts *)tmp->content;
		if ((x > but->x && x < (but->x + but->wdt))
			&& (y > but->y && y < (but->y + but->hgt)))
			return (apply_modification(env, tmp));
		tmp = tmp->next;
	}
	return (0);
}

int				select_button(int x, int y, t_env *env)
{
	if (mode_buttons(x, y))
		check_area(env, x, y, e_modeb);
	else if (axis_buttons(x, y))
		check_area(env, x, y, e_axisb);
	else if (more_less_buttons(x, y))
		check_area(env, x, y, e_more_lessb);
	else if (done_buttons(x, y))
		check_area(env, x, y, e_doneb);
	return (0);
}
