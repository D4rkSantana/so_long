/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:39:25 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 21:28:37 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	close_game(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		error_mensage(2, 0);
		return (0);
	}
	init_data(&data);
	if (start_game(&data, argv[1]))
	{
		destroy(&data);
		return (0);
	}
	mlx_loop_hook(data.mlx, &no_event, &data);
	mlx_key_hook(data.win, &event, &data);
	mlx_hook(data.win, 33, (1L << 5), &close_game, &data);
	mlx_loop(data.mlx);
	destroy(&data);
	return (0);
}
