#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <string.h>

# define WIN_CLOSE 17
# define EQUAL 0
# define FLOOR "F"
# define CEILLING "C"
# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

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
	char		start_position;
	t_color		floor_color;
	t_color		ceilling_color;
	t_vector	player;
}	t_map;


typedef struct s_data
{
	void		*mlx;
	void		*win_ptr;
	char		**file_content;
	t_map		map;
}				t_data;

char	*ft_strndup(char *s1, int n);
int		ft_strncmp(char *s1, char *s2, int n);
char	*gnl(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *str, char *sap);
void	ft_error(char *error);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	check_map_content(char **content);
void	parsing(t_data *ptr);
int		lines_nbr(char *file_name);
int		check_extention(char *src, char *to_find);
void	free_split(char **tab);
int		get_map_len(t_data *ptr);
int		check_new_line(char *str);
int		char_inset(char c, char *set);
void	get_p_pos(t_map *map);
void	get_map(t_data *p);
void	get_colors(t_data *ptr);
void	get_textures(t_data *data);
void	check_map2(t_map map);
void	check_map(char **map);
int		check__wall(char **map, int row);
int		check_wall(char **map, int row, int col);

#endif
