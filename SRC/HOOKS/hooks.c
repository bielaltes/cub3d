/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:58:44 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 12:44:40 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_correct(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (map[x][y] == '1')
		return (0);
	return (1);
}

int wasd_moves(t_game *game)
{
	if (game->key.w) //w
	{
		if (check_correct(game->map.map, game->player.locX + game->player.dirX * SPEED, game->player.locY))
			game->player.locX += game->player.dirX * SPEED;
		if (check_correct(game->map.map, game->player.locX, game->player.locY + game->player.dirY * SPEED))
			game->player.locY += game->player.dirY * SPEED;
	}
	if (game->key.a) //a
	{
		if (check_correct(game->map.map, game->player.locX - game->player.dirY * SPEED,  game->player.locY))
			game->player.locX -= game->player.dirY * SPEED;
		if (check_correct(game->map.map,  game->player.locX, game->player.locY + game->player.dirX * SPEED))
			game->player.locY += game->player.dirX * SPEED;
	}
	if (game->key.s) //s
	{
		if (check_correct(game->map.map, game->player.locX - game->player.dirX * SPEED, game->player.locY))
			game->player.locX -= game->player.dirX * SPEED;
		if (check_correct(game->map.map, game->player.locX, game->player.locY - game->player.dirY * SPEED))
			game->player.locY -= game->player.dirY * SPEED;
	}
	if (game->key.d) //d
	{
		if (check_correct(game->map.map, game->player.locX + game->player.dirY * SPEED,  game->player.locY))
			game->player.locX += game->player.dirY * SPEED;
		if (check_correct(game->map.map,  game->player.locX, game->player.locY - game->player.dirX * SPEED))
			game->player.locY -= game->player.dirX * SPEED;
	}
	return (SUCCESS);
}

int rot_moves(t_game *game)
{
	if (game->key.left) //dreta
	{
	  	float oldDirX = game->player.dirX;
	 	game->player.dirX = game->player.dirX * cos(TURN) - game->player.dirY * sin(TURN);
	  	game->player.dirY = oldDirX * sin(TURN) + game->player.dirY * cos(TURN);
	  	float oldPlaneX = game->player.planeX;
	  	game->player.planeX = game->player.planeX * cos(TURN) - game->player.planeY * sin(TURN);
	  	game->player.planeY = oldPlaneX * sin(TURN) + game->player.planeY * cos(TURN);
	}
	if (game->key.right) //esquerra
	{
	  	float oldDirX = game->player.dirX;
	 	game->player.dirX = game->player.dirX * cos(-TURN) - game->player.dirY * sin(-TURN);
	  	game->player.dirY = oldDirX * sin(-TURN) + game->player.dirY * cos(-TURN);
	  	float oldPlaneX = game->player.planeX;
	  	game->player.planeX = game->player.planeX * cos(-TURN) - game->player.planeY * sin(-TURN);
	  	game->player.planeY = oldPlaneX * sin(-TURN) + game->player.planeY * cos(-TURN);
	}
	return (SUCCESS);
}

int key_hook(int key, t_game *game)
{
  if (key == W || key == A || key == S || key == D || key == 123 || key == 124)
  {
	if (key == W) //w
		game->key.w = 1;
	if (key == A) //w
		game->key.a = 1;
	if (key == S) //w
		game->key.s = 1;
	if (key == D) //w
		game->key.d = 1;
	if (key == 123) //dreta
		game->key.left = 1;
	if (key == 124) //w
		game->key.right = 1;
  }
  return (SUCCESS);
}

int key_hook_release(int key, t_game *game)
{
	if (key == W) //w
		game->key.w = 0;
	if (key == A) //w
		game->key.a = 0;
	if (key == S) //w
		game->key.s = 0;
	if (key == D) //w
		game->key.d = 0;
	if (key == 123)
		game->key.left = 0;
	if (key == 124)
		game->key.right = 0;
	if (key == 53)
		clean_exit(game);
	return (SUCCESS);
}

int mouse_hook(int key, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (key == 1)
		game->key.left = 1;
	if (key == 2)
		game->key.right = 1;
	return (SUCCESS);
}

int mouse_hook_release(int key, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (key == 1)
		game->key.left = 0;
	if (key == 2)
		game->key.right = 0;
	return (SUCCESS);
}