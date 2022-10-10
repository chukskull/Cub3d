CC= cc

FLAGS= -Wall -Wextra -Werror

FILES=	cub3d draw_with_pixels/fill_buffer_by_pixels draw_with_pixels/draw \
		draw_with_pixels/render_for_player draw_with_pixels/find_wall utils/get_infos \
		draw_with_pixels/texture draw_with_pixels/draw_evertn draw_with_pixels/draw_walls \
		parsing/ft_exit_error parsing/ft_parse utils/get_next_line utils/ft_strchr_gnl \
		parsing/ft_parse_file parsing/ft_fill_state parsing/ft_extract_textures_colors \
		utils/ft_get_first_word parsing/ft_extract_texture

B_DIR=build

NAME=cub3d

LIBFT_DIR=libft
LIBFT=$(LIBFT_DIR)/libft.a

INCLUDE= -I./inc -I./libft

.PHONY = all re clean fclean

RM=rm -rf

OBJ=$(addprefix $(B_DIR)/, $(FILES:=.o))

all : $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(OBJ)  -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)


$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC)  $(INCLUDE) $(FLAGS) -Imlx -c $? -o $@

clean:
	$(RM) $(B_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)
	make fclean -C $(LIBFT_DIR)

re : fclean all
