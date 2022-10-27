CC= cc

FLAGS= -Wall -Wextra -Werror

FILES=  cub3d parsing/ft_error parsing/gnl parsing/check_extension \
		parsing/get_map parsing/check_utils parsing/ft_strdup parsing/ft_strlen \
		parsing/ft_strjoin parsing/ft_atoi parsing/map_utils2 parsing/parsing_utils \
		parsing/get_texts_colors parsing/colors_utils parsing/get_textures parsing/check_map \
		parsing/map_utils parsing/ft_split parsing/ft_strcmp parsing/ft_substr parsing/parsing

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
