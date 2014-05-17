/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_init_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:52:14 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 14:52:16 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void	mt_init_dot(t_env *env, int thread_number, float x, float y)
{
	DOTX(thread_number)->rdir[0] = MT_PIX_CAM_X(thread_number, x);
	DOTX(thread_number)->rdir[1] = MT_PIX_CAM_Y(thread_number, y);
	DOTX(thread_number)->rdir[2] = -1.0;
	normalize_ray(&DOTX(thread_number)->rdir);
	D_OBJ_MT(thread_number) = OBJ;
	DOTX(thread_number)->cam = CAM;
	DOTX(thread_number)->light = LIGHT;
	DOTX(thread_number)->dst = -1.0;
	DOTX(thread_number)->nxt = DOTX(thread_number);
}

void	init_idx_n_ptr(unsigned int **ptr, t_env *env, int thrd, int i)
{
	*ptr = (unsigned int*)IMG_ADR + (unsigned int)i;
	DOTX(thrd)->idx = i;
}
