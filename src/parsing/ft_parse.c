/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:01:14 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 15:33:31 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_extension(char *filename, char *extension)
{
	int		i;
	int		j;

	i = ft_strlen(filename) - 1;
	j = ft_strlen(extension) - 1;
	while (i >= 0 && j >= 0)
	{
		if (filename[i] != extension[j])
			return (0);
		i--;
		j--;
	}
	if (j >= 0)
		return (0);
	return (1);
}

t_state *ft_parse(int ac, char **av)
{
	t_state	*state = malloc(sizeof(t_state));

    (void) av;
    if (ac < 2)
        return NULL;
    if (!ft_check_extension(av[1], ".cub"))
        return NULL;
    return state;
}
