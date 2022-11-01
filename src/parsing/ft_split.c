/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:07 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:12:08 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	output;
	size_t	i;
	int		flag;

	output = 0;
	flag = 1;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (flag && s[i] != c)
		{
			output++;
			flag = 0;
		}
		if (!flag && s[i] == c)
			flag = 1;
		i++;
	}
	return (output);
}

static char	*ft_strndup(char *str, size_t len)
{
	size_t	i;
	char	*dupped;

	i = 0;
	dupped = (char *) malloc((len + 1) * sizeof(char));
	if (!dupped)
		return (0);
	while (i < len)
	{
		dupped[i] = str[i];
		i++;
	}
	dupped[i] = 0;
	return (dupped);
}

static char	*ft_get_next_word(char const *s, size_t *i, char c)
{
	size_t	k;
	char	*word;

	k = 0;
	while (s[(*i)] == c)
		(*i)++;
	while (s[(*i) + k] != c && s[(*i) + k])
		k++;
	word = ft_strndup((char *)(s + (*i)), k);
	if (!word)
		return (0);
	(*i) += k;
	return (word);
}

static void	ft_free_all(char **array, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(array[i++]);
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	wc;
	size_t	i;
	char	**splited;

	if (!s)
		return (0);
	wc = -1;
	i = 0;
	word_count = ft_word_count(s, c);
	splited = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!splited)
		return (0);
	while (++wc < word_count)
	{
		splited[wc] = ft_get_next_word(s, &i, c);
		if (!splited[wc])
		{
			if (wc > 0)
				ft_free_all(splited, wc);
			return (0);
		}
	}
	splited[word_count] = 0;
	return (splited);
}
