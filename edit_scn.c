/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_scn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: po-conno <po-conno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:40:56 by po-conno          #+#    #+#             */
/*   Updated: 2014/03/27 19:58:06 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include </opt/X11/include/X11/X.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_exit.h"
#include "edit.h"

int			close_edit_window(t_env *env, int quit)
{
	if (env)
	{
		if (env->selected)
			unselect_object(env);
		env->selected = NULL;
		lst_obj_del(OBJ);
		lst_cam_del(CAM);
		lst_light_del(LIGHT);
		ft_lstdel(&(env->panel), &del);
		if (E_MLX)
		{
			if (env->panel_img)
				mlx_destroy_image(MLX, env->panel_img);
			if (IMG)
				mlx_destroy_image(MLX, IMG);
			if (WIN)
				mlx_destroy_window(MLX, WIN);
			ft_memdel((void **)&E_MLX);
		}
		ft_bzero(env, sizeof(*env));
		ft_memdel((void **)&env);
	}
	if (quit)
		exit(0);
	return (0);
}

int			expose_edit_hook(t_env *env)
{
	if (world_to_cam(env, CAM) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (draw_edit(env) != EXIT_SUCCESS)
		ft_exit(ft_end(env, EXIT_FAILURE));
	mlx_put_image_to_window(MLX, WIN, env->panel_img, I_WDT, 0);
	return (1);
}

int			mouse_edit_hook(int but, int x, int y, t_env *env)
{
	if (but != 1)
		return (0);
	if ((x > I_WDT) && (but || x || y))
		select_button(x, y, env);
	else if ((x < I_WDT) && (but || x || y))
		select_object(x, y, env);
	expose_edit_hook(env);
	return (0);
}

int			launch_edit_mode(t_env *env)
{
	int		wdt;
	int		hgt;
	int		bpp;
	int		endian;

	if (!(WIN = mlx_new_window(MLX, E_WDT, E_HGT, EDIT_TITLE)))
		return (END_PUT("mlx_new_window error", NULL));
	if (!(IMG = mlx_new_image(MLX, E_WDT, E_HGT)))
		return (END_PUT("mlx_new_image error", NULL));
	if (!(IMG_ADR = mlx_get_data_addr(IMG, &bpp, &ROW_SZE, &endian)))
		return (END_PUT("mlx_get_data_addr error", NULL));
	env->panel_img = mlx_xpm_file_to_image(MLX, "panel/panel.xpm", &wdt, &hgt);
	E_WDT = I_WDT;
	BPP = bpp / 8;
	mlx_key_hook(WIN, key_edit_hook, env);
	mlx_expose_hook(WIN, expose_edit_hook, env);
	mlx_mouse_hook(WIN, mouse_edit_hook, env);
	return (EXIT_SUCCESS);
}

int			edit_scn(t_env *env)
{
	t_env	*copy;

	copy = NULL;
	if (!(copy = (t_env*)ft_memalloc(sizeof(t_env))))
		return (END_PUT("malloc error", NULL));
	if (!copy->mlx && !(copy->mlx = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		return (END_PUT("malloc error", NULL));
	env->edit = 1;
	copy->width = MWDT;
	copy->height = MHGT;
	copy->ref_lvl = 0;
	copy->save = env;
	copy->mlx->mlx = MLX;
	copy->obj = copy_object(OBJ, 0);
	copy->cam = copy_cam(CAM);
	copy->light = edit_light(env);
	copy->selected = NULL;
	copy->save_cam = NULL;
	copy->mod = _cam;
	copy->panel = set_panel();
	return (launch_edit_mode(copy));
}
