/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:10:49 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:10:50 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_extension(char *src, char *to_find)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(src) - ft_strlen(to_find);
	while ((src[j] && to_find[i])
		&& (src[j++] == to_find[i++]))
		;
	if (j == ft_strlen(src))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
