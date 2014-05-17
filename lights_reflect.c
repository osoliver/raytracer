/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_reflect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:32:48 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 15:32:50 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	get_reflect(t_env *env, t_dot *dot, int ref_lvl, int thread_number)
{
	t_dot		newdot;
	float		x;
	float		l[DIM];
	int			i;

	i = -1;
	ft_bzero(l, sizeof(l));
	newdot.thread_number = thread_number;
	newdot.obj = OBJ;
	newdot.cam = CAM;
	newdot.light = LIGHT;
	newdot.dst = -1.0;
	x = (dotproduct(dot->normal, dot->rdir));
	newdot.rdir[0] = dot->rdir[0] - (2.0 * dot->normal[0] * x);
	newdot.rdir[1] = dot->rdir[1] - (2.0 * dot->normal[1] * x);
	newdot.rdir[2] = dot->rdir[2] - (2.0 * dot->normal[2] * x);
	normalize_ray(&newdot.rdir);
	trace_ray(env, &newdot, &l, dot->pos_cam);
	while (ref_lvl > 1 && newdot.obj->reflexion > 0)
		get_reflect(env, &newdot, --ref_lvl, thread_number);
	if (newdot.obj->refraction > 0)
		get_refract(env, &newdot, 1, env->ref_lvl);
	get_light(env, &newdot);
	while (++i < 4)
		D_C[i] = (D_C[i] + ND_C[i] * ref_lvl * D_OBJ_R) / (ref_lvl + 1);
}
