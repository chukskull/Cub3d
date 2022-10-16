/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:25:24 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/10 16:25:34 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	j;
	size_t	i;
	size_t	final_len;

	if (!s1 || !s2)
		return (NULL);
	final_len = ft_strlen(s1) + ft_strlen(s2);
	output = (char *) malloc((final_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		output[i++] = s1[j++];
	j = 0;
	while (s2[j])
		output[i++] = s2[j++];
	output[i] = 0;
	free((void *) s1);
	return (output);
}
