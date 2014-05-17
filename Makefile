#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmange <gmange@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:19:56 by gmange            #+#    #+#              #
#    Updated: 2014/03/27 20:07:20 by po-conno         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


GCC				=	cc -o2 #beware
FLAGS			=	-Wall -Wextra -Werror -pedantic
LIB_ADD			=	-L /usr/X11/lib -lmlx -lXext -lX11 -lm -lpthread
NAME			=	rt
HEAD			=	rt.h get_next_line.h ft_exit.h edit.h
OTH				=	$(TEST1) $(TEST2)
MKF				=	Makefile

TEST1			=	bug1ex.scn
TEST2			=	2ex.scn
TEST			=	$(TEST1) $(TEST2)

DBG_FLD			=	$(NAME).dSYM

PTH_SRC			=	.
PTH_LIB			=	$(PTH_SRC)/libft
LIB				=	$(PTH_LIB)/libft.a
PTH_INC			=	$(PTH_LIB)/includes

SRC				=	$(addprefix $(PTH_SRC)/, \
					rt.c ft_exit.c file_to_env.c lst_obj.c file_to_cam.c \
					file_to_obj.c file_to_light.c \
					line_to_par.c get_next_line.c lst_obj.c \
					obj_plane.c obj_cylinder.c obj_cone.c obj_sphere.c \
					mlx_launch.c init_trf_mtx.c lights.c edit_scn.c \
					mode_selection.c object_mod.c draw_edit.c edit_light.c \
					move_object.c object_color.c scale_object.c \
					object_selection.c set_mode.c movement_selection.c \
					move_camera.c rotate_object.c rotate_camera.c copy_cam.c \
					panel_modes.c panel_buttons.c textures.c \
					panel_selections.c panel_list.c del_panel_lst.c \
					misc.c mt_aa_draw.c mt_rng_draw.c mt_init_draw.c \
					world_to_cam.c normal.c lights_refract.c lights_reflect.c \
					lights_dot_data.c)

OBJ				=	$(SRC:.c=.o)
ALL_FIL			=	$(SRC) $(OBJ) $(LIB) $(MKF) $(HEAD) $(OTH)
ALF_DOT			=	$(ALL_FIL:%=.\#%)
ALF_SHP			=	$(ALL_FIL:%=\#%\#)
ALF_TLD			=	$(ALL_FIL:%=%~)
ALF_TMP			=	$(AFF_DOT) $(ALF_SHP) $(ALF_TLD) $(FT_DIFF) $(SY_DIFF) \
					$(TEST)
ALF_SYC			=	$(ALL_FIL:%=%.!sync) $(ALF_TMP:%=%.!sync)

all: $(NAME)

$(LIB):
	make -C $(PTH_LIB)/

%.o: %.c $(HEAD)
	$(GCC) $(FLAGS) -I $(PTH_INC)/ -o $@ -c $<

$(NAME): $(LIB) $(OBJ)
	$(GCC) $(FLAGS) -I $(PTH_INC)/ -o $(NAME) $^ $(LIB_ADD)

t: $(NAME)
	./$(NAME) $(TEST1)

clean: cleanlib
	/bin/rm -f $(OBJ)

fclean: fcleanlib clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(ALF_DOT)
	/bin/rm -f $(ALF_SHP)
	/bin/rm -f $(ALF_TLD)
	/bin/rm -f $(ALF_SYC)
	/bin/rm -rf $(DBG_FLD)

cleanlib:
	make -C $(PTH_LIB)/ clean

fcleanlib:
	make -C $(PTH_LIB)/ fclean

re: fclean all

.PHONY: all clean fclean re cleanlib fcleanlib
#.SILENT:
