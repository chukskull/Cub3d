
#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>
# include <math.h>
# include "mlx.h"

# define EQUAL 0

# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32

# define FLOOR "F"
# define CEILLING "C"

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	int			row;
	int			col;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*file_name;
	char		starting_pos;
	t_color		floor_color;
	t_color		ceilling_color;
	t_vector	player;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	int		len;
	int		bpp;
	int		endian;
	int		*arr;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win_ptr;
	char		**file_content;
	t_map		map;
	t_img		img;
	t_img		tex;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		m_speed;
	double		r_angle;
	double		wallx;
	double		tex_pos;
	double		tex_step;
	int			r_right;
	int			m_right;
	int			r_left;
	int			m_left;
	int			m_up;
	int			m_down;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	int			tex_x;
	int			tex_y;
	int			screen_w;
	int			screen_h;
}				t_data;

char	*ft_strndup(char *s1, int n);
int	ft_strncmp(char *s1, char *s2, int n);
char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strdup(char *s1);
int	ft_strcmp(char *s1, char *s2);
char	**ft_split(char *str, char *sap);
void	ft_puterror(char *msg);
char	*ft_itoa(int n);
int	ft_atoi(const char *str);
void	check_cub_content(char **content);
void	init_game(t_data *game);
void	parse_map(t_data *ptr);
int	nbr_of_lines(char *filename);
int	check_extention(char *src, char *to_find);
void	free_split(char **tab);
int	get_map_len(t_data *ptr);
int	check_new_line(char *str);
int	in_charset(char c, char *set);
int	check_wall(char **map, int row, int col);
int	check_extended_wall(char **map, int row);
void	ft_new_window(t_data *game);
int	ft_close(t_data *game);
void	check_map_full(t_map map);
void	check_map(char **map);
void	get_map_textures(t_data *data);
void	get_colors(t_data *ptr);
void	get_map(t_data *ptr);
void	get_player_pos(t_map *map);
void	start_game(t_data *game);


#endif
