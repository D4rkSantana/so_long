/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:54:50 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 21:00:05 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	render_map(t_data *data, t_map *map)
{
	int		count;
	int		x;
	int		y;
	char	char_temp;

	count = 0;
	x = 0;
	y = 0;
	char_temp = map->save[count];
	while (char_temp != '\0')
	{
		if (render_loop(data, char_temp, &x, &y))
			map->save[count] = (char)48;
		count++;
		char_temp = map->save[count];
	}
	render_item_count(data);
}
