/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweibel <mweibel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 16:05:17 by mweibel           #+#    #+#             */
/*   Updated: 2014/03/27 16:05:18 by mweibel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTURES_H
# define RT_STRUCTURES_H

# define	DIM			3
# define	MOD			16
# define	THREAD_NB	8

enum
{
	e_camera,
	e_sphere = MOD,
	e_plane,
	e_checker,
	e_cylinder,
	e_cone,
	e_light = 2 * MOD
};

/*
** details of params for each object:
** _sphere_
** OPC = MOD
** par1 = radius
** _plane_
** OPC = MOD + 1
** rot_wor[DIM] = normale vector of the plane (x, y, z)
** _cylinder_
** OPC = MOD + 3
** par1 = radius
** par2 = n/a
** _cone_
** OPC = MOD + 4
** par1 = opening angle
** par2 = n/a
*/
typedef struct		s_obj
{
	int				opc;
	float			pos_wor[DIM];
	float			rot_wor[DIM];
	float			pos_cam[DIM];
	float			rot_cam[DIM];
	float			pos_dot[DIM];
	float			rot_dot[DIM];
	float			tmp_rot[DIM];
	float			**rot_mtx;
	float			reflexion;
	float			refraction;
	float			specular;
	float			normal;
	float			par1;
	float			par2;
	unsigned char	selec_color[4];
	float			color[4];
	float			color2[4];
	char			*texture;
	char			*ftexture;
	int				bpp;
	int				szeline;
	int				endian;
	float			float_wdt;
	float			float_hgt;
	int				t_wdt;
	int				t_hgt;
	char			*bump;
	struct s_obj	*nxt;
}					t_obj;

typedef struct		s_cam
{
	int				opc;
	float			pos_wor[DIM];
	float			pos_cam[DIM];
	float			rot_wor[DIM];
	float			rdir[DIM];
	float			**trf_mtx;
	struct s_cam	*nxt;
}					t_cam;

typedef struct		s_light
{
	int				opc;
	float			pos_wor[DIM];
	float			rot_wor[DIM];
	float			pos_cam[DIM];
	float			rot_cam[DIM];
	unsigned char	color[4];
	struct s_light	*nxt;
}					t_light;

typedef struct		s_dot
{
	int				thread_number;
	float			rdir[DIM];
	float			rot_ray[DIM];
	float			rot_l[DIM];
	float			pos_cam[DIM];
	float			normal[DIM];
	int				idx;
	float			dst;
	t_obj			*obj;
	t_light			*light;
	t_cam			*cam;
	float			intensity;
	float			px_color[4];
	int				max_draw;
	float			*color;
	struct s_dot	*nxt;
}					t_dot;

/*
** BPP stands for "Bytes" Per Pixel and not "Bits", aka Bytes == 'Bits * 8'
** ^ easy way to remember that: B always mean Byte, b always stand for bit
** There are no Bits.
*/
typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_adr;
	int				bpp;
	int				row_sze;
}					t_mlx;

typedef struct		s_env
{
	int				fd;
	t_mlx			*mlx;
	t_obj			*obj;
	t_obj			*selected;
	t_cam			*cam;
	t_cam			*save_cam;
	t_dot			*dot;
	t_dot			*tab_dot[THREAD_NB];
	int				imglen;
	int				step;
	char			*alea;
	float			rdm;
	int				drawn;
	int				mt_idx;
	int				idx[THREAD_NB];
	t_light			*light;
	int				ref_lvl;
	int				width;
	int				height;
	int				mod;
	int				axis;
	int				edit;
	t_list			*panel;
	void			*panel_img;
	struct s_env	*save;
}					t_env;

#endif
