/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 00:28:54 by gmange            #+#    #+#             */
/*   Updated: 2014/03/26 19:04:33 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_exit.h"
#include "rt.h"

static t_env	*env_init(void)
{
	static t_env	*env = NULL;

	if (env)
		return (env);
	errno = 0;
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->save = NULL;
	env->panel = NULL;
	env->width = WDT;
	env->height = HGT;
	env->ref_lvl = 5;
	return (env);
}

static int		rt(t_env *env)
{
	if (file_to_env(env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (close(FD) < 0)
		return (END_PUT("file could not be closed properly: ", NULL));
	FD = 0;
	return (mlx_launch(env));
}

static void		signal_handler(int sig)
{
	t_env		*env;

	if (sig != SIGPIPE)
		return ;
	env = NULL;
	env = env_init();
	ft_exit(ft_end(env, EXIT_SUCCESS));
}

static int		get_rdm_factor(char **av)
{
	int		factor;

	factor = 0;
	if (ft_strcmp("-r", av[1]))
		return (-1);
	if ((factor = ft_atoi(av[2])) >= 0)
	{
		if (factor <= 100)
			return (factor);
		return (100);
	}
	return (-1);
}

int				main(int ac, char **av)
{
	t_env	*env;
	int		my_factor;
	int		fd;

	fd = 1;
	if ((ac != 2 && ac != 4)
		|| (ac == 4 && (my_factor = get_rdm_factor(av)) == -1))
		return (put_error("usage: [-r 0 - 100] file", NULL));
	if (ac != 2)
		fd = 3;
	signal(SIGPIPE, signal_handler);
	if (!(env = env_init()))
		return (END_PUT("malloc error", NULL));
	env->rdm = ((float)my_factor) / 100;
	if ((FD = open(av[fd], O_RDONLY)) < 0)
		return (END_PUT("file could not be found: ", av[1]));
	if (rt(env) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
