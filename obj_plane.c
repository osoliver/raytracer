/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 11:22:02 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/07 11:22:03 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"

float	dst_plane(t_obj *obj, t_dot *dot, float (*l)[DIM])
{
	float	pt[DIM];
	int		i;

	i = -1;
	while (++i < DIM)
		pt[i] = -(*l)[i];
	if (fabs(dotproduct(O_ROT_CAM, dot->rdir)) == ERROR_F)
		return (-1);
	return (dotproduct(O_ROT_CAM, pt) / dotproduct(O_ROT_CAM, dot->rdir));
}
