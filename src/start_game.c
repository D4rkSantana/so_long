/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:35:27 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 21:00:14 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	set_map(t_map *map, char *patch)
{
	map->patch = patch;
	map->w = 0;
	map->h = 0;
	map->character = 0;
	map->items = 0;
	map->exit = 0;
	if (read_map(map))
		return (1);
	return (0);
}

static int	set_mlx(t_data *data)
{
	int	w;
	int	h;

	w = (data->map.w * 50) + 50;
	h = data->map.h * 50;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, w, h, "so_long");
	if (data->win == NULL)
		return (1);
	data->image.ptr = mlx_new_image(data->mlx, w, h);
	if (data->image.ptr == NULL)
		return (1);
	else
		data->image.addr = mlx_get_data_addr(data->image.ptr, &data->image.bpp,
				&data->image.line_len, &data->image.endian);
	return (0);
}

static int	set_images(t_data *data)
{
	if (set_sprites(data, &data->sprite, &data->character))
	{
		error_mensage(3, 0);
		return (1);
	}
	return (0);
}

int	start_game(t_data *data, char *patch)
{
	if (set_map(&data->map, patch))
		return (1);
	if (set_mlx(data))
	{
		error_mensage(4, 0);
		return (1);
	}
	if (set_images(data))
		return (1);
	return (0);
}
