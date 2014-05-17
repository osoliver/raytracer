/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 14:11:48 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/18 14:28:30 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "edit.h"

t_cam		*copy_cam(t_cam *src)
{
	t_cam	*dst;
	int		i;

	i = 0;
	dst = (t_cam *)ft_memalloc(sizeof(t_cam));
	dst->opc = src->opc;
	while (i < DIM)
	{
		dst->pos_wor[i] = src->pos_wor[i];
		dst->pos_cam[i] = src->pos_cam[i];
		dst->rot_wor[i] = src->rot_wor[i];
		dst->rdir[i] = src->rdir[i];
		++i;
	}
	dst->trf_mtx = init_trf_mtx(src->rot_wor, src->pos_wor);
	return (dst);
}
