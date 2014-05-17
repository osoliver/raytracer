/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:38:23 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/25 21:52:34 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "edit.h"

int		scale(t_env *env, int axis, int more_less)
{
	axis = 0;
	if (env->selected == NULL || env->mod != _scale)
		return (0);
	if (more_less)
		env->selected->par1 += 0.5;
	else if (!more_less)
		env->selected->par1 -= 0.5;
	return (1);
}
