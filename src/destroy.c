/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:42:53 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:39 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	destroy_img(t_data *data, t_img *img)
{
	if (img->ptr != NULL)
		mlx_destroy_image(data->mlx, img->ptr);
}

static void	destroy_numbers(t_data *data)
{
	destroy_img(data, &data->numbers.n0);
	destroy_img(data, &data->numbers.n1);
	destroy_img(data, &data->numbers.n2);
	destroy_img(data, &data->numbers.n3);
	destroy_img(data, &data->numbers.n4);
	destroy_img(data, &data->numbers.n5);
	destroy_img(data, &data->numbers.n6);
	destroy_img(data, &data->numbers.n7);
	destroy_img(data, &data->numbers.n8);
	destroy_img(data, &data->numbers.n9);
}

static void	destroy_all_images(t_data *data)
{
	destroy_img(data, &data->image);
	destroy_img(data, &data->sprite.bg0);
	destroy_img(data, &data->sprite.bg1);
	destroy_img(data, &data->sprite.item);
	destroy_img(data, &data->sprite.exit);
	destroy_img(data, &data->sprite.iu);
	destroy_img(data, &data->character.character_e);
	destroy_img(data, &data->character.character_n);
	destroy_img(data, &data->character.character_w);
	destroy_img(data, &data->character.character_s);
}

void	destroy(t_data *data)
{
	ft_strdel(&data->map.save);
	destroy_all_images(data);
	destroy_numbers(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
