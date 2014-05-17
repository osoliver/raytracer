/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 11:21:31 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/07 11:21:32 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

float	dst_cone(t_obj *obj, t_dot *dot, float (*l)[DIM])
{
	float	coef[DIM];
	float	delta;
	float	q[3];
	float	angle;

	rotate_obj(obj, dot, l);
	angle = PAR1 * M_PI / 180;
	coef[0] = powf(dot->rot_ray[0], 2) + powf(dot->rot_ray[2], 2)
				- powf(dot->rot_ray[1], 2) * tan(angle);
	coef[1] = 2 * (dot->rot_ray[0] * dot->rot_l[0] + dot->rot_ray[2]
				* dot->rot_l[2] - dot->rot_ray[1] * dot->rot_l[1] * tan(angle));
	coef[2] = powf(dot->rot_l[0], 2) + powf(dot->rot_l[2], 2)
				- powf(dot->rot_l[1], 2) * tan(angle);
	if ((delta = powf(coef[1], 2) - 4 * coef[0] * coef[2]) < 0)
		return (-1);
	q[0] = (-coef[1] - sqrtf(delta)) / (2 * coef[0]);
	q[1] = (-coef[1] + sqrtf(delta)) / (2 * coef[0]);
	q[2] = (q[0] <= q[1]) ? q[0] : q[1];
	if (q[0] < 0 && q[1] >= 0)
		q[2] = q[1];
	return (q[2]);
}
