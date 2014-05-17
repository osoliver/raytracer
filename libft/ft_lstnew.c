/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:51:40 by gmange            #+#    #+#             */
/*   Updated: 2014/01/23 12:43:22 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	if (!(lst = (t_list*)ft_memalloc(sizeof(*lst))))
		return (NULL);
	if (content)
	{
		lst->content_size = content_size;
		if (!(lst->content = ft_memalloc(content_size)))
			return (NULL);
		lst->content = ft_memcpy(lst->content, content, content_size);
	}
	else
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	lst->next = NULL;
	return (lst);
}
