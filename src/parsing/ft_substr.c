/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:26 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:15:05 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *) ptr;
	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

static void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, n * size);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, sizeof(char)));
	if (len >= ft_strlen(s) - start)
		return (ft_strdup(s + start));
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
