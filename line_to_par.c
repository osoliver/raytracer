/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_par.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 20:28:57 by gmange            #+#    #+#             */
/*   Updated: 2014/03/05 21:53:52 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_exit.h"
#include "rt.h"

static char		*g_opcode[] =
{
	"camera", "sphere", "plane", "checker", "cylinder", "cone", "light", NULL
};

static int		g_opc[] =
{
	e_camera, e_sphere, e_plane, e_checker, e_cylinder, e_cone, e_light
};

int				get_opcode(const char *str)
{
	int		i;
	char	*tmp;

	if (!*str)
		return (-1);
	tmp = (char*)str;
	i = 0;
	while (g_opcode[i])
	{
		if (!ft_strcmp(ft_strtolower(tmp), g_opcode[i]))
			return (g_opc[i]);
		i++;
	}
	put_error("object was not recognised", NULL);
	return (-2);
}

int				line_to_par_int(t_env *env, int **param,
								int (*f)(const char *str))
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (param[i])
	{
		if (f == get_opcode)
		{
			if (read_w_comments(env, &line, 1) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
		}
		else if (!line && read_w_comments(env, &line, 0) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		*param[i++] = f(line);
		if (line)
			ft_memdel((void**)&line);
	}
	return (EXIT_SUCCESS);
}

int				line_to_par_float(t_env *env, float **param)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (param[i])
	{
		if (read_w_comments(env, &line, 1) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		*param[i++] = ft_atof(line);
		if (line)
			ft_memdel((void**)&line);
	}
	return (EXIT_SUCCESS);
}

int				line_to_par_char(t_env *env, unsigned char **param)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (param[i])
	{
		if (read_w_comments(env, &line, 1) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		*param[i++] = ft_atoi(line);
		if (line)
			ft_memdel((void**)&line);
	}
	return (EXIT_SUCCESS);
}

int				line_to_par_str(t_env *env, char **param[2])
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (param[i])
	{
		if (read_w_comments(env, &line, 1) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (ft_strncmp("NULL", line, 4))
		{
			if (!(*param[i] = ft_strsub(line, 0,
				ft_strichr(line, SEPARATOR_CHAR))) != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			if (line)
				ft_memdel((void**)&line);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
