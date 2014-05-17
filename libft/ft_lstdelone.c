/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:54:05 by gmange            #+#    #+#             */
/*   Updated: 2014/01/23 12:48:33 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	tmp = *alst;
	*alst = (*alst)->next;
	del((tmp)->content, (tmp)->content_size);
	free(tmp);
	tmp = NULL;
}
