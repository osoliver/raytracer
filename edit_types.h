/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:47:43 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:57:01 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_TYPES_H
# define EDIT_TYPES_H

typedef enum		e_mode
{
	_cam,
	_grab,
	_scale,
	_rotate,
	_color
}					t_mode;

typedef enum		e_buttons
{
	e_modeb,
	e_axisb,
	e_more_lessb,
	e_doneb
}					t_buttons;

typedef struct		s_buts
{
	char			*name;
	int				x;
	int				y;
	int				wdt;
	int				hgt;
	int				mode;
	int				type;
}					t_buts;

typedef void		(*t_mod)(t_env *);
typedef int			(*t_mov)(t_env *, int, int);

#endif
