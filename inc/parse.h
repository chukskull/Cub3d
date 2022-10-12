/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:09:34 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/12 19:14:55 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

# include "cub3d.h"
# include "get_next_line.h"

typedef struct s_state {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	int		floor_color;
	int		ceiling_color;

	int		map_width;
	int		map_height;
	int		**map;

	char	player_angle; // N, S, E, W
}	t_state;

t_state	*ft_parse(int ac, char **av);
void	ft_exit_error(char *error, int status);
char	*ft_parse_file(char *filename);
int		ft_extract_textures_colors(char **lines, int lines_count, t_state *state);
char	*ft_get_first_word(char *str);
void	ft_extract_texture(char *line, char *type, t_state *state);
void	ft_fill_state(char *file_content, t_state *state);
void	ft_extract_map(char **file_content, int lines_len, t_state *state);
int		ft_invalid_surroundings(char **file_content, int line_idx, int char_idx);
int		ft_char_is_player(char c);
int		ft_get_map_width(char **file_content, int lines_len);
int		ft_found_player(char *line);
void	ft_fill_map(char **file_content, t_state *state);
void	ft_print_map(t_state *state);
void	ft_free_state(t_state *state);
void	ft_free_null(void **ptr);
char	*ft_get_second_word(char *str);
int		ft_array_len(char **array);
void	ft_free_array(char **array);
int		ft_get_color(char *line);
char	**ft_get_lines(char *file_content);

#endif
