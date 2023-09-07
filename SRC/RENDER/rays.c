/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:24:08 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 01:33:45 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int find_dist_to_edge(t_player *pl, t_ray *r)
// {
// 	if (r->rayDirX < 0)
// 	{
// 		r->stepX = -1;
// 		r->sideDistX = (pl->locX - r->mapX) * r->deltaDistX;
// 	}
// 	else
// 	{
// 		r->stepX = 1;
// 		r->sideDistX = (r->mapX + 1.0 - pl->locX) * r->deltaDistX;
// 	}
// 	if (r->rayDirY < 0)
// 	{
// 		r->stepY = -1;
// 		r->sideDistY = (pl->locY - r->mapY) * r->deltaDistY;
// 	}
// 	else
// 	{
// 		r->stepY = 1;
// 		r->sideDistY = (r->mapY + 1.0 - pl->locY) * r->deltaDistY;
// 	}
// 	return (SUCCESS);
// }

// int find_collision(t_game *game, t_ray *r)
// {
// 	while (r->hit == 0)
// 	{
// 		if (r->sideDistX < r->sideDistY)
// 		{
// 			r->sideDistX += r->deltaDistX;
// 			r->mapX += r->stepX;
// 			r->side = 0;
// 		}
// 		else
// 		{
// 			r->sideDistY += r->deltaDistY;
// 			r->mapY += r->stepY;
// 			r->side = 1;
// 		}
// 		if (game->map.map[r->mapX][r->mapY] == '1')
// 			r->hit = 1;
// 	}
// 	return (SUCCESS);
// }

int main
norminete error aquest arxiu no fa absolutament res