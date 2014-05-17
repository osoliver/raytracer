/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:21:23 by gmange            #+#    #+#             */
/*   Updated: 2013/12/07 15:33:40 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewtoend(t_list **lst, void const *content, size_t content_size)
{
	t_list		*ptr;

	if (!(ptr = ft_lstnew(content, content_size)))
		return (NULL);
	ft_lstaddtoend(lst, ptr);
	return (ptr);
}
