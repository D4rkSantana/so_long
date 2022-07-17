/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:54:55 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 21:00:09 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	load_xpm(void *mlx, t_img *img, char *patch)
{
	img->ptr = mlx_xpm_file_to_image(mlx, patch, &img->w, &img->h);
	if (img->ptr == NULL)
		return (1);
	else
		img->addr = mlx_get_data_addr(img->ptr,
				&img->bpp, &img->line_len, &img->endian);
	return (0);
}

static int	load_numbers(t_data *data, t_numbers *numbers)
{
	if (load_xpm(data->mlx, &numbers->n0, "./texture/0.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n1, "./texture/1.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n2, "./texture/2.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n3, "./texture/3.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n4, "./texture/4.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n5, "./texture/5.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n6, "./texture/6.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n7, "./texture/7.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n8, "./texture/8.xpm"))
		return (1);
	if (load_xpm(data->mlx, &numbers->n9, "./texture/9.xpm"))
		return (1);
	return (0);
}

static int	load_sprites(t_data *data, t_sprites *sprite, t_character *chara)
{
	if (load_xpm(data->mlx, &sprite->iu, "./texture/iu.xpm"))
		return (1);
	if (load_xpm(data->mlx, &sprite->bg0, "./texture/bg0.xpm"))
		return (1);
	if (load_xpm(data->mlx, &sprite->bg1, "./texture/bg1.xpm"))
		return (1);
	if (load_xpm(data->mlx, &sprite->item, "./texture/item.xpm"))
		return (1);
	if (load_xpm(data->mlx, &sprite->exit, "./texture/exit.xpm"))
		return (1);
	if (load_xpm(data->mlx, &chara->character_e, "./texture/char_e.xpm"))
		return (1);
	if (load_xpm(data->mlx, &chara->character_n, "./texture/char_n.xpm"))
		return (1);
	if (load_xpm(data->mlx, &chara->character_s, "./texture/char_s.xpm"))
		return (1);
	if (load_xpm(data->mlx, &chara->character_w, "./texture/char_w.xpm"))
		return (1);
	return (0);
}

int	set_sprites(t_data *data, t_sprites *sprite, t_character *character)
{
	if (load_sprites(data, sprite, character))
		return (1);
	if (load_numbers(data, &data->numbers))
		return (1);
	return (0);
}
