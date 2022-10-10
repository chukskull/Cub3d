# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:16:18 by olabrahm          #+#    #+#              #
#    Updated: 2022/10/10 15:29:28 by dar_sefriou      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
FLAGS=-Wall -Wextra -Werror
MANDATORY =	ft_isalpha ft_isdigit ft_isalnum ft_isascii \
			ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy \
			ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower \
			ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
			ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
			ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
OBJS=$(MANDATORY:=.o)
NAME=libft.a
AR= ar rc

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $? -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all