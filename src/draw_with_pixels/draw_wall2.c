/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:10:13 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:10:14 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_texture_no(t_data *data, t_player *delta, t_tex *tex)
{
	int	xox;
	int	pos_wallstr;

	if (delta->zone == 1)
	{
		pos_wallstr = delta->dx * tex->wdt_no;
		xox = pos_wallstr % tex->wdt_no;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_no,
				tex->wdt_no, tex->addr_no));
	}
	else
	{
		pos_wallstr = delta->dy * tex->wdt_no;
		xox = pos_wallstr % tex->wdt_no;
		if (tex->y_no == data->texture->ea_height)
			tex->y_no = data->texture->ea_height - 1;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_no,
				tex->wdt_no, tex->addr_no));
	}
}

void	ft_texture_so(t_data *data, t_player *delta, t_tex *tex)
{
	int	xox;
	int	pos_wallstr;

	if (delta->zone == 1)
	{
		pos_wallstr = delta->dx * tex->wdt_so;
		xox = pos_wallstr % tex->wdt_so;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_so,
				tex->wdt_so, tex->addr_so));
	}
	else
	{
		pos_wallstr = delta->dy * tex->wdt_so;
		xox = pos_wallstr % tex->wdt_so;
		if (tex->y_so == data->texture->ea_height)
			tex->y_so = data->texture->ea_height - 1;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_so,
				tex->wdt_so, tex->addr_so));
	}
}

void	ft_texture_ea(t_data *data, t_player *delta, t_tex *tex)
{
	int	xox;
	int	pos_wallstr;

	if (delta->zone == 1)
	{
		pos_wallstr = delta->dx * tex->wdt_ea;
		xox = pos_wallstr % tex->wdt_ea;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_ea,
				tex->wdt_ea, tex->addr_ea));
	}
	else
	{
		pos_wallstr = delta->dy * tex->wdt_ea;
		xox = pos_wallstr % tex->wdt_ea;
		if (tex->y_ea == data->texture->ea_height)
			tex->y_ea = data->texture->ea_height - 1;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_ea,
				tex->wdt_ea, tex->addr_ea));
	}
}

void	ft_texture_we(t_data *data, t_player *delta, t_tex *tex)
{
	int	xox;
	int	pos_wallstr;

	if (delta->zone == 1)
	{
		pos_wallstr = delta->dx * tex->wdt_we;
		xox = pos_wallstr % tex->wdt_we;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_we,
				tex->wdt_we, tex->addr_we));
	}
	else
	{
		pos_wallstr = delta->dy * tex->wdt_we;
		xox = pos_wallstr % tex->wdt_we;
		if (tex->y_we == data->texture->ea_height)
			tex->y_we = data->texture->ea_height - 1;
		fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_we,
				tex->wdt_we, tex->addr_we));
	}
}
