/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:38:24 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 21:01:59 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_img
{
	char	*addr;
	void	*ptr;
	int		bpp;
	int		line_len;
	int		w;
	int		h;
	int		endian;

}				t_img;

typedef struct s_character{
	t_img	character_w;
	t_img	character_s;
	t_img	character_n;
	t_img	character_e;
	int		x;
	int		y;
	char	direction;
	int		itens;
	int		count;
}				t_character;

typedef struct s_numbers
{
	t_img		n0;
	t_img		n1;
	t_img		n2;
	t_img		n3;
	t_img		n4;
	t_img		n5;
	t_img		n6;
	t_img		n7;
	t_img		n8;
	t_img		n9;
}				t_numbers;

typedef struct s_sprites
{
	t_img		bg0;
	t_img		bg1;
	t_img		item;
	t_img		exit;
	t_img		iu;
}				t_sprites;

typedef struct s_map
{
	char	*patch;
	char	*save;
	int		w;
	int		h;
	int		character;
	int		exit;
	int		items;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_numbers	numbers;
	t_sprites	sprite;
	t_img		image;
	t_character	character;
	t_map		map;
}				t_data;

typedef struct s_cord
{
	int		x;
	int		y;
	int		c_x;
	int		c_y;
}				t_cord;

void	init_data(t_data *data);
int		read_map(t_map *map);
int		check_map(char *char_map, t_map *map);
int		start_game(t_data *data, char *patch);
void	destroy(t_data *data);
void	error_mensage(int option, int sub_option);
char	*ft_strjoin_free2(char *s1, const char *s2, size_t size2);
int		no_event(t_data *data);
int		event(int key, t_data *data);
int		set_sprites(t_data *data, t_sprites *sprite, t_character *character);
void	render_map(t_data *data, t_map *map);
int		render_loop(t_data *data, char brick, int *x, int *y);
void	render_character(t_data *data, char c, int x, int y);
int		collision(t_map *map, int x, int y);
void	render_item_count(t_data *data);
void	sprite_to_img(t_img *sprite, t_img *img, int x, int y);

#endif /* SOLONG_H */
