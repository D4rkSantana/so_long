/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:04:41 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:52 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	put_numbers_img(t_data *data, int number, int x)
{
	if (number == 0)
		sprite_to_img(&data->numbers.n0, &data->image, x, 15);
	if (number == 1)
		sprite_to_img(&data->numbers.n1, &data->image, x, 15);
	if (number == 2)
		sprite_to_img(&data->numbers.n2, &data->image, x, 15);
	if (number == 3)
		sprite_to_img(&data->numbers.n3, &data->image, x, 15);
	if (number == 4)
		sprite_to_img(&data->numbers.n4, &data->image, x, 15);
	if (number == 5)
		sprite_to_img(&data->numbers.n5, &data->image, x, 15);
	if (number == 6)
		sprite_to_img(&data->numbers.n6, &data->image, x, 15);
	if (number == 7)
		sprite_to_img(&data->numbers.n7, &data->image, x, 15);
	if (number == 8)
		sprite_to_img(&data->numbers.n8, &data->image, x, 15);
	if (number == 9)
		sprite_to_img(&data->numbers.n9, &data->image, x, 15);
}

void	render_item_count(t_data *data)
{
	int		cent;
	int		dez;
	int		unit;
	int		temp;

	sprite_to_img(&data->sprite.iu, &data->image, 0, 0);
	cent = data->character.itens / 100;
	temp = data->character.itens % 100;
	dez = temp / 10;
	unit = temp % 10;
	put_numbers_img(data, cent, 22);
	put_numbers_img(data, dez, 40);
	put_numbers_img(data, unit, 60);
}
