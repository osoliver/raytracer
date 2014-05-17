/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:29:38 by gmange            #+#    #+#             */
/*   Updated: 2013/11/30 10:05:04 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	size_t		i;

	if (!s || !f || !(str = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
