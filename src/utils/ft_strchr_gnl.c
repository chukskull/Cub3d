/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:07:27 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 16:07:28 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strchr_gnl(const char *s, int c)
{
	char	to_find;
	int		i;

	i = 0;
	to_find = (char) c;
	while (s[i])
	{
		if (s[i] == to_find)
			return (i);
		i++;
	}
	if (s[i] == to_find)
		return (i);
	return (-1);
}