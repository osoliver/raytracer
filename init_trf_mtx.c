/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_trf_mtx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osoliver <osoliver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 13:52:59 by osoliver          #+#    #+#             */
/*   Updated: 2014/03/05 13:53:00 by osoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <math.h>
#include "matrices.h"
#include "rt.h"

static t_maths	*init_maths_values(float x, float y, float z)
{
	t_maths	*maths;
	float	xrad;
	float	yrad;
	float	zrad;

	if (!(maths = (t_maths*)ft_memalloc(sizeof(t_maths))))
		return (NULL);
	xrad = (-x * M_PI) / 180.0;
	yrad = (y * M_PI) / 180.0;
	zrad = (-z * M_PI) / 180.0;
	COSX = cos(xrad);
	SINX = sin(xrad);
	COSY = cos(yrad);
	SINY = sin(yrad);
	COSZ = cos(zrad);
	SINZ = sin(zrad);
	PROD1 = COSX * SINY;
	PROD2 = SINX * SINY;
	return (maths);
}

static float	**init_rot_mtx(t_maths *maths)
{
	float	**t_matrix;
	int		i;

	i = 4;
	if (!(t_matrix = (float**)ft_memalloc(sizeof(float*) * 4)))
		return (NULL);
	while (i-- > 0)
	{
		if (!(t_matrix[i] = (float*)ft_memalloc(sizeof(float) * 4)))
			return (NULL);
	}
	AA = COSY * COSZ;
	BB = COSY * -SINZ;
	CC = SINY;
	DD = PROD2 * COSZ + COSX * SINZ;
	EE = -PROD2 * SINZ + COSX * COSZ;
	FF = -SINX * COSY;
	GG = -PROD1 * COSZ + SINX * SINZ;
	HH = -PROD1 * -SINZ + SINX * COSZ;
	II = COSX * COSY;
	return (t_matrix);
}

float			**init_trf_mtx(float *rot_wor, float *pos_wor)
{
	float		**trf_mtx;
	t_maths		*maths;

	if (!(maths = init_maths_values(rot_wor[0], rot_wor[1], rot_wor[2])))
		return (NULL);
	if (!(trf_mtx = init_rot_mtx(maths)))
		return (NULL);
	trf_mtx[0][3] = -pos_wor[0];
	trf_mtx[1][3] = -pos_wor[1];
	trf_mtx[2][3] = -pos_wor[2];
	trf_mtx[3][3] = 1;
	return (trf_mtx);
}

float			**init_obj_rot_mtx(float *rot_obj)
{
	float		**rot_mtx;
	t_maths		*maths;
	int			i;

	if (!(maths = init_maths_values(rot_obj[0], rot_obj[1], rot_obj[2])))
		return (NULL);
	if (!(rot_mtx = init_rot_mtx(maths)))
		return (NULL);
	i = 0;
	while (i < 3)
	{
		rot_mtx[i][3] = 0;
		++i;
	}
	rot_mtx[3][3] = 1;
	return (rot_mtx);
}

void			rotate_obj(t_obj *obj, t_dot *dot, float (*l)[DIM])
{
	int		i;

	i = 0;
	while (i < DIM)
	{
		dot->rot_ray[i] = dotproduct(dot->rdir, obj->rot_mtx[i]);
		dot->rot_l[i] = dotproduct((*l), obj->rot_mtx[i]);
		++i;
	}
	normalize_ray(&dot->rot_ray);
}
