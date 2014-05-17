/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncharl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 09:17:35 by gmange            #+#    #+#             */
/*   Updated: 2013/12/13 10:45:06 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putncharl_fd(char c, size_t n, int fd)
{
	ft_putnchar_fd(c, n, fd);
	ft_putchar_fd('\n', fd);
}
