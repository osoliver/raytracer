/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:08:22 by gmange            #+#    #+#             */
/*   Updated: 2013/12/06 17:41:46 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddnew(t_list **lst, void const *content, size_t content_size)
{
	t_list		*ptr;

	if (!(ptr = ft_lstnew(content, content_size)))
		return (NULL);
	ft_lstadd(lst, ptr);
	return (ptr);
}
