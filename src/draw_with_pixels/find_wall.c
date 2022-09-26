#include "cub3d.h"



// double  find_wall_y(int map[18][18], t_data *data)
// {
// 	int	x;
// 	int y;
// 	double	d;
// 	// int		p;
// 	(void)map;
// 	y = data->player->y ;
// 	x = data->player->x;
// 	printf("x ->[%d] y->[%d] \n", x, y);
	

// 	d = 0;
// 	while(1)
// 	{
// 		if (map[y][x] == 1)
// 			return(y);
// 		y += sin(data->player->an);
// 		x -= cos(data->player->an);
// 	}
// 	return(y);
// }

t_player	*find_wall(int map[18][18], t_data *data)
{
	t_player	*horiz;
	t_player	*ver;
	double	distanc_hor;
	double	distanc_ver;

	horiz = find_wall_horiz(map, data);
	ver = find_wall_vert(map, data);

	distanc_hor = sqrt(pow(data->player->x - horiz->dx, 2)
		+ pow(data->player->y - horiz->dy, 2));
	distanc_ver = sqrt(pow(data->player->x - ver->dx, 2) 
		+ pow(data->player->y - ver->dy,2));
	// printf("%f\n", diff_y);
	// if(data->player->an == PI/2)
	// 	return(horiz);
	// printf("cos: %f\n", cos(data->player->an));
	printf("distanc_hor: %f\n", data->player->x);
	printf("distanc_ver: %f\n", distanc_ver);
	// if (cos(data->player->an) >= 0)
	// {
	// 	if (distanc_hor < distanc_ver)
	// 	{
	// 		return(ver);
	// 	}
	// 	else
	// 	{
	// 		return(horiz);
	// 	}
	// }
	// else
	// {
	// 	if (distanc_hor > distanc_ver)
	// 	{
	// 		return(ver);
	// 	}
	// 	else
	// 	{
	// 		return(horiz);
	// 	}
	// }
	// printf("x: %f\ny: %f\n", ver->dx, ver->dy);
	if (distanc_hor < distanc_ver)
	{
		return(horiz);
	}
	return(ver);
}

t_player	*find_wall_horiz(int map[18][18], t_data *data)
{
	int	x;
	int y;
	t_player	*horiz;
	//int	f;

	// int		p;
	(void)map;
	horiz = malloc(sizeof(t_player));
	y = data->player->y;
	x = data->player->x;
	//f = y;
	//float f1 = (y+1);
	if (sin(data->player->an) > 0)
	{
		horiz->dy = -(data->player->y - y);
	}
	else
	{
		horiz->dy = -(data->player->y - (y +1));
	}
	horiz->dx = -(horiz->dy / (tan(data->player->an)));
	horiz->dx += data->player->x;
	horiz->dy += data->player->y;
	return(horiz);
}

t_player	*find_wall_vert(int map[18][18], t_data *data)
{
	int	x;
	int y;
	t_player	*ver;
	//int	f;

	// int		p;
	(void)map;
	ver = malloc(sizeof(t_player));
	y = data->player->y;
	x = data->player->x;
	//f = y;
	//float f1 = (y+1);
	if (cos(data->player->an) > 0)
	{
		ver->dx = -(data->player->x - (x + 1));
	}
	else if (cos(data->player->an) < 0)
	{
		ver->dx = -(data->player->x - x);
	}
	ver->dy = -(ver->dx * (tan(data->player->an)));

	// printf("----------------------\n");
	// printf("dx : %lf\n",data->player->dx);
	// printf("----------------------\n");

	// printf("dy : %lf\n",data->player->dy);
	// printf("----------------------\n");
	ver->dx += data->player->x;
	ver->dy += data->player->y;
	return(ver);
}


	//if (data->player->an > PI /2 && data->player->an <= 3*(PI/2))
		//data->player->dy = data->player->y / (SQUARE/18) * (SQUARE/18);

// double	find_wall_ver_y(int map[18][18], t_data *data)
// {
// 	int	x;
// 	int	y;
// 	float	dx;
// 	float	dy;
// 	// int	f1;
// 	float	f;
// 	(void)map;
// 	x = data->player->x;
// 	y = data->player->y;
// 	f = (x) * (SQUARE/18);
// 	dx = data->player->x * (SQUARE/18)- ((data->player->x * (SQUARE/18)) - f);
// 	dy = (data->player->y * (SQUARE/18)) + tan(data->player->an) * dx;
// 	printf("%f le zigrad\n", dy );
// 	printf("%f le ziks\n", dx );
// 	return(dy);
// }


// double	find_wall_ver(int map[18][18], t_data *data)
// {
// 	int	x;
// 	int	y;
// 	float	dx;
// 	// int	f1;
// 	float	f;
// 	(void)map;
// 	x = data->player->x;
// 	y = data->player->y;
// 	f = (x + 1) * (SQUARE/18);
// 	dx = data->player->x * (SQUARE/18)- ((data->player->x * (SQUARE/18)) - f);

// 	return(dx);
// }