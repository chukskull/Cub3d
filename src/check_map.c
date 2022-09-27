#include "cub3d.h"

int	check_player_surr(char **map, int row, int col)
{
	if (map[row][col + 1] == ' ' || map[row][col - 1] == ' '
		|| map[row + 1][col] == ' ' || map[row - 1][col] == ' ')
		ft_error("Invalid map\n");
	return (EXIT_SUCCESS);
}

void	check_map(char **map)
{
	int	row;
	int	col;
	int	player;

	row = 0;
	player = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!char_inset(map[row][col], " 01NSEW"))
				ft_error("Invalid character in map!\n");
			if (char_inset(map[row][col], "NSEW")
				&& !check_player_surr(map, row, col))
				player++;
			col++;
		}
		row++;
	}
	if (!player)
		ft_error("The player's not found!\n");
	else if (player > 1)
		ft_error("This is not a multiplayer game..\n");
}

void	check_plus(t_map map, int row, int col)
{
	if ((row == 0 && check_wall(map.map, row, col))
		|| (row == map.row - 1 && check_wall(map.map, row, col)))
		ft_error("Invalid map!\n");
	else if (col == 0 && check_wall(map.map, row, col))
		ft_error("Invalid map!\n");
	else if (col == ft_strlen(map.map[row]) - 1
		&& check_wall(map.map, row, col))
		ft_error("Invalid map!\n");
	else if ((row > 0 && row < map.row - 1)
		&& (col > 0 && col < ft_strlen(map.map[row]) - 1))
	{
		if (map.map[row][col] == '0'
			&& (map.map[row + 1][col] == ' ' || map.map[row - 1][col] == ' '
			|| map.map[row][col + 1] == ' ' || map.map[row][col - 1] == ' '))
			ft_error("Invalid map!\n");
	}
}

void	check_map2(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (map.map[row])
	{
		col = 0;
		if (check__wall(map.map, row))
			ft_error("Invalid map!\n");
		while (map.map[row][col])
		{
			check_plus(map, row, col);
			col++;
		}
		row++;
	}
}
