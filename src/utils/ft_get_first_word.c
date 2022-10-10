/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_first_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:09:22 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 17:57:54 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_first_word(char *str)
{
	char	*first_word;
	int		i;
	size_t	word_len;

	i = 0;
	if (!str)
		return NULL;
	while (str[i] && str[i] == ' ')
		i++;
	word_len = i;
	if (word_len >= ft_strlen(str))
		return NULL;
	while (str[word_len] && str[word_len] != ' ')
		word_len++;
	first_word = ft_substr(str, i, word_len - i);
	return (first_word);
}
