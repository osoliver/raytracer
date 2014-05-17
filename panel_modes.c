/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 19:56:07 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 18:48:12 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

int			mode_buttons(int x, int y)
{
	if (x >= I_WDT + 14 && x <= I_WDT + 186)
	{
		if (y >= 20 && y <= 180)
			return (1);
	}
	return (0);
}

int			axis_buttons(int x, int y)
{
	if (x >= I_WDT + 27 && x <= I_WDT + 175)
	{
		if (y >= 200 && y <= 230)
			return (1);
	}
	return (0);
}

int			more_less_buttons(int x, int y)
{
	if (x >= I_WDT + 30 && x <= I_WDT + 170)
	{
		if (y >= 270 && y <= 475)
			return (1);
	}
	return (0);
}

int			done_buttons(int x, int y)
{
	if (x >= I_WDT + 14 && x <= I_WDT + 190)
	{
		if (y >= 530 && y <= 570)
			return (1);
	}
	return (0);
}

int			ref_modification(t_env *env, int more_less)
{
	if (more_less == 10 && env->save->ref_lvl)
		env->save->ref_lvl--;
	else if (more_less == 11 && env->save->ref_lvl < 20)
		env->save->ref_lvl++;
	if (more_less == 13 && env->selected && env->selected->reflexion < 1)
		env->selected->reflexion += 0.1;
	else if (more_less == 12 && env->selected && env->selected->reflexion)
		env->selected->reflexion -= 0.1;
	if (more_less == 15 && env->selected && env->selected->refraction < 5)
		env->selected->refraction += 0.5;
	else if (more_less == 14 && env->selected && env->selected->refraction)
		env->selected->refraction -= 0.5;
	return (1);
}
