/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 12:53:05 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:20:35 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

static int		move_y(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (more_less)
		env->cam->pos_wor[1] += 1;
	else
		env->cam->pos_wor[1] -= 1;
	return (1);
}

static int		move_x(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (!more_less)
		env->cam->pos_wor[0] -= 1;
	else
		env->cam->pos_wor[0] += 1;
	return (1);
}

static int		move_z(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (more_less)
		env->cam->pos_wor[2] -= 1;
	else
		env->cam->pos_wor[2] += 1;
	return (1);
}

int				move_camera(t_env *env, int axis, int more_less)
{
	t_mov		mov[3];

	mov[0] = move_x;
	mov[1] = move_y;
	mov[2] = move_z;
	if (env->selected)
		return (0);
	mov[axis](env, axis, more_less);
	return (1);
}
