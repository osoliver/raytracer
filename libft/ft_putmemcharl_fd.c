/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemcharl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 10:39:26 by gmange            #+#    #+#             */
/*   Updated: 2013/12/13 10:39:37 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmemcharl_fd(void *ptr, size_t n, int fd)
{
	ft_putmemchar_fd(ptr, n, fd);
	ft_putchar_fd('\n', fd);
}
