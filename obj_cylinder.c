/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 11:21:21 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/07 11:21:23 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

static float	finite_cylinder(t_obj *obj, float *res, float *l, float *rdir)
{
	int		flag;

	flag = 2;
	res[3] = l[1] + res[0] * rdir[1];
	res[4] = l[1] + res[1] * rdir[1];
	if (res[3] > 0 && res[3] < obj->par2)
		flag -= 2;
	if (res[4] > 0 && res[3] < obj->par2)
		flag -= 1;
	if (flag == -1)
	{
		res[2] = (res[0] <= res[1]) ? res[0] : res[1];
		if (res[0] < 0 && res[1] >= 0)
			res[2] = res[1];
		return (res[2]);
	}
	if (flag == 1 || flag == 0)
		return (res[flag]);
	return (-1);
}

float			dst_cylinder(t_obj *obj, t_dot *dot, float (*l)[DIM])
{
	float	coef[DIM];
	float	result[4];
	float	delta;

	rotate_obj(obj, dot, l);
	coef[0] = powf(dot->rot_ray[0], 2) + powf(dot->rot_ray[2], 2);
	coef[1] = 2 * dot->rot_l[0] * dot->rot_ray[0] + 2 * dot->rot_l[2]
				* dot->rot_ray[2];
	coef[2] = powf(dot->rot_l[0], 2) + powf(dot->rot_l[2], 2)
				- powf(obj->par1, 2);
	if ((delta = powf(coef[1], 2) - 4 * coef[0] * coef[2]) < 0)
		return (-1);
	result[0] = (-coef[1] - sqrtf(delta)) / (2 * coef[0]);
	result[1] = (-coef[1] + sqrtf(delta)) / (2 * coef[0]);
	if (obj->par2 != 0)
		return (finite_cylinder(obj, result, dot->rot_l, dot->rot_ray));
	result[2] = (result[0] <= result[1]) ? result[0] : result[1];
	if (result[0] < 0 && result[1] >= 0)
		result[2] = result[1];
	return (result[2]);
}
