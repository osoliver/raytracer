/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:30:21 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/19 11:58:26 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "edit.h"

t_light			*edit_light(t_env *env)
{
	t_light		*light;
	int			i;

	i = 0;
	if (!(light = (t_light*)ft_memalloc(sizeof(t_light))))
		return (NULL);
	while (i < 3)
	{
		light->pos_wor[i] = env->cam->pos_wor[i];
		++i;
	}
	i = 0;
	while (i < 3)
	{
		light->rot_wor[i] = env->cam->rot_wor[i];
		++i;
	}
	i = 1;
	light->color[0] = 0;
	while (i < 4)
	{
		light->color[i] = 255;
		++i;
	}
	return (light);
}
