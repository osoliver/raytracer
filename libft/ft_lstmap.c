/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:57:54 by gmange            #+#    #+#             */
/*   Updated: 2013/12/02 17:01:56 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** it seem I should apply f to lst first,
** and only then ft_lstnew(lst->content, lst->content_size)
** really? what is the meaning of it?
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	if (!(new = f(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	tmp = new;
	while ((lst = lst->next))
	{
		if (!(tmp->next = f(ft_lstnew(lst->content, lst->content_size))))
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
