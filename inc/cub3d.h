
#ifndef CUB3D_H
#define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define SQUARE 800
# define PI 3.14159265
# define DEGREE 0.0174533
# define A 0
# define W 13
# define S 1
# define D 2
 
typedef struct s_player
{
	double	dx;
	double	dy;
	double	an;
	double	x;
	double	y;
	int		flag;
}	t_player;
typedef struct s_data
{
	void		*mlx;
	void		*img;
	void		*win;
	t_player	*player;	
	unsigned int *addr;
} t_data;


void		fill_pixel(t_data *data, int x, int y, int color);
void		draw_square(t_data *data, int x, int y, int color);
void		draw_player(t_data *data, int x, int y, int color);
int			render_for_p(t_data *data);
void   		draw_map_p(t_data *data, int init);
int			key_hook(int key, t_data *data);
void   		draw_line(t_data *data, double Bx, double By, double Ex, double Ey);
t_player	*find_wall_horiz(int map[18][18], t_data *data,  double ray_angle);
t_player	*find_wall_vert(int map[18][18], t_data *data,  double ray_angle);
t_player	*find_wall(int map[18][18], t_data *data, double ray_angle);


//// utils
double  g_player_y(t_data *data);
double  g_player_x(t_data *data);
double  g_player_dx(t_data *data);
double  g_player_dy(t_data *data);








#endif