/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 09:55:42 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/26 15:11:14 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

int			movement_selection(t_env *env, int axis, int more_less)
{
	t_mov	mov[5];

	mov[0] = move_camera;
	mov[1] = move_object;
	mov[2] = scale;
	mov[3] = rotate_object;
	mov[4] = object_color;
	mov[env->mod](env, axis, more_less);
	return (1);
}
