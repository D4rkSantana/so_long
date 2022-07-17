/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:33:13 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:46 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	calcule_moviment(t_data *data, int x, int y)
{
	int		bloco;

	if (x == 0)
		bloco = collision(&data->map, data->character.x, y);
	else
		bloco = collision(&data->map, x, data->character.y);
	if (bloco == 49)
		return ;
	else
	{
		data->character.count += 1;
		ft_putstr_fd("Passos dados: ", 1);
		ft_putnbr_fd(data->character.count, 1);
		ft_putchar_fd(10, 1);
		if (bloco == 67)
			data->character.itens += 1;
		else if (bloco == 69 && (data->character.itens == data->map.items))
			mlx_loop_end(data->mlx);
		if (x == 0)
			data->character.y = y;
		else
			data->character.x = x;
	}
}

static void	moviment_keys(t_data *data, int key)
{
	if (key == 97)
	{
		data->character.direction = 65;
		calcule_moviment(data, data->character.x - 50, 0);
	}
	if (key == 115)
	{
		data->character.direction = 83;
		calcule_moviment(data, 0, data->character.y + 50);
	}
	if (key == 119)
	{
		data->character.direction = 87;
		calcule_moviment(data, 0, data->character.y - 50);
	}
	if (key == 100)
	{
		data->character.direction = 68;
		calcule_moviment(data, data->character.x + 50, 0);
	}
}

int	event(int key, t_data *data)
{
	if (key == 65307)
		mlx_loop_end(data->mlx);
	if (key == 100 || key == 97 || key == 115 || key == 119)
		moviment_keys(data, key);
	return (0);
}

int	no_event(t_data *data)
{
	int		x;
	int		y;

	x = data->character.x;
	y = data->character.y;
	render_map(data, &data->map);
	render_character(data, data->character.direction, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->image.ptr, 0, 0);
	return (0);
}
