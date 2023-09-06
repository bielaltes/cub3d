/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:51:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 19:03:36 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_game *game)
{
	(void) game;
	exit(0);
}

int main(int argc, char **argv)
{
	t_game game;
	parse(argc, argv, &game);
	init(&game);
	mlx_hook(game.mlx.mlx_win, 2, (1L << 0), &key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 3, (1L << 0), &key_hook_release, &game);
	mlx_hook(game.mlx.mlx_win, 4, (1L << 0), &mouse_hook, &game);
	mlx_hook(game.mlx.mlx_win, 5, (1L << 0), &mouse_hook_release, &game);
	mlx_hook(game.mlx.mlx_win, 17, 0, &clean_exit, &game);
	render(&game);
	mlx_loop_hook(game.mlx.mlx, render, &game);
	mlx_loop(game.mlx.mlx);
}