/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 11:21:12 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/07 11:21:14 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "rt.h"

float	dst_sphere(t_obj *obj, t_dot *dot, float (*l)[DIM])
{
	float	coef[3];
	float	delta;
	float	q[3];

	rotate_obj(obj, dot, l);
	ft_bzero(q, 3);
	ft_bzero(coef, 3);
	coef[0] = dotproduct(dot->rot_ray, dot->rot_ray);
	coef[1] = 2.0 * dotproduct(dot->rot_ray, dot->rot_l);
	coef[2] = dotproduct(dot->rot_l, dot->rot_l) - powf(PAR1, 2);
	if ((delta = powf(coef[1], 2) - 4 * coef[0] * coef[2]) < 0)
		return (-1);
	q[0] = (-coef[1] - sqrtf(delta)) / (2 * coef[0]);
	q[1] = (-coef[1] + sqrtf(delta)) / (2 * coef[0]);
	q[2] = (q[0] <= q[1]) ? q[0] : q[1];
	if (q[0] < 0 && q[1] >= 0)
		q[2] = q[1];
	return (q[2]);
}
