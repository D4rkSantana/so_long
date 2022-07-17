/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:58:29 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:59 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	check_line(char *line)
{
	int	index;
	int	size;

	index = 0;
	size = ft_strlen(line);
	while (index < size)
	{
		if (!(line[index] == 48 || line[index] == 49 || line[index] == 67
				|| line[index] == 69 || line[index] == 80))
			return (1);
		index++;
	}
	return (0);
}

static int	verifique_map(char *patch)
{
	int		size;
	int		error;

	error = 0;
	size = ft_strlen(patch);
	if (patch[size - 1] != 114)
		error = 1;
	if (patch[size - 2] != 101)
		error = 1;
	if (patch[size - 3] != 98)
		error = 1;
	if (patch[size - 4] != 46)
		error = 1;
	if (error)
	{
		error_mensage(1, 1);
		return (1);
	}
	return (0);
}

static int	open_map(char *patch, int *fd)
{
	if (verifique_map(patch))
		return (1);
	*fd = open(patch, O_RDONLY);
	if (*fd == -1)
	{
		error_mensage(1, 1);
		return (1);
	}
	return (0);
}

static int	load_map(int fd, t_map *map)
{
	int		count;
	int		error;
	char	*line;

	error = 0;
	count = 1;
	while (count)
	{
		count = ft_get_next_line(fd, &line);
		if (check_line(line) || error)
			error = 1;
		else
		{
			if (map->save == NULL)
				map->save = ft_strdup(line);
			else
				map->save = ft_strjoin_free2(map->save, line, ft_strlen(line));
			map->save = ft_strjoin_free2(map->save, "\n", 1);
		}
		ft_strdel(&line);
	}
	if (!error)
		map->save = ft_strjoin_free2(map->save, "\0", 1);
	return (error);
}

int	read_map(t_map *map)
{
	int		fd;
	int		error_check;

	if (open_map(map->patch, &fd))
		return (1);
	if (load_map(fd, map))
	{
		close(fd);
		error_mensage(1, 2);
		return (1);
	}
	close(fd);
	error_check = check_map(map->save, map);
	if (error_check > 0)
	{
		error_mensage(1, error_check);
		return (1);
	}
	return (0);
}
