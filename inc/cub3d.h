
#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "parse.h"

# define BUFFER_SIZE 100
# define HEIGHT 700
# define WIDTH 1200
# define PI 3.14159265
# define DEGREE 0.0174533
# define A 0
# define W 13
# define S 1
# define D 2
# define SIZE (200 / 18)
# define SQUARE_M 200
# define LEFT 124

// int	 **map is filled with these
# define NOTHING -1
# define EMPTY 0
# define WALL 1
# define PLAYER 2

# define RIGHT 123
 
typedef struct s_player
{
	int		zone;
	double	dx;
	double	dy;
	double	an;
	double	x;
	double	y;
	int		flag;
}	t_player;


typedef	struct s_texture
{
	char			*dire;
	int				height;
	int				width;
	unsigned int 	*addr_south;
	unsigned int 	*addr_west;
	unsigned int 	*addr_east;
	unsigned int 	*addr_north;
	void			*img_north;
	void			*img_south;
	void			*img_west;
	void			*img_east;
	int				ea_width;
	int				ea_height;
	int				no_width;
	int				no_height;
	int				west_width;
	int				west_height;
	int				sou_width;
	int				sou_height;
}t_texture;



typedef struct s_data
{
	int			usls;
	unsigned int	*addr;
	void		*mlx;
	void		*img;
	void		*win;
	t_player	*player;	
	t_texture	*texture;
	t_state	*state;
} t_data;

typedef struct s_ray
{
	double	an;
	double	x;
	int		y;
} t_ray;

typedef	struct s_wall
{
	double	wall_h;
	int		top_y;
	int		bottom_y;
} t_wall;


int			test_pixel(int x, int y, int width, unsigned int *addr);
void		fill_pixel(t_data *data, int x, int y, int color);
void		draw_square(t_data *data, int x, int y, int color);
void		draw_player(t_data *data, int x, int y, int color);
int			render_for_p(t_data *data);
void   		draw_map_p(t_data *data, int init);
int			key_hook(int key, t_data *data);
void   		draw_line(t_data *data, double Bx, double By, double Ex, double Ey);
t_player	find_wall_horiz(int map[18][18], t_data *data,  double ray_angle);
t_player	find_wall_vert(int map[18][18], t_data *data,  double ray_angle);
t_player	find_wall(int map[18][18], t_data *data, double ray_angle);
void    	fill_pixel_2(t_data *data, int x, int y, int color);
void    	ft_texture(t_data *wall, int x, int y, t_data *data, t_player delta, int h, int	width, unsigned int *addr);
void		draw_everything(t_data *data, int map[18][18], t_data *wall);
void		draw_walls(t_data *wall,t_player delta,t_data *data, t_ray *ray);
double		scale(double val, double max, double range, double range2);



//// utils
double  g_player_y(t_data *data);
double  g_player_x(t_data *data);
double  g_player_dx(t_data *data);
double  g_player_dy(t_data *data);

#endif