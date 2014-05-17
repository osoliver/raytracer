/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:12:51 by gmange            #+#    #+#             */
/*   Updated: 2013/12/01 19:25:37 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** function bugs when ft_strlen(s1) < ft_strlen (s2)
** pb of writing in unallocated memory
*/

char		*ft_strcpy(char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
