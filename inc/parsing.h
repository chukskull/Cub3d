/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:01:29 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:01:30 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 100
# define WALL 1
# define PLAYER 2
# define EMPTY 0
# define NO_VALUE -1

typedef struct s_map {
	int		ceiling_color;
	int		floor_color;

	int		**map;
	int		map_w;
	int		map_h;

	char	*north_texture;
	char	*west_texture;
	char	*south_texture;
	char	*east_texture;

	char	player_ang;
}	t_map;

int		check_extension(char *src, char *to_find);
char	*first_line(char **content_ptr);
char	*another_line(char **content_ptr, char *line);
char	*gnl(int fd);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_free(char **ptr);
void	ft_error(char *error);
t_map	*parsing(char *argv);
char	*ft_strncpy(char *dst, char *src, int n);
char	*get_map_data(char *file);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr_gnl(const char *s, int c);
void	check_newlines(char *map_content);
void	ft_skip_map(char *map_content, int *i);
void	skip_txts_clrs(char *map_content, int *i, int *lines);
int		is_color_or_texture(char *line);
char	*ft_get_line(char *map_content);
void	ft_parse_map(char *map_content, t_map *map);
void	init_map(t_map *map);
char	**ft_split(char const *s, char c);
char	*ft_get_first_word(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		get_texts_colors(char **lines, int nbr_lines, t_map *map);
void	pars_get_textures(char *line, char *type, t_map *map);
int		handle_color(char *line);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_free_array(char **array);
char	*ft_get_first_word(char *str);
char	*ft_get_second_word(char *str);
int		ft_array_len(char **array);
int		map_width(char **map_content, int nbr_lines);
int		player_found(char *line);
void	ft_fill_map(char **map_content, t_map *map);
int		invalid_char(char c);
int		invalid_surroundings(char **map_content, int i, int j);
int		char_is_player(char c);
void	get_map(char **map_content, int nbr_lines, t_map *map);
void	*ft_memset(void *b, int c, size_t len);
int		ft_exit(void);

#endif
