/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 13:34:01 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 20:04:46 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "edit.h"

static char		*g_but_mode[5] =
{
	"camera.xpm",
	"grab.xpm",
	"scale.xpm",
	"rotate.xpm",
	"color.xpm"
};

static char		*g_but_axis[3] =
{
	"x.xpm",
	"y,xpm",
	"z.zpm"
};

static char		*g_but_more_less[2] =
{
	"minus.xpm",
	"plus.xpm"
};

static char		*g_done[2] =
{
	"exit.xpm",
	"render.xpm"
};

t_buts			*init_button(t_list *ptr, char *name)
{
	t_list		*tmp;
	t_buts		*but;
	t_buts		*tmpb;

	tmp = ptr;
	if (ptr)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmpb = (t_buts *)(tmp->content);
	}
	but = (t_buts *)ft_memalloc(sizeof(t_buts));
	but->name = ft_strjoin("panel/", name);
	return (but);
}

static t_list	*set_buttons(t_list *ptr)
{
	t_list		*tmp;

	tmp = ptr;
	tmp = set_mode_buttons(&tmp);
	tmp = set_axis_buttons(&tmp);
	tmp = set_more_less_buttons(&tmp);
	tmp = set_done_buttons(&tmp);
	return (ptr);
}

static t_list	*add_to_list(t_list *ptr, char *name)
{
	t_list		*new;
	t_buts		*but;

	but = init_button(ptr, name);
	new = ft_lstnew(but, sizeof(t_buts));
	ft_lstaddtoend(&ptr, new);
	return (ptr);
}

t_list			*set_panel(void)
{
	t_list		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	while (i < 5)
		ptr = add_to_list(ptr, g_but_mode[i++]);
	while (i < 8)
		ptr = add_to_list(ptr, g_but_axis[i++ - 5]);
	while (i < 16)
		ptr = add_to_list(ptr, g_but_more_less[i++ % 2]);
	while (i < 18)
		ptr = add_to_list(ptr, g_done[i++ % 2]);
	if (ptr)
		ptr = set_buttons(ptr);
	return (ptr);
}
