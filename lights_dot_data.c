/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_dot_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:34:52 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 15:34:53 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	apply_color(float (*v1)[4], float *v2)
{
	(*v1)[0] = v2[0];
	(*v1)[1] = v2[1] * AMBIENT;
	(*v1)[2] = v2[2] * AMBIENT;
	(*v1)[3] = v2[3] * AMBIENT;
}

void	checker_pos(int (*c)[3], t_dot *dot)
{
	(*c)[0] = dot->pos_cam[0] / CHK_SZE;
	if (dot->pos_cam[0] < 0)
		(*c)[0]++;
	(*c)[1] = dot->pos_cam[1] / CHK_SZE;
	if (dot->pos_cam[1] < 0)
		(*c)[1]++;
	(*c)[2] = dot->pos_cam[2] / CHK_SZE;
	if (dot->pos_cam[2] < 0)
		(*c)[2]++;
}

void	get_color(t_dot *dot)
{
	int		i;
	int		c[3];

	i = 0;
	if (dot->O_OPC == 18)
	{
		checker_pos(&c, dot);
		if (!((int)c[2] % 2))
		{
			if (!(((int)c[0] + (int)c[1]) % 2))
				apply_color(&dot->px_color, dot->O_COLOR);
			else
				apply_color(&dot->px_color, dot->obj->color2);
		}
		else
		{
			if (!(((int)c[0] + (int)c[1]) % 2))
				apply_color(&dot->px_color, dot->obj->color2);
			else
				apply_color(&dot->px_color, dot->O_COLOR);
		}
	}
	else
		apply_color(&dot->px_color, dot->O_COLOR);
}

void	get_dot_datas(t_dot *dot, float src[DIM])
{
	static void	(*f[])(t_dot *dot) =

	{
	normal_sphere, normal_plane, normal_plane, normal_cylinder, normal_cone,
	NULL
	};
	dot->pos_cam[0] = src[0] + dot->dst * dot->rdir[0];
	dot->pos_cam[1] = src[1] + dot->dst * dot->rdir[1];
	dot->pos_cam[2] = src[2] + dot->dst * dot->rdir[2];
	f[dot->obj->opc - MOD](dot);
	dot->pos_cam[0] += dot->normal[0] * 0.0001;
	dot->pos_cam[1] += dot->normal[1] * 0.0001;
	dot->pos_cam[2] += dot->normal[2] * 0.0001;
	get_color(dot);
	if (dot->obj->texture)
		get_dot_texture(dot);
}
