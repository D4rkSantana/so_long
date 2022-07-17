/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mensage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:51:33 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 20:59:42 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	error_map(int option)
{
	if (option == 1)
		ft_putstr_fd("map .ber file not found\n", 1);
	if (option == 2)
		ft_putstr_fd("The map contains invalid characters\n", 1);
	if (option == 3)
		ft_putstr_fd("The map is not rectangular\n", 1);
	if (option == 4)
		ft_putstr_fd("The edges of the map must be walls\n", 1);
	if (option == 5)
		ft_putstr_fd("The map must have 1 origin point\n", 1);
	if (option == 6)
		ft_putstr_fd("The map must have at least 1 collectible\n", 1);
	if (option == 7)
		ft_putstr_fd("the map must have at least 1 exit\n", 1);
	if (option == 8)
		ft_putstr_fd("\n", 1);
}

void	error_mensage(int option, int sub_option)
{
	ft_putstr_fd("Error\n", 1);
	if (option == 1)
		error_map(sub_option);
	if (option == 2)
		ft_putstr_fd("invalid number of arguments\n", 1);
	if (option == 3)
		ft_putstr_fd("Error loading texture\n", 1);
	if (option == 4)
		ft_putstr_fd("Error loading MLX\n", 1);
}
