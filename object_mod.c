/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 23:05:58 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 17:48:34 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"
#include "libft.h"

t_obj		*get_float_tab(t_obj *dst, t_obj *src)
{
	int		i;

	i = 0;
	while (i < DIM)
	{
		dst->pos_wor[i] = src->pos_wor[i];
		dst->rot_wor[i] = src->rot_wor[i];
		dst->pos_cam[i] = src->pos_cam[i];
		dst->rot_cam[i] = src->rot_cam[i];
		dst->pos_dot[i] = src->pos_dot[i];
		dst->rot_dot[i] = src->rot_dot[i];
		++i;
	}
	return (dst);
}

t_obj		*get_link(t_obj *src, int flag)
{
	t_obj	*dst;
	int		i;

	i = 0;
	flag = 0;
	dst = (t_obj *)ft_memalloc(sizeof(t_obj));
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

t_obj		*copy_object(t_obj *src, int flag)
{
	t_obj	*s_tmp;
	t_obj	*d_tmp;
	t_obj	*new;
	t_obj	*ptr;

	flag = 0;
	ptr = NULL;
	if (!ptr)
		ptr = get_link(src, flag);
	d_tmp = ptr;
	s_tmp = src;
	while (s_tmp && s_tmp->nxt)
	{
		s_tmp = s_tmp->nxt;
		new = get_link(s_tmp, flag);
		d_tmp->nxt = new;
		d_tmp = d_tmp->nxt;
	}
	d_tmp = get_link(s_tmp, flag);
	d_tmp->nxt = NULL;
	return (ptr);
}

t_obj		*modify_object(t_obj *obj)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		obj->selec_color[i] = obj->color[i];
		++i;
	}
	obj->color[0] = 0;
	obj->color[1] = 255;
	obj->color[2] = 0;
	obj->color[3] = 0;
	return (obj);
}
