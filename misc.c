/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:31:12 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 14:31:14 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt.h"
#include "get_next_line.h"
#include "ft_exit.h"

float	dotproduct(float *v1, float *v2)
{
	float		i;

	i = (v1[0] * v2[0]) + (v1[1] * v2[1]) + (v1[2] * v2[2]);
	return (i);
}

int		read_w_comments(t_env *env, char **line, char c)
{
	int		ret;

	while ((ret = get_next_line(FD, line)) > 0 && **line == COMMENT_CHAR)
		ft_memdel((void**)line);
	if (ret < 0)
		return (END_PUT("gnl error", NULL));
	if (!ret && !c)
		return (END_PUT("file is too short, missing information", NULL));
	return (EXIT_SUCCESS);
}

float	normalize_ray(float (*ray)[3])
{
	float	len;

	len = 0;
	len = sqrtf((*ray)[0] * (*ray)[0] + (*ray)[1] * (*ray)[1]
				+ (*ray)[2] * (*ray)[2]);
	(*ray)[0] /= len;
	(*ray)[1] /= len;
	(*ray)[2] /= len;
	return (len);
}

float	normalize_len(float len, float *v)
{
	float	pos[DIM];

	pos[0] = len * v[0];
	pos[1] = len * v[1];
	pos[2] = len * v[2];
	len = sqrtf(dotproduct(pos, pos));
	return (len);
}

void	substract_vector(float *v1, float *v2, float (*v3)[DIM])
{
	(*v3)[0] = v1[0] - v2[0];
	(*v3)[1] = v1[1] - v2[1];
	(*v3)[2] = v1[2] - v2[2];
}
