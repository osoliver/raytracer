#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmange <gmange@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:19:56 by gmange            #+#    #+#              #
#    Updated: 2014/03/02 13:32:30 by gmange           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC				=	gcc #beware
FLAGS			=	-Wall -Wextra -Werror -pedantic -ansi
MAKEFILE		=	Makefile
HEADERS			=	libft.h

PATH_SRCS		=	.

LIBRAIRY		=	$(PATH_SRCS)/libft.a
PATH_INCL		=	$(PATH_SRCS)/includes

SRCS			=	$(addprefix $(PATH_SRCS)/, ft_memset.c ft_bzero.c \
					ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
					ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
					ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
					ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
					ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
					ft_toupper.c ft_tolower.c \
					\
					ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
					ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
					ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
					ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
					ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c \
					\
					ft_lstnew.c ft_lstdellast.c ft_lstdel.c ft_lstadd.c \
					ft_lstiter.c ft_lstmap.c \
					\
					ft_lstaddtoend.c ft_lstdelone.c ft_lstaddnew.c \
					ft_lstnewtoend.c ft_lstdelif.c \
					\
					ft_putmemchar.c ft_putmemchar_fd.c ft_putmemcharl.c \
					ft_putmemcharl_fd.c \
					ft_putnchar.c ft_putnchar_fd.c ft_putncharl.c \
					ft_putncharl_fd.c ft_putnbrl.c ft_putnbrl_fd.c \
					\
					ft_swap.c ft_memlen.c ft_strichr.c ft_strirchr.c \
					ft_stristr.c \
					ft_nbrlen.c ft_strdupchar2.c ft_freechar2.c ft_putchar2.c \
					ft_strcpy2.c ft_strdup3.c ft_endianness.c ft_is_wht_spc.c \
					ft_ptrlen.c ft_strrpl.c ft_strtoupper.c ft_strtolower.c \
					ft_atof.c)

OBJS			=	$(SRCS:.c=.o)
ALL_FILES		=	$(SRCS) $(OBJS) $(LIBRAIRY) $(MAKEFILE) $(HEADERS)
AF_DOT			=	$(ALL_FILES:%=.\#%)
AF_SHARP		=	$(ALL_FILES:%=\#%\#)
AF_TILDE		=	$(ALL_FILES:%=%~)
AF_TMP			=	$(AF_DOT) $(AF_SHARP) $(AF_TILDE)
AF_SYNC			=	$(ALL_FILES:%=%.!sync) $(AF_TMP:%=%.!sync)

all: $(LIBRAIRY)

$(NAME):

$(LIBRAIRY): $(OBJS) $(HEAD)
	ar rc $@ $?
	ranlib $(LIBRAIRY)

%.o: %.c $(HEAD)
	$(GCC) $(FLAGS) -I $(PATH_INCL)/ -o $@ -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(LIBRAIRY)
	/bin/rm -f $(AF_DOT)
	/bin/rm -f $(AF_SHARP)
	/bin/rm -f $(AF_TILDE)
	/bin/rm -f $(AF_SYNC)

re: fclean all

.PHONY: all clean fclean re
.SILENT:
