/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:40:55 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/16 12:42:02 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "cub3d.h"

typedef struct s_text_no
{
	unsigned int	*addr_north;
	void			*img_north;
	int				no_width;
	int				no_height;
}	t_text_no;

typedef struct s_text_so
{
	unsigned int	*addr_south;
	void			*img_south;
	int				so_width;
	int				so_height;
}	t_text_so;

typedef struct s_text_we
{
	unsigned int	*addr_west;
	void			*img_west;
	int				we_width;
	int				we_height;
}	t_text_we;

typedef struct s_text_ea
{
	unsigned int	*addr_east;
	void			*img_east;
	int				ea_width;
	int				ea_height;
}	t_text_ea;

typedef struct s_texture
{
	t_text_no	*text_no;
	t_text_so	*text_so;
	t_text_we	*text_we;
	t_text_ea	*text_ea;

}	t_texture;

int	get_no_height(t_data *data);

#endif
