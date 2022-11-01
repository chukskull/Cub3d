# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 13:52:55 by azouaghi          #+#    #+#              #
#    Updated: 2022/11/01 13:55:01 by azouaghi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc

FLAGS= -Wall -Wextra -Werror

FILES=	cub3d draw_with_pixels/fill_buffer_by_pixels draw_with_pixels/draw \
		draw_with_pixels/render_for_player draw_with_pixels/find_wall utils/get_infos \
		draw_with_pixels/draw_evertn draw_with_pixels/draw_walls \
		utils/get_textures utils/get_width utils/get_height utils/get_addr_img parsing/ft_exit \
		draw_with_pixels/draw_wall2 parsing/ft_error parsing/gnl parsing/check_extension \
		parsing/get_map parsing/check_utils parsing/ft_strdup parsing/ft_strlen \
		parsing/ft_strjoin parsing/ft_atoi parsing/map_utils2 parsing/parsing_utils \
		parsing/get_texts_colors parsing/colors_utils parsing/get_textures parsing/check_map \
		parsing/map_utils parsing/ft_split parsing/ft_strcmp parsing/ft_substr parsing/parsing \
		parsing/ft_memset utils/key_hook_utils

B_DIR=build

NAME=cub3D

INCLUDE= -I./inc -I./libft
INCLUDES=cub3d.h parsing.h texture.h utils.h
INCLUDES_FILES=$(addprefix ./inc/, $(INCLUDES))

.PHONY = all re clean fclean

RM=rm -rf

OBJ=$(addprefix $(B_DIR)/, $(FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES_FILES)
	$(CC) $(OBJ)  -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)


$(B_DIR)/%.o: src/%.c $(INCLUDES_FILES)
	mkdir -p $(@D)
	$(CC) $(INCLUDE) $(FLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(B_DIR)

fclean: clean
	$(RM) $(NAME)

re : fclean all
