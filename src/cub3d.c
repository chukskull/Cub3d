#include "cub3d.h"

void	ft_free(t_data *game, char *msg)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	free(game->map.file_name);
	mlx_destroy_window(game->mlx, game->win_ptr);
	printf("%s\n", msg);
	exit(EXIT_SUCCESS);
}

int	ft_close(t_data *game)
{
	ft_free(game, "WINDOW CLOSED");
	return (0);
}

void	ft_new_window(t_data *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->screen_w, game->screen_h, \
		"cub3D");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}

int	main(int ac, char **av)
{
	t_data	data_p;

	if (ac != 2)
		ft_puterror("Usage: ./cub3D ./path_to_map\n");
	init_game(&data_p);
	data_p.map.file_name = ft_strdup(av[1]);
	parse_map(&data_p);
	return (0);
}
