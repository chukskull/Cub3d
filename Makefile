CC= cc

FLAGS= -Wall -Wextra -Werror

FILES= cub3d fill_buffer_by_pixels check_extension ft_error ft_strlen ft_strdup gnl get_cub_data check_cub_data ft_strncmp ft_strcmp

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
