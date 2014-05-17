/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:28:26 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 20:03:17 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"
#include "edit.h"

static t_obj	*save_link(t_obj *src, t_obj *dst)
{
	int			i;

	i = 0;
	dst->opc = src->opc;
	dst = get_float_tab(dst, src);
	dst->reflexion = src->reflexion;
	dst->refraction = src->refraction;
	dst->specular = src->specular;
	dst->normal = src->normal;
	dst->par1 = src->par1;
	dst->par2 = src->par2;
	while (i < 4)
	{
		dst->selec_color[i] = '\0';
		dst->color[i] = src->color[i];
		++i;
	}
	dst->bump = NULL;
	return (dst);
}

int				copy_env_mods(t_env *env)
{
	t_obj		*tmp;
	t_obj		*cur;

	if (env->selected)
		unselect_object(env);
	env->selected = NULL;
	env->mod = _cam;
	tmp = env->save->obj;
	cur = env->obj;
	env->save->cam = copy_cam(CAM);
	while (tmp)
	{
		tmp = save_link(cur, tmp);
		tmp = tmp->nxt;
		cur = cur->nxt;
	}
	expose_hook(env->save);
	return (0);
}

void			change_mode(t_env *env, int key)
{
	int			i;
	t_mod		mod[4];
	int			tab[4];

	tab[0] = T_G;
	tab[1] = T_S;
	tab[2] = T_R;
	tab[3] = T_C;
	mod[0] = grab_mode;
	mod[1] = scale_mode;
	mod[2] = rotate_mode;
	mod[3] = color_mode;
	i = 0;
	while (key % tab[i])
		++i;
	mod[i](env);
}

int				key_edit_hook(int keycode, t_env *env)
{
	if (keycode == T_ESC)
		return (close_edit_window(env, 0));
	if (keycode == T_ENTER || keycode == T_RETURN)
		copy_env_mods(env);
	if (keycode == T_G || keycode == T_S || keycode == T_R || keycode == T_C)
		change_mode(env, keycode);
	if (keycode == T_TAB)
		next_object(env);
	expose_edit_hook(env);
	return (1);
}
