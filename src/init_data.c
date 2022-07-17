/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 04:22:49 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:49 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	init_character(t_data *data)
{
	data->character.direction = 'P';
	data->character.itens = 0;
	data->character.count = 0;
	data->character.x = 0;
	data->character.y = 0;
	data->character.character_e.ptr = NULL;
	data->character.character_e.addr = NULL;
	data->character.character_s.ptr = NULL;
	data->character.character_s.addr = NULL;
	data->character.character_n.ptr = NULL;
	data->character.character_n.addr = NULL;
	data->character.character_w.ptr = NULL;
	data->character.character_w.addr = NULL;
}

static void	init_sprites(t_data *data)
{
	data->sprite.bg0.ptr = NULL;
	data->sprite.bg0.addr = NULL;
	data->sprite.bg1.ptr = NULL;
	data->sprite.bg1.addr = NULL;
	data->sprite.item.ptr = NULL;
	data->sprite.item.addr = NULL;
	data->sprite.exit.ptr = NULL;
	data->sprite.exit.addr = NULL;
	data->sprite.iu.ptr = NULL;
	data->sprite.iu.addr = NULL;
}

static void	init_numbers(t_data *data)
{
	data->numbers.n0.ptr = NULL;
	data->numbers.n1.ptr = NULL;
	data->numbers.n2.ptr = NULL;
	data->numbers.n3.ptr = NULL;
	data->numbers.n4.ptr = NULL;
	data->numbers.n5.ptr = NULL;
	data->numbers.n6.ptr = NULL;
	data->numbers.n7.ptr = NULL;
	data->numbers.n8.ptr = NULL;
	data->numbers.n9.ptr = NULL;
	data->numbers.n0.addr = NULL;
	data->numbers.n1.addr = NULL;
	data->numbers.n2.addr = NULL;
	data->numbers.n3.addr = NULL;
	data->numbers.n4.addr = NULL;
	data->numbers.n5.addr = NULL;
	data->numbers.n6.addr = NULL;
	data->numbers.n7.addr = NULL;
	data->numbers.n8.addr = NULL;
	data->numbers.n9.addr = NULL;
}

void	init_data(t_data *data)
{
	data->map.save = NULL;
	data->map.patch = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->image.ptr = NULL;
	data->image.addr = NULL;
	init_sprites(data);
	init_numbers(data);
	init_character(data);
}
