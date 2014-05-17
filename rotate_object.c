/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:03:58 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:22:34 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "edit.h"

static int		rotate_x(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _rotate)
		return (0);
	if (more_less)
		env->selected->rot_wor[0] += 1;
	else
		env->selected->rot_wor[0] -= 1;
	return (1);
}

static int		rotate_y(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _rotate)
		return (0);
	if (!more_less)
		env->selected->rot_wor[0] -= 1;
	else
		env->selected->rot_wor[0] += 1;
	return (1);
}

static int		rotate_z(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _rotate)
		return (0);
	if (more_less)
		env->selected->rot_wor[0] -= 1;
	else
		env->selected->rot_wor[0] += 1;
	return (1);
}

int				rotate_object(t_env *env, int axis, int more_less)
{
	t_mov		mov[3];

	mov[0] = rotate_y;
	mov[1] = rotate_x;
	mov[2] = rotate_z;
	if (!env->selected)
		rotate_camera(env, axis, more_less);
	mov[axis](env, axis, more_less);
	return (1);
}
