/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_to_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 15:10:55 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 15:10:57 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "ft_exit.h"

static int		create_obj_rot_mtx(t_obj *obj)
{
	if ((obj->rot_mtx = init_obj_rot_mtx(obj->tmp_rot)) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int		obj_world_to_cam(t_env *env, t_cam *cam, t_obj *obj)
{
	int		i;

	i = 0;
	while (i < DIM)
	{
		O_POS_CAM[i] = DOTPROD(O_POS_WOR, TRF_MTX[i])
						+ 1 * DOTPROD(-C_POS_WOR, TRF_MTX[i]);
		O_ROT_CAM[i] = DOTPROD(O_ROT_WOR, TRF_MTX[i]);
		obj->tmp_rot[i] = obj->rot_wor[i] - env->cam->rot_wor[i];
		i++;
	}
	if (create_obj_rot_mtx(obj) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				world_to_cam(t_env *env, t_cam *cam)
{
	t_obj	*obj;
	t_light	*light;
	int		i;

	obj = OBJ;
	light = LIGHT;
	while (obj)
	{
		if (obj_world_to_cam(env, cam, obj) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		obj = O_NXT;
	}
	while (light)
	{
		i = 0;
		while (i < DIM)
		{
			L_POS_CAM[i] = DOTPROD(L_POS_WOR, TRF_MTX[i])
							+ 1 * DOTPROD(-C_POS_WOR, TRF_MTX[i]);
			L_ROT_CAM[i] = DOTPROD(L_ROT_WOR, TRF_MTX[i]);
			i++;
		}
		light = L_NXT;
	}
	return (EXIT_SUCCESS);
}
