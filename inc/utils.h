/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:15:35 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/16 12:15:35 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

unsigned int	*get_no_add(t_data *data);
unsigned int	*get_so_add(t_data *data);
unsigned int	*get_we_add(t_data *data);
unsigned int	*get_ea_add(t_data *data);
int     		get_no_height(t_data *data);
int     		get_so_height(t_data *data);
int     		get_we_height(t_data *data);
int     		get_ea_height(t_data *data);
int				get_no_width(t_data *data);
int				get_so_width(t_data *data);
int				get_we_width(t_data *data);
int				get_ea_width(t_data *data);
char    		*get_north(t_data *data);
char			*get_south(t_data *data);
char			*get_east(t_data *data);
char			*get_west(t_data *data);

#endif