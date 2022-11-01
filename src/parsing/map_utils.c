/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:59 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:16:11 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	invalid_char(char c)
{
	return (c != '0' && c != '1' && c != ' ' && !char_is_player(c));
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
	char	*second_word;

	i = 0;
	words = ft_split(str, ' ');
	if (!words || ft_array_len(words) != 2)
		return (NULL);
	second_word = ft_strdup(words[1]);
	if (!second_word)
		ft_error("Color Error!\n");
	ft_free_array(words);
	return (second_word);
}

char	*ft_get_first_word(char *str)
{
	size_t	word_length;
	char	*first_word;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] == ' ')
		i++;
	word_length = i;
	if (word_length >= ft_strlen(str))
		return (NULL);
	while (str[word_length] && str[word_length] != ' ')
		word_length++;
	first_word = ft_substr(str, i, word_length - i);
	return (first_word);
}
