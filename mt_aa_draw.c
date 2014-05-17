/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_aa_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:46:19 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 14:46:20 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_exit.h"
#include "rt.h"

static void		init_mt_var(float xy[2], int flag)
{
	if (!flag)
	{
		xy[1] = 0.25;
		xy[0] = 0.25;
	}
	if (flag == 1)
		xy[1] += 0.25;
	if (flag == 2)
	{
		xy[1] = 0.25;
		xy[0] += 0.25;
	}
}

static void		color_pixel(unsigned int *ptr, t_env *env, float c[4])
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (c[i] > 255)
			(c[i] = 255);
	}
	*ptr = GET_RGB(AA_PTR_COLOR);
}

static void		fillin_colors(t_env *env, float xy[2], float *c, int trd_num)
{
	int		i;
	float	l[DIM];

	i = -1;
	mt_init_dot(env, trd_num, xy[0], xy[1]);
	trace_ray(env, DOTX(trd_num), &l, env->C_POS_CAM);
	if (DOTX(trd_num)->dst >= 0.001)
	{
		if (DOTX(trd_num)->obj->refraction > 0)
			get_refract(env, DOTX(trd_num), 1, env->ref_lvl);
		if (DOTX(trd_num)->obj->reflexion > 0)
			get_reflect(env, DOTX(trd_num), env->ref_lvl, trd_num);
		get_light(env, DOTX(trd_num));
		while (++i < 4)
			c[i] += (float)((float)DOTX(trd_num)->px_color[i] / 9.0);
	}
	else
	{
		while (++i < 4)
			c[i] += (float)((float)GET_RGB(BCKGRND_COLOR) / 9.0);
	}
}

int				trace_ray(t_env *env, t_dot *dot, float (*l)[DIM], float v[DIM])
{
	t_obj			*obj;
	float			dst_tmp;
	static float	(*f[])(t_obj *obj, t_dot *dot, float (*l)[DIM]) =

	{dst_sphere, dst_plane, dst_plane, dst_cylinder, dst_cone, NULL};
	obj = OBJ;
	while (obj)
	{
		(*l)[0] = v[0] - O_POS_CAM[0];
		(*l)[1] = v[1] - O_POS_CAM[1];
		(*l)[2] = v[2] - O_POS_CAM[2];
		dst_tmp = f[O_OPC - MOD](obj, dot, l);
		if (dst_tmp >= 0.001 && (dst_tmp <= dot->dst || dot->dst < 0))
		{
			dot->obj = obj;
			dot->dst = dst_tmp;
		}
		obj = O_NXT;
	}
	if (dot->dst >= 0.001)
		get_dot_datas(dot, v);
	return (EXIT_SUCCESS);
}

void			mt_draw_antialiasing(t_env *env, unsigned int *ptr, int trd_num)
{
	float			xy[2];
	float			c[4];

	init_mt_var(xy, 0);
	ft_bzero(c, sizeof(c));
	while (xy[0] <= 0.75)
	{
		while (xy[1] <= 0.75)
		{
			fillin_colors(env, xy, c, trd_num);
			init_mt_var(xy, 1);
		}
		init_mt_var(xy, 2);
	}
	color_pixel(ptr, env, c);
}
