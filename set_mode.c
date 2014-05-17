/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 09:42:11 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 20:05:23 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

void		grab_mode(t_env *env)
{
	if (env->mod == _grab)
		env->mod = _cam;
	else
		env->mod = _grab;
}

void		scale_mode(t_env *env)
{
	if (env->mod == _scale)
		env->mod = _cam;
	else
		env->mod = _scale;
}

void		rotate_mode(t_env *env)
{
	if (env->mod == _rotate)
		env->mod = _cam;
	else
		env->mod = _rotate;
}

void		color_mode(t_env *env)
{
	if (!env->selected)
		return ;
	if (env->mod == _color)
		env->mod = _cam;
	else
		env->mod = _color;
	if (!env->mod != _color)
	{
		env->selected->color[0] = 0;
		env->selected->color[1] = 255;
		env->selected->color[2] = 0;
		env->selected->color[3] = 0;
	}
}
