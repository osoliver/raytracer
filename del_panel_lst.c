/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_panel_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 17:02:42 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/26 17:26:48 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

void		del(void *link, size_t but_size)
{
	ft_strdel(&(((t_buts *)link)->name));
	ft_bzero(link, but_size);
	ft_memdel((void **)&link);
}
