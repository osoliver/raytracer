/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:51:59 by gmange            #+#    #+#             */
/*   Updated: 2014/03/05 20:45:15 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_exit.h"
#include "rt.h"

/*
** how to merge these two following functions?
** first: merge their struct where data is registered
** then anticipate to include other forms
*/

int				file_to_env(t_env *env)
{
	int		(*f[3])(t_env *e, int o);
	int		opc;
	int		*tab[2];

	tab[0] = &opc;
	tab[1] = NULL;
	f[0] = file_to_cam;
	f[1] = file_to_obj;
	f[2] = file_to_light;
	opc = -1;
	while (line_to_par_int(env, tab, get_opcode) == EXIT_SUCCESS && opc >= 0)
	{
		if (f[opc / MOD](env, opc) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	if (opc == -2)
		return (EXIT_FAILURE);
	if (!OBJ)
		return (END_PUT("no object where found in file", NULL));
	if (!CAM && (CAM = (t_cam*)ft_memalloc(sizeof(t_cam)))
		&& !(CAM->trf_mtx = init_trf_mtx(CAM->rot_wor, CAM->pos_wor)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
