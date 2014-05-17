/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:36:13 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/26 18:33:13 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

static void		modify_selected_color(t_obj *selected, int *color)
{
	selected->color[1] = color[1];
	selected->color[2] = color[2];
	selected->color[3] = color[3];
	selected->selec_color[1] = color[1];
	selected->selec_color[2] = color[2];
	selected->selec_color[3] = color[3];
}

static void		set_basic_color(unsigned char color[4])
{
	while (color[1] % 51)
		color[3] += 1;
	while (color[2] % 51)
		color[2] += 1;
	while (color[3] % 51)
		color[1] += 1;
}

static void		upper_object_color(t_env *env, int diff)
{
	int			color[4];

	color[1] = env->selected->selec_color[1];
	color[2] = env->selected->selec_color[2];
	color[3] = env->selected->selec_color[3];
	set_basic_color(env->selected->selec_color);
	color[3] += diff;
	if (color[3] > 255)
	{
		color[3] = 0;
		color[2] += diff;
	}
	if (color[2] > 255)
	{
		color[2] = 0;
		color[1] += diff;
	}
	if (color[1] > 255)
	{
		color[1] = 0;
		color[2] = 0;
		color[3] = 0;
	}
	modify_selected_color(env->selected, color);
}

static void		lower_object_color(t_env *env, int diff)
{
	int			color[4];

	color[1] = env->selected->selec_color[1];
	color[2] = env->selected->selec_color[2];
	color[3] = env->selected->selec_color[3];
	set_basic_color(env->selected->selec_color);
	color[3] += diff;
	if (color[3] < 0)
	{
		color[3] = 255;
		color[2] += diff;
	}
	if (color[2] < 0)
	{
		color[2] = 255;
		color[1] += diff;
	}
	if (color[1] < 0)
	{
		color[1] = 255;
		color[2] = 255;
		color[3] = 255;
	}
	modify_selected_color(env->selected, color);
}

int				object_color(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (!env->selected || !env->mod)
		return (0);
	if (more_less)
		upper_object_color(env, 51);
	else
		lower_object_color(env, -51);
	return (0);
}
