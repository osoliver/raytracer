/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:22:35 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 15:22:39 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

void		normal_sphere(t_dot *dot)
{
	float	len;

	dot->normal[0] = dot->pos_cam[0] - dot->obj->pos_cam[0];
	dot->normal[1] = dot->pos_cam[1] - dot->obj->pos_cam[1];
	dot->normal[2] = dot->pos_cam[2] - dot->obj->pos_cam[2];
	len = sqrtf(dotproduct(dot->normal, dot->normal));
	dot->normal[0] /= len;
	dot->normal[1] /= len;
	dot->normal[2] /= len;
}

void		normal_plane(t_dot *dot)
{
	float	len;

	dot->normal[0] = dot->obj->rot_cam[0];
	dot->normal[1] = dot->obj->rot_cam[1];
	dot->normal[2] = dot->obj->rot_cam[2];
	len = sqrtf(dotproduct(dot->normal, dot->normal));
	dot->normal[0] /= len;
	dot->normal[1] /= len;
	dot->normal[2] /= len;
}

static void	finish_normal_cylinder(t_dot *dot)
{
	int		i;
	float	len;
	float	pos_cam1[DIM];

	ft_bzero(pos_cam1, sizeof(pos_cam1));
	i = -1;
	while (++i < DIM)
		pos_cam1[i] = dotproduct(dot->pos_cam, dot->obj->rot_mtx[i]);
	i = -1;
	while (++i < DIM)
		dot->pos_cam[i] = pos_cam1[i];
	i = -1;
	while (++i < DIM)
		pos_cam1[i] = dotproduct(dot->normal, dot->obj->rot_mtx[i]);
	i = -1;
	while (++i < DIM)
		dot->normal[i] = pos_cam1[i];
	len = sqrtf(dotproduct(dot->normal, dot->normal));
	dot->normal[0] /= len;
	dot->normal[1] /= len;
	dot->normal[2] /= len;
}

void		normal_cylinder(t_dot *dot)
{
	dot->pos_cam[0] = 0 + dot->dst * dot->rot_ray[0];
	dot->pos_cam[1] = 0 + dot->dst * dot->rot_ray[1];
	dot->pos_cam[2] = 0 + dot->dst * dot->rot_ray[2];
	dot->normal[0] = dot->pos_cam[0] - dot->obj->pos_cam[0];
	dot->normal[1] = 0;
	dot->normal[2] = dot->pos_cam[2] - dot->obj->pos_cam[2];
	finish_normal_cylinder(dot);
}

void		normal_cone(t_dot *dot)
{
	float	len;

	dot->pos_cam[0] = 0 + dot->dst * dot->rot_ray[0];
	dot->pos_cam[1] = 0 + dot->dst * dot->rot_ray[1];
	dot->pos_cam[2] = 0 + dot->dst * dot->rot_ray[2];
	dot->normal[0] = dot->pos_cam[0] - dot->obj->pos_cam[0];
	dot->normal[1] = (dot->pos_cam[0] - dot->obj->pos_cam[0])
					* tan(sqrt(M_PI * dot->obj->par1) / 180);
	dot->normal[2] = dot->pos_cam[2] - dot->obj->pos_cam[2];
	len = sqrt(powf(dot->normal[0], 2) + powf(dot->normal[2], 2));
	dot->normal[0] /= len;
	dot->normal[1] /= len;
	dot->normal[2] /= len;
}
