/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 08:18:20 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 20:07:27 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_H
# define EDIT_H

# include "rt.h"
# include "edit_types.h"

# define T_ESC		65307
# define T_ENTER	65421
# define T_RETURN	65293
# define T_TAB		65289
# define T_G		103
# define T_S		115
# define T_R		114
# define T_C		99

int					edit_scn(t_env *env);
int					expose_edit_hook(t_env *env);
int					close_edit_window(t_env *env, int quit);
int					mouse_edit_hook(int but, int x, int y, t_env *env);
int					launch_edit_mode(t_env *env);
int					key_edit_hook(int keycode, t_env *env);
void				change_mode(t_env *env, int key);
int					copy_env_mods(t_env *env);
void				grab_mode(t_env *env);
void				scale_mode(t_env *env);
void				rotate_mode(t_env *env);
void				color_mode(t_env *env);
t_light				*edit_light(t_env *env);
int					movement_selection(t_env *env, int axis, int more_less);
int					move_camera(t_env *env, int axis, int more_less);
int					origin_cam(t_env *env, int key);
int					rotate_camera(t_env *env, int axis, int more_less);
int					move_object(t_env *env, int axis, int more_less);
int					scale(t_env *env, int axis, int more_less);
int					rotate_object(t_env *env, int axis, int more_less);
int					object_color(t_env *env, int axis, int more_less);
void				unselect_object(t_env *env);
void				select_object(int x, int y, t_env *env);
void				next_object(t_env *env);
t_obj				*get_float_tab(t_obj *dst, t_obj *src);
t_obj				*get_link(t_obj *src, int flag);
t_obj				*copy_object(t_obj *src, int flag);
t_obj				*modify_object(t_obj *obj);
t_cam				*copy_cam(t_cam *src);
void				put_button(t_env *env, int mode);
t_list				*set_panel(void);
int					mode_buttons(int x, int y);
int					axis_buttons(int x, int y);
int					more_less_buttons(int x, int y);
int					done_buttons(int x, int y);
int					ref_modification(t_env *env, int more_less);
t_buts				*init_button(t_list *ptr, char *name);
t_list				*set_mode_buttons(t_list **ptr);
t_list				*set_more_less_buttons(t_list **ptr);
t_list				*set_axis_buttons(t_list **ptr);
t_list				*set_done_buttons(t_list **ptr);
int					apply_modification(t_env *env, t_list *ptr);
int					select_button(int x, int y, t_env *env);
void				del(void *link, size_t but_size);

#endif
