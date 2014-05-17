/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 12:17:13 by gmange            #+#    #+#             */
/*   Updated: 2014/03/05 20:37:29 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"

void			lst_obj_del(t_obj *obj)
{
	t_obj	*tmp;

	while ((tmp = obj))
	{
		obj = O_NXT;
		ft_memdel((void**)&tmp);
	}
}

void			lst_cam_del(t_cam *cam)
{
	t_cam	*tmp;
	int		i;

	tmp = cam;
	while ((cam = tmp))
	{
		tmp = C_NXT;
		i = 0;
		if (TRF_MTX)
		{
			while (i < DIM + 1)
				ft_memdel((void**)&TRF_MTX[i++]);
			ft_memdel((void**)&TRF_MTX);
		}
		ft_memdel((void**)&cam);
	}
}

void			lst_light_del(t_light *light)
{
	t_light	*tmp;

	while ((tmp = light))
	{
		light = L_NXT;
		ft_memdel((void**)&tmp);
	}
}
