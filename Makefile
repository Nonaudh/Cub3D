# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cblonde <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 09:14:44 by cblonde           #+#    #+#              #
#    Updated: 2024/09/30 10:38:09 by cblonde          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -g # -Werror -Wextra -Wall -g

INCLUDE = -Iinclude -Ilib -Imlx -I/usr/include

LIBRARIES = -Llib -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIBMAC = -Llib -lft -Lmlx -L/usr/lib -L/usr/X11/lib -lXext -lX11\
		 -lmlx -framework OpenGL -framework AppKit

DSRC = src/

DMAP = src/map/

DPARSE = src/parse/

DPLAYER = src/player/

DLIB = lib/

DERR = src/error/

DGRAPH = src/libgraph/

DMMAP = src/minimap/

DDATA = src/data/

DRAY = src/raycasting/

DIN = src/input/

DSPRITE = src/sprite/

LIB = $(DLIB)libft.a

DMLX = mlx/

MLX = $(DMLX)libmlx.a

SRC = $(DSRC)main.c $(DMAP)utils_map.c $(DPARSE)ft_readfile.c\
	  $(DPARSE)initialize_map.c $(DERR)err_ptr.c $(DPARSE)get_map_infos.c\
	  $(DERR)err_file.c $(DPARSE)get_map_colors.c $(DPLAYER)util_player.c\
	  $(DPARSE)handle_map_err.c $(DPARSE)util_map_err.c $(DERR)err_map.c\
	  $(DERR)validated.c $(DGRAPH)ft_initmlx.c $(DGRAPH)render_pixel.c\
	  $(DGRAPH)build_img.c $(DMMAP)init_mmap.c $(DDATA)util_data.c\
	  $(DPLAYER)mouvement.c $(DPLAYER)rotation.c $(DGRAPH)handle_keys.c\
	  $(DMMAP)render_mnmap.c $(DRAY)draw_line.c $(DRAY)raycasting.c $(DRAY)floor_celling.c\
	  $(DIN)handle_input.c $(DDATA)textures.c $(DSPRITE)util_sprite.c \
	   #$(DSPRITE)render_sprite.c $(DSPRITE)sort_sprites.c

NAME = cube

all : $(NAME)

DBUILD = build/

OBJ = $(addprefix $(DBUILD),$(SRC:%.c=%.o))

$(DBUILD)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(LIB) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBRARIES) -o $(NAME)

$(LIB) :
	@make -C $(DLIB) --no-print-directory --silent

$(MLX) :
	@make -C $(DMLX) --no-print-directory --silent

clean :
	@make clean -C $(DLIB) --no-print-directory --silent
	@make clean -C $(DMLX) --no-print-directory --silent
	@rm -rf $(DBUILD)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(LIB)

re : fclean $(NAME)

.PHONY: all clean fclean re
