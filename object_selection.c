/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:40:22 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/26 16:56:51 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "edit.h"

void		unselect_object(t_env *env)
{
	int		i;

	i = 0;
	if (!env->selected)
		return ;
	env->mod = _cam;
	while (i < 4)
	{
		env->selected->color[i] = env->selected->selec_color[i];
		env->selected->selec_color[i] = '\0';
		++i;
	}
	env->selected = NULL;
}

void		select_object(int x, int y, t_env *env)
{
	float	norm_x;
	float	norm_y;
	float	l[DIM];

	ft_bzero(l, DIM);
	norm_x = ((((E_WDT * y + x) % E_WDT) + 0.5) / E_WDT);
	norm_y = ((((E_WDT * y + x) / E_WDT) + 0.5) / E_HGT);
	D_RDIR[0] = ((2.0 * norm_x - 1.0) * ((float)WDT / (float)HGT) * FOV);
	D_RDIR[1] = ((1.0 - 2.0 * norm_y) * FOV);
	D_RDIR[2] = -1.0;
	normalize_ray(&(env->dot->rdir));
	env->dot->obj = env->obj;
	env->dot->cam = env->cam;
	env->dot->light = env->light;
	env->dot->dst = -1.0;
	trace_ray(env, env->dot, &l, env->C_POS_CAM);
	if (env->selected == env->dot->obj)
	{
		unselect_object(env);
		return ;
	}
	if (env->selected)
		unselect_object(env);
	env->selected = env->dot->obj;
	modify_object(env->selected);
}

void		next_object(t_env *env)
{
	t_obj	*tmp;

	tmp = env->selected;
	if (!env->selected)
		env->selected = env->obj;
	else if (env->selected && !env->selected->nxt)
	{
		unselect_object(env);
		env->selected = NULL;
		env->selected = env->obj;
	}
	else
	{
		unselect_object(env);
		env->selected = NULL;
		env->selected = tmp->nxt;
	}
	modify_object(env->selected);
}
