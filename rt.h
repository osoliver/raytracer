/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmange <gmange@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 08:59:22 by gmange            #+#    #+#             */
/*   Updated: 2014/03/27 15:05:50 by po-conno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "rt_structures.h"

# ifndef STDIN_FILENO
#  define	STDIN_FILENO	0
# endif

# define	TITLE				"rt"
# define	EDIT_TITLE			"Edit"
# define	COMMENT_CHAR		'#'
# define	SEPARATOR_CHAR		' '

# define	WDT					800
# define	HGT					600
# define	MWDT				1000
# define	MHGT				600
# define	I_WDT				800
# define	E_WDT				(env->width)
# define	E_HGT				(env->height)
# define	IMG_LEN				((E_WDT) * (E_HGT))
# define	I_BPP				(i * (BPP / sizeof(unsigned int)))
# define	FOV					tan((45 * M_PI) / 180)
# define	PIX_NORM_X(r)		(((D_IDX % WDT) + r) / WDT)
# define	PIX_NORM_Y(r)		(((D_IDX / WDT) + r) / HGT)
# define	IAR					((float)WDT / (float)HGT)
# define	PIX_CAM_X(r)		((2.0 * PIX_NORM_X(r) - 1.0) * IAR * FOV)
# define	PIX_CAM_Y(r)		((1.0 - 2.0 * PIX_NORM_Y(r)) * FOV)
# define	EPIXNORM_X			(((D_IDX % E_WDT) + 0.5) / E_WDT)
# define	EPIXNORM_Y			(((D_IDX / E_WDT) + 0.5) / E_HGT)
# define	EPIXCAM_X			((2.0 * EPIXNORM_X - 1.0) * IAR * FOV)
# define	EPIXCAM_Y			((1.0 - 2.0 * EPIXNORM_Y) * FOV)
# define	DOTPROD(a, b)		((a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]))
# define	T_ESC				65307
# define	T_E					101

# define	COLOR_ALPHA			(16777216)
# define	COLOR_RED			(65536)
# define	COLOR_GREEN			(256)
# define	COLOR_BLUE			(1)

# define	MIX_ALPHA			D_COLOR[0] * COLOR_ALPHA
# define	MIX_RED				D_COLOR[1] * COLOR_RED
# define	MIX_GREEN			D_COLOR[2] * COLOR_GREEN
# define	MIX_BLUE			D_COLOR[3] * COLOR_BLUE
# define	MIX_PTR_COLOR		MIX_ALPHA + MIX_RED + MIX_GREEN + MIX_BLUE

# define	AA_ALPHA			(unsigned char)c[0] * COLOR_ALPHA
# define	AA_RED				(unsigned char)c[1] * COLOR_RED
# define	AA_GREEN			(unsigned char)c[2] * COLOR_GREEN
# define	AA_BLUE				(unsigned char)c[3] * COLOR_BLUE
# define	AA_PTR_COLOR		AA_ALPHA + AA_RED + AA_GREEN + AA_BLUE

# define	ERROR_F				(0.000001)
# define	GET_RGB(c)			mlx_get_color_value(MLX, (c))
# define	BCKGRND_COLOR		0x0
# define	REF_LVL				2
# define	CHK_SZE				4
# define	AMBIENT				0.2

# define	STEP				32
# define	RANDON_FACTOR		1

# define	O_OPC				obj->opc
# define	O_POS_WOR			obj->pos_wor
# define	O_ROT_WOR			obj->rot_wor
# define	O_POS_CAM			obj->pos_cam
# define	O_ROT_CAM			obj->rot_cam
# define	O_POS_DOT			obj->pos_dot
# define	O_ROT_DOT			obj->rot_dot
# define	PAR1				obj->par1
# define	PAR2				obj->par2
# define	O_COLOR				obj->color
# define	O_COLOR_A			obj->color[0]
# define	O_COLOR_R			obj->color[1]
# define	O_COLOR_G			obj->color[2]
# define	O_COLOR_B			obj->color[3]
# define	O_COLOR2			obj->color2
# define	O_COLOR2_A			obj->color2[0]
# define	O_COLOR2_R			obj->color2[1]
# define	O_COLOR2_G			obj->color2[2]
# define	O_COLOR2_B			obj->color2[3]
# define	O_TEXTURE			obj->texture
# define	O_TEX_WDT			obj->float_wdt
# define	O_TEX_HGT			obj->float_hgt
# define	REFLEXION			obj->reflexion
# define	REFRACTION			obj->refraction
# define	SPECULAR			obj->specular
# define	D_O_SPC				dot->obj->specular
# define	NORMAL				obj->normal
# define	O_NXT				obj->nxt

# define	C_OPC				cam->opc
# define	C_POS_WOR			cam->pos_wor
# define	C_POS_CAM			cam->pos_cam
# define	C_ROT_WOR			cam->rot_wor
# define	TRF_MTX				cam->trf_mtx
# define	C_NXT				cam->nxt

# define	L_OPC				light->opc
# define	L_POS_WOR			light->pos_wor
# define	L_ROT_WOR			light->rot_wor
# define	L_POS_CAM			light->pos_cam
# define	L_ROT_CAM			light->rot_cam
# define	L_COLOR_A			light->color[0]
# define	L_COLOR_R			light->color[1]
# define	L_COLOR_G			light->color[2]
# define	L_COLOR_B			light->color[3]
# define	L_NXT				light->nxt

# define	D_RDIR				DOT->rdir
# define	D_POS_CAM			DOT->pos_cam
# define	D_NORMAL			DOT->normal
# define	D_IDX				DOT->idx
# define	D_DST				DOT->dst
# define	D_OBJ				DOT->obj
# define	D_CAM				DOT->cam
# define	D_LIGHT				DOT->light
# define	D_COLOR				DOT->px_color
# define	D_C					dot->px_color
# define	ND_C				newdot.px_color
# define	D_OBJ_R				dot->obj->reflexion
# define	D_INTENSITY			DOT->intensity
# define	D_NXT				dot->nxt;
# define	D_OBJ_BPP			dot->obj->bpp
# define	D_OBJ_TEX			dot->obj->ftexture
# define	D_OBJ_LN			dot->obj->szeline
# define	D_OBJ_TWDT			dot->obj->t_wdt
# define	D_OBJ_OPC			dot->obj->opc

# define	D_OBJ_MT(a)			DOTX(a)->obj
# define	D_NXT_MT(a)			DOTX(a)->nxt;
# define	D_IDX_MT(a)			DOTX(a)->idx
# define	D_DST_MT(a)			DOTX(a)->dst
# define	D_COLOR_MT(a)		DOTX(a)->px_color
# define	MT_PIX_NORM_X(a, r)	(((D_IDX_MT(a) % WDT) + r) / WDT)
# define	MT_PIX_NORM_Y(a, r)	(((D_IDX_MT(a) / WDT) + r) / HGT)
# define	MT_PIX_CAM_X(a, r)	((2.0 * MT_PIX_NORM_X(a, r) - 1.0) * IAR * FOV)
# define	MT_PIX_CAM_Y(a, r)	((1.0 - 2.0 * MT_PIX_NORM_Y(a, r)) * FOV)

# define	MLX					E_MLX->mlx
# define	WIN					E_MLX->win
# define	IMG					E_MLX->img
# define	IMG_ADR				E_MLX->img_adr
# define	BPP					E_MLX->bpp
# define	ROW_SZE				E_MLX->row_sze

# define	FD					env->fd
# define	OBJ					env->obj
# define	E_MLX				env->mlx
# define	E_IDX				env->idx
# define	E_ALEA				env->alea
# define	E_STEP				env->step
# define	E_IMGLEN			env->imglen
# define	E_DRAWN				env->drawn
# define	CAM					env->cam
# define	LIGHT				env->light
# define	DOT					env->dot
# define	DOTX(a)				env->tab_dot[a]
# define	MT_IDX				env->mt_idx

int		file_to_env(t_env *env);
int		get_opcode(const char *str);
int		line_to_par_int(t_env *env, int **param, int f(const char *str));
int		line_to_par_float(t_env *env, float **param);
int		line_to_par_char(t_env *env, unsigned char **param);
int		line_to_par_str(t_env *env, char **param[2]);
int		file_to_cam(t_env *env, int opc);
int		file_to_obj(t_env *env, int opc);
int		file_to_light(t_env *env, int opc);
int		mlx_launch(t_env *env);
int		draw_scn(t_env *env);
void	lst_obj_del(t_obj *obj);
void	lst_cam_del(t_cam *cam);
void	lst_light_del(t_light *light);
float	**init_trf_mtx(float *rot_wor, float *pos_wor);
void	get_light(t_env *env, t_dot *dot);
float	dst_sphere(t_obj *obj, t_dot *dot, float (*l)[DIM]);
float	dst_cylinder(t_obj *obj, t_dot *dot, float (*l)[DIM]);
float	dst_plane(t_obj *obj, t_dot *dot, float (*l)[DIM]);
int		trace_ray(t_env *env, t_dot *dot, float (*l)[DIM], float v[DIM]);
void	substract_vector(float *v1, float *v2, float (*v3)[DIM]);
float	dotproduct(float *v1, float *v2);
void	get_reflect(t_env *env, t_dot *dot, int ref_lvl, int thread_number);
void	get_dot_datas(t_dot *dot, float src[DIM]);
float	normalize_ray(float (*ray)[3]);
void	get_refract(t_env *env, t_dot *dot, float refr_coef, int refr_lvl);
float	**init_obj_rot_mtx(float *rot_obj);
void	rotate_obj(t_obj *obj, t_dot *dot, float (*l)[DIM]);
float	dst_cone(t_obj *obj, t_dot *dot, float (*l)[DIM]);
float	dst_sphere(t_obj *obj, t_dot *dot, float (*l)[DIM]);
float	dst_plane(t_obj *obj, t_dot *dot, float (*l)[DIM]);
float	dst_cylinder(t_obj *obj, t_dot *dot, float (*l)[DIM]);
int		world_to_cam(t_env *env, t_cam *cam);
int		draw_edit(t_env *env);
int		expose_hook(t_env *env);
void	get_textures(t_env *env);
void	get_dot_texture(t_dot *dot);
void	*mt_draw_scn(void *env_ptr);
int		finish_drawing(t_env *env);
void	init_idx_n_ptr(unsigned int **ptr, t_env *env, int thread_nbr, int i);
int		mt_draw_edit(t_env *env);
void	*mt_draw_scn(void *env_ptr);
void	mt_init_dot(t_env *env, int thread_number, float x, float y);
void	init_idx_n_ptr(unsigned int **ptr, t_env *env, int thrd, int i);
void	mt_draw_antialiasing(t_env *env, unsigned int *ptr, int trd_num);
int		read_w_comments(t_env *env, char **line, char c);
void	normal_cone(t_dot *dot);
void	normal_cylinder(t_dot *dot);
void	normal_plane(t_dot *dot);
void	normal_sphere(t_dot *dot);
float	normalize_len(float len, float *v);
void	substract_vector(float *v1, float *v2, float (*v3)[DIM]);

#endif
