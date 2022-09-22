#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define SQUARE 500

# define FLOOR "F"
# define CEILLING "C"

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_vector
{
	int x;
	int	y;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char		**map;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	char		*file;
	char		start_pos;
	t_color		floor_clr;
	t_color		ceilling_clr;
	t_vector	player;
}	t_map;

typedef struct s_data
{
	void 			*mlx;
	void 			*img;
	void 			*win;
	char			**file_cont;
	unsigned int	*addr;
	t_map			map;
}	t_data;

void	fill_pixel(t_data *data, int x, int y, int color);
void	ft_error(char* err);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*gnl(int fd);
int		get_len(char *file);
void	get_cub_data(t_data *p);
void	check_extension(char **av);
void	check_cub_data(char **file_cont);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
void	init_map(t_map *map);
void	init_color(t_color *color);


#endif