/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_refract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:27:37 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 15:27:39 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static int		check_medium(t_env *env, int thread_number)
{
	t_dot	*tmp;
	t_dot	*cur;

	cur = env->tab_dot[thread_number];
	tmp = env->tab_dot[thread_number];
	while (cur->nxt != env->tab_dot[thread_number])
		cur = cur->nxt;
	while (tmp != cur)
	{
		if (tmp->obj == cur->obj)
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}

static void		init_newdot(t_env *env, t_dot *newdot, int thread_number)
{
	newdot->thread_number = thread_number;
	newdot->obj = OBJ;
	newdot->cam = CAM;
	newdot->light = LIGHT;
	newdot->dst = -1.0;
}

static void		fill_px_color(t_env *env, t_dot *dot, t_dot *newdot,
								float refr_lvl)
{
	int			i;

	get_light(env, newdot);
	i = 0;
	while (i < 4)
	{
		dot->px_color[i] = (float)(dot->px_color[i]
					+ (float)newdot->px_color[i] * refr_lvl) / (refr_lvl + 1);
		i++;
	}
}

static void		calc_new_rdir(float xy[2], float ref_div_med,
								t_dot *newdot, t_dot *dot)
{
	if (xy[0] < 0)
	{
		newdot->rdir[0] = (ref_div_med) * dot->rdir[0]
							+ ((ref_div_med) * xy[0] + xy[1]) * dot->normal[0];
		newdot->rdir[1] = (ref_div_med) * dot->rdir[1]
							+ ((ref_div_med) * xy[0] + xy[1]) * dot->normal[1];
		newdot->rdir[2] = (ref_div_med) * dot->rdir[2]
							+ ((ref_div_med) * xy[0] + xy[1]) * dot->normal[2];
	}
	else
	{
		newdot->rdir[0] = (ref_div_med) * dot->rdir[0]
							+ ((ref_div_med) * xy[0] - xy[1]) * dot->normal[0];
		newdot->rdir[1] = (ref_div_med) * dot->rdir[1]
							+ ((ref_div_med) * xy[0] - xy[1]) * dot->normal[1];
		newdot->rdir[2] = (ref_div_med) * dot->rdir[2]
							+ ((ref_div_med) * xy[0] - xy[1]) * dot->normal[2];
	}
	normalize_ray(&(newdot->rdir));
}

void			get_refract(t_env *env, t_dot *dot, float refr_coef,
							int refr_lvl)
{
	t_dot		*newdot;
	float		xy[2];
	float		l[DIM];
	float		medium;
	int			thread_number;

	thread_number = dot->thread_number;
	newdot = ft_memalloc(sizeof(t_dot));
	init_newdot(env, newdot, thread_number);
	ft_bzero(l, sizeof(l));
	medium = (float)check_medium(env, thread_number);
	dot->nxt = newdot;
	newdot->nxt = dot;
	if (!medium)
		substract_vector(l, dot->normal, &dot->normal);
	medium = dot->obj->refraction;
	xy[0] = -(dotproduct(dot->normal, dot->rdir));
	xy[1] = sqrtf(1.0 - powf(refr_coef / medium, 2) * (1 - powf(xy[0], 2)));
	calc_new_rdir(xy, (refr_coef / medium), newdot, dot);
	trace_ray(env, newdot, &l, dot->pos_cam);
	while (refr_lvl > 1 && newdot->obj->refraction > 0)
		get_refract(env, newdot, medium, --refr_lvl);
	if (newdot->obj->reflexion > 0)
		get_reflect(env, newdot, env->ref_lvl, thread_number);
	fill_px_color(env, dot, newdot, refr_lvl);
}
