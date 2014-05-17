/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_rng_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:48:08 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 14:48:14 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <mlx.h>
#include "ft_exit.h"
#include "rt.h"

static int		fully_check(t_env *env)
{
	while (E_ALEA[(int)E_DRAWN] != 0)
	{
		++E_DRAWN;
		if (E_DRAWN >= E_IMGLEN)
			return (E_IMGLEN);
	}
	E_ALEA[(int)E_DRAWN] = 1;
	return ((int)E_DRAWN);
}

int				finish_drawing(t_env *env)
{
	unsigned int	*ptr;
	int				i;

	E_DRAWN = 0;
	while (i < E_IMGLEN)
	{
		i = fully_check(env);
		init_idx_n_ptr(&ptr, env, 0, i);
		mt_draw_antialiasing(env, ptr, 0);
	}
	return (EXIT_SUCCESS);
}

static int		randomize_order(t_env *env)
{
	unsigned int	random;
	static int		index = 0;

	if (E_DRAWN < env->rdm * (float)E_IMGLEN)
		random = (unsigned int)rand() % (unsigned int)E_IMGLEN;
	else
		random = index;
	while (E_ALEA[random] != 0)
	{
		++random;
		if ((int)random >= E_IMGLEN)
			random = 0;
	}
	if (E_DRAWN >= env->rdm * (float)E_IMGLEN)
		index = random;
	E_ALEA[random] = 1;
	++E_DRAWN;
	return (random);
}

void			*mt_draw_scn(void *env_ptr)
{
	unsigned int	*ptr;
	t_env			*env;
	int				thread_number;
	int				i;

	env = (t_env*)env_ptr;
	thread_number = MT_IDX;
	++MT_IDX;
	DOTX(thread_number)->thread_number = thread_number;
	while (E_DRAWN < E_IMGLEN)
	{
		if (E_DRAWN >= 0.999 * (float)E_IMGLEN)
			pthread_exit(NULL);
		i = randomize_order(env);
		init_idx_n_ptr(&ptr, env, thread_number, i);
		mt_draw_antialiasing(env, ptr, thread_number);
		if (thread_number == THREAD_NB - 1 && !(E_DRAWN % E_STEP))
			mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	}
	return ((void*)EXIT_SUCCESS);
}
