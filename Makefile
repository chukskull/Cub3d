CC= cc

FLAGS= -Wall -Wextra -Werror

FILES=  cub3d parsing check_wall check_map parsing_utils get_data check_map2 ft_atoi ft_itoa ft_error ft_split ft_strncmp ft_strcmp ft_strdup ft_strlen ft_strndup gnl

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
