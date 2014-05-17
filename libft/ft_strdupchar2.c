/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchar2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:44:26 by gmange            #+#    #+#             */
/*   Updated: 2014/02/09 21:01:22 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strdupchar2(const char **s1)
{
	char		**s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = ft_strdup(s1[i]);
		i++;
	}
	return (s2);
}
