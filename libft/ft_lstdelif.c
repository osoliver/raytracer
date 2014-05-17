/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 08:50:32 by gmange            #+#    #+#             */
/*   Updated: 2013/12/08 08:55:57 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **alst, size_t size, void (*del)(void *, size_t))
{
	t_list			*ptr;
	t_list			*tmp;

	tmp = *alst;
	while (tmp)
	{
		if (tmp->content_size == size)
		{
			ptr = tmp->next;
			if (tmp == *alst)
				ft_lstdelone(alst, del);
			else
				ft_lstdelone(&tmp, del);
			tmp = ptr;
		}
		else
			tmp = tmp->next;
	}
}
