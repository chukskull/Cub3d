/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_second_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:23:15 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/13 13:18:15 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	char	*second_word;

	i = 0;
	words = ft_split(str, ' ');
	if (!words || ft_array_len(words) != 2)
		return (NULL);
	second_word = ft_strdup(words[1]);
	if (!second_word)
		ft_exit_error("Error", EXIT_FAILURE);
	ft_free_array(words);
	return (second_word);
}
