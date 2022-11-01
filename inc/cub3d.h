/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:01:20 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:01:21 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "parsing.h"

# define BUFFER_SIZE 100
# define HEIGHT 700
# define WIDTH 1200
# define PI 3.14159265
# define DEGREE 0.0174533
# define A 0
# define W 13
# define S 1
# define D 2
# define SQUARE_M 200
# define LEFT 124

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

typedef struct s_texture
{
	char			*dire;
	int				height;
	int				width;
	unsigned int	*addr_south;
	unsigned int	*addr_west;
	unsigned int	*addr_east;
	unsigned int	*addr_north;
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
}	t_texture;

typedef struct s_wall
{
	double	wall_h;
	int		top_y;
	int		bottom_y;
}	t_wall;
typedef struct s_rel
{
	int	tour_right;
	int	tour_left;
	int	left;
	int	right;
	int	up;
	int	down;
	int	flag;
}	t_rel;
typedef struct s_tex
{
	int				tab[2];
	int				y_so;
	int				y_no;
	int				y_we;
	int				y_ea;
	int				wdt_no;
	int				wdt_so;
	int				wdt_we;
	int				wdt_ea;
	unsigned int	*addr_no;
	unsigned int	*addr_so;
	unsigned int	*addr_we;
	unsigned int	*addr_ea;
}	t_tex;

typedef struct s_data
{
	int				usls;
	unsigned int	*addr;
	void			*mlx;
	void			*img;
	void			*win;
	t_wall			*wall;
	t_player		*player;
	t_map			*map;
	t_texture		*texture;
	t_rel			button;
}	t_data;

typedef struct s_ray
{
	double	an;
	double	x;
	int		y;
}	t_ray;

int			grab_pixel(int x, int y, int width, unsigned int *addr);
void		fill_pixel(t_data *data, int x, int y, int color);
int			render_for_p(t_data *data);
void		draw_map_p(t_data *data, int init, int r, int c);
int			key_hook(t_data *data);
t_player	find_wall_horiz(int **map, t_data *data, double ray_angle);
t_player	find_wall_vert(int **map, t_data *data, double ray_angle);
t_player	find_wall(int **map, t_data *data, double ray_angle);
void		draw_everything(t_data *data, int **map);
void		draw_walls(t_player delta, t_data *data, t_ray *ray);
void		ft_texture_no(t_data *data, t_player *delta, t_tex *tex);
void		ft_texture_so(t_data *data, t_player *delta, t_tex *tex);
void		ft_texture_ea(t_data *data, t_player *delta, t_tex *tex);
void		ft_texture_we(t_data *data, t_player *delta, t_tex *tex);
double		g_player_y(t_data *data);
double		g_player_x(t_data *data);
double		g_player_dx(t_data *data);
double		g_player_dy(t_data *data);

#endif
