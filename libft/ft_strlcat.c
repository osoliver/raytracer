/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:25:36 by gmange            #+#    #+#             */
/*   Updated: 2013/11/26 12:32:24 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;
	size_t		ret;

	ret = ft_strlen(src);
	if ((len = ft_strlen(dst)) >= size)
		return (size + ret);
	i = len;
	while (*src && size-- > len + 1)
		dst[i++] = *(src++);
	if (!*src || size == len)
		dst[i] = '\0';
	return (len + ret);
}
