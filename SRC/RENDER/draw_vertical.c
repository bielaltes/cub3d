/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:00:57 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/04 15:49:22 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int draw_vertical(t_game *game, t_image *img, t_image *tex, int height, int x, int x_tex)
{
	int 	i;
	float	step;
	float	pos_img;

	pos_img = 0;
	i = 0;
	step = 64 / (float)height;
	while (i < (HEIGHT/2 - height/2))
		my_pixel_put(img, x, i++, c2int(&game->map.ceiling));
	while (i < (HEIGHT/2 + height/2))
	{
		my_pixel_put(img, x, i, my_pixel_get(tex, x_tex, (int)pos_img));
		pos_img += step;
		//printf("%f\n", pos_img);
		++i;
	}
	while (i < HEIGHT)
		my_pixel_put(img, x, i++, c2int(&game->map.floor));
	return (SUCCESS);
}