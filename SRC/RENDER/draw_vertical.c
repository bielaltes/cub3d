/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:00:57 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/05 18:21:45 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_vertical(t_game *game, t_image *img, t_image *tex, int height, int x, int x_tex)
{
	int 	i;
	float	step;
	float	pos_img;

	i = 0;
	step = (float)64/ height;
	if (height >= HEIGHT)
		pos_img = step * (height - HEIGHT) /2;
	else
		pos_img = 0;
	while (i < (HEIGHT/2 - height/2))
		my_pixel_put(img, x, i++, c2int(&game->map.ceiling));
	while (i < HEIGHT && i < (HEIGHT/2 + height/2))
	{
		my_pixel_put(img, x, i, my_pixel_get(tex, x_tex, (int)pos_img));
		pos_img += step;
		++i;
	}
	while (i < HEIGHT)
		my_pixel_put(img, x, i++, c2int(&game->map.floor));
	return (SUCCESS);
}