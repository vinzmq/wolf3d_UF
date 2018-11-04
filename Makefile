# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 08:25:30 by vmartynu          #+#    #+#              #
#    Updated: 2018/09/13 08:17:06 by vmartynu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
LIBFT = -L ./libft/Libft/ -lft
INC = -I ./inc/ -I ./SDL/SDL2.framework/Headers\
-I ./SDL/SDL2_image.framework/Headers\
-I ./SDL/SDL2_ttf.framework/Headers\
-I ./SDL/SDL2_mixer.framework/Headers
FRM = -F ./SDL/ -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer 
GCC = gcc -Wall -Wextra -Werror -g -O3
SRC =	./src/ft_int_strdel.c \
		./src/loop.c \
		./src/draw_scene.c \
		./src/set_colors.c \
		./src/find_walls.c \
		./src/ft_chartoi.c \
		./src/map_ret.c \
		./src/get_player_pos_n_exit.c \
		./src/free_mem.c \
		./src/dda_algorithm.c \
		./src/button_events.c \
		./src/putpixel.c \
		./src/render.c \
		./src/main.c \
		./src/read_map.c \
		./src/check_wall_d.c
OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/Libft/
	$(GCC)  -o $(NAME) $(OBJ) $(LIBFT) $(FRM) -rpath @loader_path/SDL
%.o : %.c ./inc/wolf.h
	 $(GCC) -c  $< -o $@ $(INC)
clean:
	rm -f $(OBJ)
	make clean -C libft/Libft/
fclean: clean
	rm -f $(NAME)
	make fclean -C libft/Libft/
re: fclean all

