/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:29:43 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:29 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	check_dimensions(char *char_map)
{
	int	index;
	int	size_line1;
	int	size_line2;

	index = 0;
	size_line1 = 0;
	size_line2 = 0;
	while (char_map[index] != '\0')
	{
		if (char_map[index] == '\n')
		{
			if (size_line1 == 0)
				size_line1 = size_line2;
			if (size_line1 != size_line2)
				return (1);
			if (char_map[index + 1] == '\0')
				break ;
			if (size_line1 != 0)
				size_line2 = 0;
		}
		else
			size_line2++;
		index++;
	}
	return (0);
}

static void	check_brick(char brick, t_map *map)
{
	if (brick == 67)
		map->items += 1;
	else if (brick == 69)
		map->exit += 1;
	else if (brick == 80)
		map->character += 1;
}

static int	bord_check(char *char_map, t_map *map)
{
	int		index;
	int		count_x;
	int		count_y;

	index = 0;
	count_x = 0;
	count_y = 0;
	while (char_map[index] != '\0')
	{
		if ((count_y == 0 || count_y == (map->h - 1))
			&& char_map[index] != 49 && char_map[index] != '\n')
			return (1);
		else if ((count_x == 0 || count_x == map->w) && char_map[index] != 49)
			return (1);
		if (char_map[index] == '\n')
		{
			count_y += 1;
			count_x = 0;
		}
		else
			count_x++;
		index++;
	}
	return (0);
}

static int	check_amount(t_map *map)
{
	int		index;

	index = 0;
	while (map->save[index] != '\0')
	{
		check_brick(map->save[index], map);
		index++;
	}
	if (map->character != 1)
		return (5);
	else if (map->items < 1)
		return (6);
	else if (map->exit < 1)
		return (7);
	return (0);
}

int	check_map(char *char_map, t_map *map)
{
	int		index;
	int		error_check;

	index = 0;
	while (char_map[index] != '\0')
	{
		if (char_map[index] == '\n')
		{	
			if (map->w == 0)
				map->w = index - 1;
			map->h++;
		}
		index++;
	}
	if (check_dimensions(char_map))
		return (3);
	if (bord_check(char_map, map))
		return (4);
	error_check = check_amount(map);
	if (error_check)
		return (error_check);
	return (0);
}
