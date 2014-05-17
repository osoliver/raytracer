/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 20:43:03 by gmange            #+#    #+#             */
/*   Updated: 2014/03/14 23:27:13 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_exit.h"
#include "rt.h"

static float	**init_par_flt(t_obj *obj)
{
	float	**tab;

	if (!(tab = (float**)ft_memalloc(sizeof(float*) * 15)))
		return (NULL);
	tab[0] = &O_POS_WOR[0];
	tab[1] = &O_POS_WOR[1];
	tab[2] = &O_POS_WOR[2];
	tab[3] = &O_ROT_WOR[0];
	tab[4] = &O_ROT_WOR[1];
	tab[5] = &O_ROT_WOR[2];
	tab[6] = &REFLEXION;
	tab[7] = &REFRACTION;
	tab[8] = &SPECULAR;
	tab[9] = &NORMAL;
	tab[10] = &PAR1;
	tab[11] = &PAR2;
	tab[12] = &O_TEX_WDT;
	tab[13] = &O_TEX_HGT;
	tab[14] = NULL;
	return (tab);
}

static float	**init_par_char(t_obj *obj)
{
	float	**tab;

	if (!(tab = (float**)ft_memalloc(sizeof(float*) * 9)))
		return (NULL);
	tab[0] = &O_COLOR_A;
	tab[1] = &O_COLOR_R;
	tab[2] = &O_COLOR_G;
	tab[3] = &O_COLOR_B;
	tab[4] = &O_COLOR2_A;
	tab[5] = &O_COLOR2_R;
	tab[6] = &O_COLOR2_G;
	tab[7] = &O_COLOR2_B;
	tab[8] = NULL;
	return (tab);
}

int				file_to_obj_sub(t_env *env, t_obj *obj)
{
	float	**par_flt;
	float	**par_char;
	char	**par_str[2];
	int		ret;

	if (!(par_flt = init_par_flt(obj)))
		return (EXIT_FAILURE);
	if (!(par_char = init_par_char(obj)))
		return (EXIT_FAILURE);
	par_str[0] = &O_TEXTURE;
	par_str[1] = NULL;
	if (line_to_par_float(env, par_flt) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (line_to_par_float(env, par_char) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ret = line_to_par_str(env, par_str);
	free(par_char);
	free(par_flt);
	return (ret);
}

int				file_to_obj(t_env *env, int opc)
{
	t_obj	*obj;

	if (!(obj = (t_obj*)ft_memalloc(sizeof(t_obj))))
		return (END_PUT("malloc error", NULL));
	O_OPC = opc;
	O_NXT = OBJ;
	OBJ = obj;
	return (file_to_obj_sub(env, obj));
}
