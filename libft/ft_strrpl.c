/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 09:09:55 by gmange            #+#    #+#             */
/*   Updated: 2014/02/16 21:15:45 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns s where the first occurrence of src in s is replace by dst
** result is undefined when a pointer is NULL
*/

/*
** final ft_strdup3 is not protected on purpose, enables to ft_memdel anyway
*/

char			*ft_strrpl(char *s, char *src, char *dst)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	size_t	i;

	if ((int)(i = ft_stristr(s, src)) < 0)
		return (NULL);
	if (!(tmp = ft_strsub(s, 0, i)))
		return (NULL);
	i += ft_strlen(src);
	if (!(tmp2 = ft_strsub(s, i, ft_strlen(s) - i)))
	{
		ft_memdel((void**)&tmp);
		return (NULL);
	}
	str = ft_strdup3(tmp, dst, tmp2);
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&tmp2);
	return (str);
}
