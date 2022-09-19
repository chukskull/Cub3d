CC= cc

FLAGS= -Wall -Wextra -Werror

FILES= cub3d draw_with_pixels/fill_buffer_by_pixels draw_with_pixels/draw

B_DIR=build

NAME=cub3d

INCLUDE= -I./inc

.PHONY = all re clean fclean

RM=rm -rf

OBJ=$(addprefix $(B_DIR)/, $(FILES:=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ)  -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(B_DIR)/%.o:src/%.c
	mkdir -p $(@D)
	$(CC)  $(INCLUDE) $(FLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(B_DIR)

fclean: clean
	$(RM) $(NAME)

re : fclean all
