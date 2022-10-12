/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_second_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:23:15 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 15:29:02 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_all_but_index(char **array, int index)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (i != index)
			ft_free_null((void **) &array[i]);
		i++;
	}
	ft_free_null((void **) array);
}

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*ft_get_second_word(char *str)
{
	int		i;
	char	**words;

	i = 0;
	words = ft_split(str, ' ');
	if (!words || ft_array_len(words) != 2)
		return (NULL);
	ft_free_all_but_index(words, 1);
	return (words[1]);
}
