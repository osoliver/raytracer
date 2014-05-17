/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osoliver <osoliver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 19:22:26 by osoliver          #+#    #+#             */
/*   Updated: 2014/03/27 18:15:27 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

int				ray_throught_obj(t_dot *dot, t_obj *obj)
{
	float			l[DIM];
	float			len;
	static float	(*f[])(t_obj *obj, t_dot *dot, float (*l)[DIM]) =

	{
	dst_sphere, dst_plane, dst_plane, dst_cylinder, dst_cone, NULL
	};
	ft_bzero(l, sizeof(l));
	substract_vector(dot->pos_cam, O_POS_CAM, &l);
	len = f[obj->opc - MOD](obj, dot, &l);
	if (len > 0.00001)
		len = normalize_len(len, dot->rdir);
	if (D_OBJ_OPC == 19 && dot->obj == obj)
		return (0);
	if (len < dot->dst && len > 0.00001)
	{
		dot->intensity = 0.0;
		return (1);
	}
	return (0);
}

void			ray_to_light(t_env *env, t_dot *dot, t_light *light)
{
	t_obj			*obj;

	obj = OBJ;
	substract_vector(light->pos_cam, dot->pos_cam, &dot->rdir);
	dot->dst = normalize_ray(&dot->rdir);
	if (dotproduct(dot->rdir, dot->normal) > 0.0)
		dot->intensity = dotproduct(dot->rdir, dot->normal);
	if (dot->intensity > 0.0)
	{
		while (obj)
		{
			if (ray_throught_obj(dot, obj))
				break ;
			obj = obj->nxt;
		}
	}
}

float			get_specular(t_dot *dot)
{
	float	ray[3];
	float	ray2[3];
	float	len;

	len = 0;
	ft_bzero(ray, sizeof(ray));
	ft_bzero(ray2, sizeof(ray2));
	ray[0] = dot->pos_cam[0];
	ray[1] = dot->pos_cam[1];
	ray[2] = dot->pos_cam[2];
	normalize_ray(&ray);
	ray2[0] = dot->rdir[0] - 2.0 * dot->intensity * dot->normal[0];
	ray2[1] = dot->rdir[1] - 2.0 * dot->intensity * dot->normal[1];
	ray2[2] = dot->rdir[2] - 2.0 * dot->intensity * dot->normal[2];
	normalize_ray(&ray2);
	len = dotproduct(ray2, ray);
	return (len);
}

void			get_light(t_env *env, t_dot *dot)
{
	int		i;
	float	specular;
	int		value;

	while (dot->light)
	{
		dot->intensity = 0.0;
		ray_to_light(env, dot, dot->light);
		specular = get_specular(dot);
		if (dot->intensity > 0.00001)
		{
			i = -1;
			while (++i < 4)
			{
				value = ((powf(specular, 20) * D_O_SPC) + (dot->intensity *
((float)dot->light->color[i] / 255.0) * (dot->px_color[i] * (1.0 / AMBIENT))))
				* (10 / dot->dst);
				if ((int)dot->px_color[i] + value < 255)
					dot->px_color[i] += value;
				else
					dot->px_color[i] = 255;
			}
		}
		dot->light = dot->light->nxt;
	}
}
