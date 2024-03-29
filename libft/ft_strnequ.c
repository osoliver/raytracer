/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:34:58 by gmange            #+#    #+#             */
/*   Updated: 2013/11/27 09:39:23 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n || (!s1 && !s2))
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, n))
		return (0);
	return (1);
}
