CC= cc

FLAGS= -Wall -Wextra -Werror

FILES= cub3d draw_with_pixels/fill_buffer_by_pixels draw_with_pixels/draw draw_with_pixels/render_for_player\
draw_with_pixels/find_wall utils/get_infos draw_with_pixels/texture draw_with_pixels/draw_evertn draw_with_pixels/draw_walls \
parsing/ft_exit_error parsing/ft_parse

B_DIR=build

NAME=cub3d

LIBFT_DIR=libft

INCLUDE= -I./inc -I./libft

.PHONY = all re clean fclean

RM=rm -rf

OBJ=$(addprefix $(B_DIR)/, $(FILES:=.o))

all : $(NAME)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT_DIR)/libft.a
	$(CC) $(OBJ)  -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_DIR)/libft.a


$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC)  $(INCLUDE) $(FLAGS) -Imlx -c $? -o $@

clean:
	$(RM) $(B_DIR)

fclean: clean
	$(RM) $(NAME)

re : fclean all
