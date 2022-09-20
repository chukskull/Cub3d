#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define SQUARE 800

typedef struct s_player
{
	double	x;
	double	y;
}	t_player;
typedef struct s_data
{
	void		*mlx;
	void		*img;
	void		*win;
	t_player	*player;	
	unsigned int *addr;
} t_data;


void	fill_pixel(t_data *data, int x, int y, int color);
void	draw_square(t_data *data, int x, int y, int color);
void	draw_player(t_data *data, int x, int y, int color);
int		render_for_p(t_data *data);
void    draw_map_p(t_data *data, int init);
int		key_hook(int key, t_data *data);




#endif