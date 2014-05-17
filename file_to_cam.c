/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 20:36:18 by gmange            #+#    #+#             */
/*   Updated: 2014/03/05 21:20:20 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_exit.h"
#include "rt.h"

static int		file_to_cam_sub(t_env *env, t_cam *cam)
{
	float	*param[7];

	param[0] = &C_POS_WOR[0];
	param[1] = &C_POS_WOR[1];
	param[2] = &C_POS_WOR[2];
	param[3] = &C_ROT_WOR[0];
	param[4] = &C_ROT_WOR[1];
	param[5] = &C_ROT_WOR[2];
	param[6] = NULL;
	return (line_to_par_float(env, param));
}

int				file_to_cam(t_env *env, int opc)
{
	t_cam	*cam;

	if (!(cam = (t_cam*)ft_memalloc(sizeof(t_cam))))
		return (END_PUT("malloc error", NULL));
	C_OPC = opc;
	C_NXT = CAM;
	CAM = cam;
	if (file_to_cam_sub(env, cam) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (!(TRF_MTX = init_trf_mtx(C_ROT_WOR, C_POS_WOR)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
