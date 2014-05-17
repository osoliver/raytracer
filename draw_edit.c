/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 22:03:34 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:15:14 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "libft.h"
#include "rt.h"
#include "edit.h"
#include "ft_exit.h"

static void	init_dot(t_env *env)
{
	D_RDIR[0] = EPIXCAM_X;
	D_RDIR[1] = EPIXCAM_Y;
	D_RDIR[2] = -1.0;
	normalize_ray(&D_RDIR);
	D_OBJ = OBJ;
	D_CAM = CAM;
	D_LIGHT = LIGHT;
	D_DST = -1.0;
}

int			draw_edit(t_env *env)
{
	unsigned int	*ptr;
	unsigned int	i;
	float			l[DIM];

	i = 0;
	ft_bzero(l, DIM);
	ptr = (unsigned int*)IMG_ADR;
	if (!(DOT = (t_dot*)ft_memalloc(sizeof(t_dot))))
		return (EXIT_FAILURE);
	D_IDX = 0;
	while (D_IDX < ((MHGT * I_WDT)))
	{
		if ((i++ % MWDT) >= I_WDT)
			continue ;
		init_dot(env);
		trace_ray(env, DOT, &l, env->C_POS_CAM);
		if (D_DST >= 0)
			ptr[I_BPP] = GET_RGB(MIX_PTR_COLOR);
		else
			ptr[I_BPP] = GET_RGB(BCKGRND_COLOR);
		++D_IDX;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (EXIT_SUCCESS);
}
