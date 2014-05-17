/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 19:06:09 by gmange            #+#    #+#             */
/*   Updated: 2014/03/27 18:55:05 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include </opt/X11/include/X11/X.h>
#include <stdlib.h>
#include <pthread.h>
#include "edit.h"
#include "ft_exit.h"
#include "rt.h"

static int		init_dotx(t_env *env)
{
	int			i;

	i = 0;
	while (i < THREAD_NB)
	{
		if (DOTX(i) == NULL)
		{
			if (!(DOTX(i) = (t_dot*)ft_memalloc(sizeof(t_dot))))
				return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

static int		mt_draw(t_env *env)
{
	pthread_t	draw_thread[THREAD_NB];
	int			i;

	if (init_dotx(env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	E_IMGLEN = WDT * HGT;
	E_STEP = THREAD_NB * STEP;
	E_DRAWN = 0;
	MT_IDX = 0;
	i = 0;
	while (i < THREAD_NB)
	{
		pthread_create(draw_thread + i, NULL, mt_draw_scn, env);
		++i;
	}
	i = 0;
	while (i < THREAD_NB)
	{
		pthread_join(draw_thread[i], NULL);
		++i;
	}
	finish_drawing(env);
	ft_bzero(E_ALEA, IMG_LEN);
	return (EXIT_SUCCESS);
}

static int		key_hook(int keycode, t_env *env)
{
	if (keycode == T_ESC)
		ft_exit(ft_end(env, EXIT_SUCCESS));
	if (keycode == T_E && !env->edit)
		edit_scn(env);
	return (1);
}

int				expose_hook(t_env *env)
{
	if (world_to_cam(env, CAM) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (mt_draw(env) != EXIT_SUCCESS)
		ft_exit(ft_end(env, EXIT_FAILURE));
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (1);
}

int				mlx_launch(t_env *env)
{
	int		bpp;
	int		endian;

	if (!E_MLX && !(E_MLX = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		return (END_PUT("malloc error", NULL));
	if (!(MLX = mlx_init()))
		return (END_PUT("mlx_init error", NULL));
	get_textures(env);
	if (!(WIN = mlx_new_window(MLX, E_WDT, E_HGT, TITLE)))
		return (END_PUT("mlx_new_window error", NULL));
	if (!(IMG = mlx_new_image(MLX, E_WDT, E_HGT)))
		return (END_PUT("mlx_new_image error", NULL));
	if (!(IMG_ADR = mlx_get_data_addr(IMG, &bpp, &ROW_SZE, &endian)))
		return (END_PUT("mlx_get_data_addr error", NULL));
	if (!(E_ALEA = ft_memalloc(sizeof(char) * (IMG_LEN))))
		return (END_PUT("malloc error", NULL));
	BPP = bpp / 8;
	srand(time(NULL));
	mlx_key_hook(WIN, key_hook, env);
	mlx_expose_hook(WIN, expose_hook, env);
	mlx_hook(WIN, KeyPress, KeyPressMask, key_hook, env);
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, key_hook, env);
	mlx_loop(MLX);
	return (EXIT_SUCCESS);
}
