/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:34:23 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:20:20 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "edit.h"

static int		move_x(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _grab)
		return (0);
	if (!more_less)
		env->selected->pos_wor[0] -= 1;
	else
		env->selected->pos_wor[0] += 1;
	return (1);
}

static int		move_y(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _grab)
		return (0);
	if (more_less)
		env->selected->pos_wor[1] += 1;
	else
		env->selected->pos_wor[1] -= 1;
	return (1);
}

static int		move_z(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _grab)
		return (0);
	if (more_less)
		env->selected->pos_wor[2] -= 1;
	else
		env->selected->pos_wor[2] += 1;
	return (1);
}

int				move_object(t_env *env, int axis, int more_less)
{
	t_mov		mov[3];

	mov[0] = move_x;
	mov[1] = move_y;
	mov[2] = move_z;
	mov[axis](env, axis, more_less);
	return (1);
}
