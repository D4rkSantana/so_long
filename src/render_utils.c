/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:54:47 by esilva-s          #+#    #+#             */
/*   Updated: 2022/07/17 21:00:02 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*ft_strjoin_free2(char *s1, const char *s2, size_t size2)
{
	unsigned int	size;
	unsigned int	size1;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size = size1 + size2 + 1;
	new = (char *)ft_calloc(sizeof(char), size);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, size1 + 1);
	ft_strlcpy(new + size1, s2, size2 + 1);
	ft_strdel(&s1);
	return (new);
}

void	sprite_to_img(t_img *sprite, t_img *img, int x, int y)
{
	char	*dst;
	char	*src;
	int		count_src;
	int		count_y;
	int		count_x;

	count_src = 0;
	count_y = 0;
	count_x = 0;
	dst = img->addr;
	src = sprite->addr;
	while (count_y < sprite->h)
	{
		while (count_x < sprite->line_len)
		{
			dst[((count_y + y) * img->line_len)
				+ (count_x + (x * 4))] = src[count_src];
			count_src++;
			count_x++;
		}
		count_x = 0;
		count_y++;
	}
}

static void	render_blocks(t_data *data, char c, int x, int y)
{
	if (c == 48)
		sprite_to_img(&data->sprite.bg0, &data->image, x, y);
	else if (c == 49)
		sprite_to_img(&data->sprite.bg1, &data->image, x, y);
	else if (c == 67)
		sprite_to_img(&data->sprite.item, &data->image, x, y);
	else if (c == 69)
		sprite_to_img(&data->sprite.exit, &data->image, x, y);
}

void	render_character(t_data *data, char c, int x, int y)
{
	if (c == 87)
		sprite_to_img(&data->character.character_n, &data->image, x, y);
	else if (c == 83)
		sprite_to_img(&data->character.character_s, &data->image, x, y);
	else if (c == 68 || c == 80)
		sprite_to_img(&data->character.character_e, &data->image, x, y);
	else if (c == 65)
		sprite_to_img(&data->character.character_w, &data->image, x, y);
	data->character.direction = c;
}

int	render_loop(t_data *data, char brick, int *x, int *y)
{	
	if (brick == 48 || brick == 49 || brick == 67 || brick == 69)
	{
		render_blocks(data, brick, *x, *y);
		*x += 50;
	}
	else if (brick == 80)
	{
		render_character(data, brick, *x, *y);
		data->character.x = *x;
		data->character.y = *y;
		*x += 50;
		return (1);
	}
	if (brick == '\n')
	{
		*y += 50;
		*x = 0;
	}	
	return (0);
}
