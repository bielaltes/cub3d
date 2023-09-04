/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:58:44 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/04 20:15:37 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int key, t_game *game)
{
  if (key == W || key == A || key == S || key == D || key == 123 || key == 124)
  {
	if (key == S) //w
	{
		game->player.locX -= game->player.dirX;
		game->player.locY -= game->player.dirY;
	}
	if (key == D) //a
	{
	  	game->player.locX -= game->player.dirY;
		game->player.locY += game->player.dirX;
	}
	if (key == W) //s
	{
		game->player.locX += game->player.dirX;
		game->player.locY += game->player.dirY;
	}
	if (key == A) //d
	{
	  	game->player.locX += game->player.dirY;
		game->player.locY -= game->player.dirX;
	}
	if (key == 124) //dreta
	{
	  	float oldDirX = game->player.dirX;
	 	game->player.dirX = game->player.dirX * cos(0.05) - game->player.dirY * sin(0.05);
	  	game->player.dirY = oldDirX * sin(0.05) + game->player.dirY * cos(0.05);
	  	float oldPlaneX = game->player.planeX;
	  	game->player.planeX = game->player.planeX * cos(0.05) - game->player.planeY * sin(0.05);
	  	game->player.planeY = oldPlaneX * sin(0.05) + game->player.planeY * cos(0.05);
	}
	if (key == 123) //esquerra
	{
	  	float oldDirX = game->player.dirX;
	 	game->player.dirX = game->player.dirX * cos(-0.05) - game->player.dirY * sin(-0.05);
	  	game->player.dirY = oldDirX * sin(-0.05) + game->player.dirY * cos(-0.05);
	  	float oldPlaneX = game->player.planeX;
	  	game->player.planeX = game->player.planeX * cos(-0.05) - game->player.planeY * sin(-0.05);
	  	game->player.planeY = oldPlaneX * sin(-0.05) + game->player.planeY * cos(-0.05);
	}
	mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
	printf("posX::::::%f,posY:::::%f,\n", game->player.locX, game->player.locY);
	render(game);
  }
  return (SUCCESS);
}