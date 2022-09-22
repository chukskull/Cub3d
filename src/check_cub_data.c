#include "cub3d.h"

void	check_cub_texture(char **file_cont, int *i)
{
	int	found;

	found = 0;
	while (*i < 4 && file_cont[*i])
	{
		if (ft_strncmp(file_cont[*i], "NO ", 3) == 0
			|| ft_strncmp(file_cont[*i], "SO ", 3) == 0
			|| ft_strncmp(file_cont[*i], "WE ", 3) == 0
			|| ft_strncmp(file_cont[*i], "EA ", 3) == 0)
			found++;
		(*i)++;
	}
	if (found != 4 && *i != found)
		ft_error("Textures error!\n");
	if (*i == 0)
		ft_error("Your .cub file is empty!\n");
}

void	check_cub_colors(char **file_cont, int *i)
{
	int	found;
	int	j;
	int	ex;

	found = 0;
	ex = *i;
	j = *i + 2;
	while (*i < j && file_cont[*i])
	{
		if (ft_strncmp(file_cont[*i], "F ", 2) == 0
			|| ft_strncmp(file_cont[*i], "C ", 2) == 0)
			found++;
		(*i)++;
	}
	if (*i - ex != found && found != 2)
		ft_error("Colors error!\n");
}

void	check_cub_data(char **file_cont)
{
	int	i;

	i = 0;
	check_cub_texture(file_cont, &i);
	while (file_cont[i] && ft_strcmp(file_cont[i], "\n") == 0)
		i++;
	check_cub_colors(file_cont, &i);
	while (file_cont[i] && ft_strcmp(file_cont[i], "\n") == 0)
		i++;
	if (!file_cont[i])
		ft_error("No map found in your .cub file!\n");
}