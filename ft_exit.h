/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 18:52:12 by gmange            #+#    #+#             */
/*   Updated: 2014/03/01 16:07:59 by gmange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXIT_H
# define FT_EXIT_H

# include "rt.h"

# ifndef EXIT_SUCCESS
#  define	EXIT_SUCCESS		0
# endif

# ifndef EXIT_FAILURE
#  define	EXIT_FAILURE		1
# endif

# define	END_PUT(s, t)		(ft_end(env, put_error(s, t)))
# define	EXIT_PUT(s, t)		(ft_exit(ft_end(s, t)))

int				put_error(char *str1, char *str2);
int				ft_end(t_env *env, int ret);
void			ft_exit(int ret);

#endif
