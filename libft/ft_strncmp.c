/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:30:47 by gmange            #+#    #+#             */
/*   Updated: 2013/12/02 21:58:47 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	if (n == (i = 0))
		return (0);
	while (s1[i] == s2[i] && s1[i])
	{
		if (++i >= n)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
