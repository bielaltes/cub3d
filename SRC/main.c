/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:51:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/04 16:50:29 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int main(int argc, char **argv)
{
	t_game game;
	parse(argc, argv, &game);
	init(&game);
	printf("NO: %s\n", game.map.tex_N);
	printf("SO: %s\n", game.map.tex_S);
	printf("EA: %s\n", game.map.tex_E);
	printf("WE: %s\n", game.map.tex_O);
	printf("Floor: %d %d %d\n", game.map.floor.r, game.map.floor.g, game.map.floor.b);
	printf("Ceeiling: %d %d %d\n", game.map.ceiling.r, game.map.ceiling.g, game.map.ceiling.b);
	printf("Player row: %f Player column %f Player angle: %f", game.player.locY, game.player.locX, game.player.angle);
	printf("\n Map:\n");
	int i = 0;
	while (game.map.map[i])
	{
		printf("%s\n", game.map.map[i]);
		++i;
	}
	for (int i = 0; i < WIDTH; ++i)
	{
		draw_vertical(&game, &game.mlx.img, &game.mlx.textures[1], 100, i, i%64);
	}
	mlx_put_image_to_window(game.mlx.mlx, game.mlx.mlx_win,
		game.mlx.img.img, 0, 0);
	mlx_loop(game.mlx.mlx);
}*/