/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:54:34 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:35 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	colision_check(t_cord *cord, char brick)
{
	if (cord->x == cord->c_x && cord->y == cord->c_y)
	{
		if (brick == 49)
			return (49);
		if (brick == 67)
			return (67);
		if (brick == 69)
			return (69);
	}
	cord->c_x += 50;
	if (brick == '\n')
	{
		cord->c_y += 50;
		cord->c_x = 0;
	}
	return (0);
}

int	collision(t_map *map, int x, int y)
{
	int		index;
	char	*temp;
	t_cord	cord;
	int		result_collision;

	cord.c_x = 0;
	cord.c_y = 0;
	cord.x = x;
	cord.y = y;
	index = 0;
	temp = map->save;
	while (temp[index] != '\0')
	{
		result_collision = colision_check(&cord, temp[index]);
		if (result_collision == 67)
			map->save[index] = (char)48;
		if (result_collision)
			return (result_collision);
		index++;
	}
	return (0);
}
