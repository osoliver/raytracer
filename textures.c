/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osoliver <osoliver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 10:37:03 by osoliver          #+#    #+#             */
/*   Updated: 2014/03/27 20:07:04 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <libft.h>
#include <mlx.h>
#include <math.h>

void	crossproduct(float v1[3], float v2[3], float (*v)[3])
{
	(*v)[0] = v1[1] * v2[2] - v1[2] * v2[1];
	(*v)[1] = v1[2] * v2[0] - v1[0] * v2[2];
	(*v)[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void	get_textures(t_env *env)
{
	t_obj	*obj;
	void	*texture;

	obj = OBJ;
	while (obj)
	{
		if (obj->texture)
		{
			obj->t_wdt = (int)O_TEX_WDT;
			obj->t_hgt = (int)O_TEX_HGT;
			texture = mlx_xpm_file_to_image(MLX, obj->texture,
							&obj->t_wdt, &obj->t_hgt);
			obj->ftexture = mlx_get_data_addr(texture, &obj->bpp,
							&obj->szeline, &obj->endian);
		}
		obj = obj->nxt;
	}
}

void	is_plane(float *v, float *u, t_dot *dot)
{
	float	vc[3];
	float	ve[3];

	*u = 0;
	*v = 0;
	vc[0] = dot->obj->rot_cam[1];
	vc[1] = dot->obj->rot_cam[2];
	vc[2] = -dot->obj->rot_cam[0];
	crossproduct(vc, dot->obj->rot_cam, &ve);
	if (*u < 0)
		*u = 0;
	if (*v < 0)
		*v = 0;
}

void	is_not_plane(float *u, float *v, t_dot *dot)
{
	float	phi;
	float	theta;
	float	vn[3];
	float	ve[3];
	float	vc[3];

	vn[0] = 0;
	vn[1] = 1;
	vn[2] = 0;
	ve[0] = sin((dot->obj->rot_cam[1] * M_PI) / 180);
	ve[1] = 0;
	ve[2] = cos((dot->obj->rot_cam[1] * M_PI) / 180);
	normalize_ray(&vn);
	normalize_ray(&ve);
	phi = acosf(-dotproduct(vn, dot->normal));
	*v = dot->O_TEX_HGT * (1 - phi / M_PI);
	theta = (acosf(dotproduct(dot->normal, ve) / sin(phi))) / (2.0 * M_PI);
	crossproduct(vn, ve, &vc);
	if (dotproduct(vc, dot->normal) > 0)
		*u = theta;
	else
		*u = 1 - theta;
}

void	get_dot_texture(t_dot *dot)
{
	float	u;
	float	v;
	char	*pos;

	if (dot->obj->opc == MOD + 1)
		is_plane(&u, &v, dot);
	else
		is_not_plane(&u, &v, dot);
	pos = D_OBJ_TEX + (int)v * D_OBJ_LN + (int)(u * D_OBJ_TWDT) * D_OBJ_BPP / 8;
	dot->px_color[1] = (unsigned char)pos[dot->obj->bpp / 8 - 2] * AMBIENT;
	dot->px_color[2] = (unsigned char)pos[dot->obj->bpp / 8 - 3] * AMBIENT;
	dot->px_color[3] = (unsigned char)pos[dot->obj->bpp / 8 - 4] * AMBIENT;
	dot->px_color[0] = 0;
}
