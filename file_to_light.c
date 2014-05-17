/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 20:44:11 by gmange            #+#    #+#             */
/*   Updated: 2014/03/15 23:19:01 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_exit.h"
#include "rt.h"

static int		file_to_light_sub(t_env *env, t_light *light)
{
	float			*par_flt[7];
	unsigned char	*par_char[5];

	par_flt[0] = &L_POS_WOR[0];
	par_flt[1] = &L_POS_WOR[1];
	par_flt[2] = &L_POS_WOR[2];
	par_flt[3] = &L_ROT_WOR[0];
	par_flt[4] = &L_ROT_WOR[1];
	par_flt[5] = &L_ROT_WOR[2];
	par_flt[6] = NULL;
	par_char[0] = &L_COLOR_A;
	par_char[1] = &L_COLOR_R;
	par_char[2] = &L_COLOR_G;
	par_char[3] = &L_COLOR_B;
	par_char[4] = NULL;
	if (line_to_par_float(env, par_flt) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (line_to_par_char(env, par_char));
}

int				file_to_light(t_env *env, int opc)
{
	t_light		*light;

	if (!(light = (t_light*)ft_memalloc(sizeof(t_light))))
		return (END_PUT("malloc error", NULL));
	L_OPC = opc;
	L_NXT = LIGHT;
	LIGHT = light;
	return (file_to_light_sub(env, light));
}
