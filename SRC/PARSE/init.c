/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:01:18 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/04 15:27:33 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int save_texture(t_mlx *mlx, t_image *img, char *path)
{
	path[ft_strlen(path) -1] = '\0';
	img->img = mlx_xpm_file_to_image(mlx->mlx,
			path, &img->width, &img->height);
	if (!img->img)
		exit_parse("Couldn't convert xpm file to image.");
	img->addr = mlx_get_data_addr(
			img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	if (!img->addr)
		exit_parse("Cound not get img address");
	return (SUCCESS);
}
int charge_textures(t_mlx *mlx, t_map *map)
{
	save_texture(mlx, &mlx->textures[0], map->tex_N);
	save_texture(mlx, &mlx->textures[1], map->tex_S);
	save_texture(mlx, &mlx->textures[2], map->tex_E);
	save_texture(mlx, &mlx->textures[3], map->tex_O);
	return (SUCCESS);
}

int init(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		exit_parse("Cound not initialize mlx");
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (!game->mlx.mlx_win)
		exit_parse("Cound not initialize mlx window");
	game->mlx.img.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (!game->mlx.img.img)
		exit_parse("Cound not initialize mlx image");
	game->mlx.img.addr = mlx_get_data_addr(game->mlx.img.img,
			&(game->mlx.img.bits_per_pixel),
			&(game->mlx.img.line_length), &(game->mlx.img.endian));
	if (!game->mlx.img.addr)
		exit_parse("Cound not get img address");
	charge_textures(&game->mlx, &game->map);
	return (SUCCESS);
}