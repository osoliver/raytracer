/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:04:28 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:22:57 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

static int		rotate_x(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected || env->mod != _rotate)
		return (0);
	if (!more_less)
		env->cam->rot_wor[0] -= 1;
	else
		env->cam->rot_wor[0] += 1;
	env->cam->trf_mtx = init_trf_mtx(env->cam->rot_wor, env->cam->pos_wor);
	return (1);
}

static int		rotate_y(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected || env->mod != _rotate)
		return (0);
	if (!more_less)
		env->cam->rot_wor[1] -= 1;
	else
		env->cam->rot_wor[1] += 1;
	env->cam->trf_mtx = init_trf_mtx(env->cam->rot_wor, env->cam->pos_wor);
	return (1);
}

static int		rotate_z(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected || env->mod != _rotate)
		return (0);
	if (more_less)
		env->cam->rot_wor[2] -= 1;
	else
		env->cam->rot_wor[2] += 1;
	env->cam->trf_mtx = init_trf_mtx(env->cam->rot_wor, env->cam->pos_wor);
	return (1);
}

int				rotate_camera(t_env *env, int axis, int more_less)
{
	t_mov		mov[3];

	mov[0] = rotate_x;
	mov[1] = rotate_y;
	mov[2] = rotate_z;
	mov[axis](env, axis, more_less);
	return (1);
}
