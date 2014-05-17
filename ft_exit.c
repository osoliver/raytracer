/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:11:28 by gmange            #+#    #+#             */
/*   Updated: 2014/03/14 22:46:52 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "libft.h"
#include "rt.h"
#include "ft_exit.h"

int		put_error(char *str1, char *str2)
{
	ft_putstr_fd(TITLE, 2);
	ft_putstr_fd(": ", 2);
	if (str1)
	{
		if (str2)
		{
			ft_putstr_fd(str1, 2);
			ft_putendl_fd(str2, 2);
		}
		ft_putendl_fd(str1, 2);
	}
	else if (str2)
		ft_putendl_fd(str2, 2);
	if (errno)
		perror(NULL);
	return (EXIT_FAILURE);
}

int		ft_end(t_env *env, int ret)
{
	if (env)
	{
		if (FD && close(FD) < 0)
			return (put_error("file could not be closed: ", NULL));
		lst_obj_del(OBJ);
		lst_cam_del(CAM);
		lst_light_del(LIGHT);
		if (E_MLX)
		{
			if (IMG)
				mlx_destroy_image(MLX, IMG);
			if (WIN)
				mlx_destroy_window(MLX, WIN);
			ft_memdel((void**)&E_MLX);
		}
		ft_bzero(env, sizeof(*env));
		ft_memdel((void**)&env);
	}
	return (ret);
}

void	ft_exit(int ret)
{
	exit(ret);
}
