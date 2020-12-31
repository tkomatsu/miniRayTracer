# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 20:22:12 by tkomatsu          #+#    #+#              #
#    Updated: 2020/12/28 16:53:56 by tkomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_GREY	= \x1b[30m
_RED	= \x1b[31m
_GREEN	= \x1b[32m
_YELLOW	= \x1b[33m
_BLUE	= \x1b[34m
_PURPLE	= \x1b[35m
_CYAN	= \x1b[36m
_WHITE	= \x1b[37m
_END	= \x1b[0m

# OS
UNAME := $(shell uname)

NAME = miniRT

CC = gcc

INCLUDE = includes
SRC_DIR = srcs/
LIB = lib/

FILES =	main.c\
		utils/bmp.c \
		utils/show_rt.c \
		utils/img_init.c \
		utils/color.c \
		utils/ft_mlx_pixel_put.c \
		utils/loop_hook.c \
		utils/export.c \
		utils/mem_free.c \
		utils/err_handle.c \
		readfile/read_rt.c \
		readfile/read_shapes.c \
		readfile/read_util.c \
		raytrace/raytrace.c \
		raytrace/get_nearest.c \
		raytrace/hit_decision_sphere.c \
		raytrace/hit_decision_plane.c \
		raytrace/hit_decision_square.c \
		raytrace/hit_decision_triangle.c \
		raytrace/hit_decision_cylinder.c \
		raytrace/calc_ray.c \
		raytrace/specular.c \
		raytrace/diffuse.c
#		../test/print_mrt.c

SRCS = $(addprefix $(SRC_DIR), $(FILES))

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE)
OSX_MACRO = -D OSX
LINUX_MACRO = -D LINUX

FLAGS = -lm -L $(LIB)libft -lft -L $(LIB)libvct -lvct
OSX_FLAGS = libmlx.dylib -framework OpenGL -framework AppKit -lz
LINUX_FLAGS = -L $(LIB) -lmlx -lXext -lX11

DEBUG_CFLAGS = -g3 -D DEBUG

ifeq ($(UNAME),Darwin)
	CFLAGS += $(OSX_MACRO)
	FLAGS += $(OSX_FLAGS)
endif
ifeq ($(UNAME),Linux)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB)libft
	@make -C $(LIB)libvct
	@$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $@
	@echo "$(_GREEN)Finish compiling $(NAME)!"
	@echo "Try \"./$(NAME) <rt file>\" to use$(_END)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@ 

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: re
	@echo "DEBUG\t\tDebug build done"

leak: CFLAGS += -fsanitize=address $(DEBUG_CFLAGS)
leak: re
	echo $(CFLAGS)

clean:
	@echo "$(_YELLOW)Removing object files ...$(_END)"
	@make clean -C $(LIB)libft
	@make clean -C $(LIB)libvct
	@rm -f $(OBJS)
	@rm -fr *.dSYM

fclean:
	@echo "$(_RED)Removing object files and program ...$(_END)"
	@make fclean -C $(LIB)libft
	@make fclean -C $(LIB)libvct
	@rm -f $(NAME) $(OBJS)
	@rm -fr *.dSYM

re: fclean all

PHONY: all clean fclean re

