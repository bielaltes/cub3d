/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:17:05 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 19:19:55 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int choose_text(t_ray *r)
{
	int t;
	
	if (r->side == 0 && r->rayDirX < 0)
		t = 0;
	else if (r->side == 0 && r->rayDirX > 0)
		t = 1;
	else if (r->side == 1 && r->rayDirY > 0)
		t = 2;
	else
		t = 3;
	return (t);
}

int	compute_xcoord(t_player *pl, t_ray *r)
{
	float xcoord;

	if (r->side == 0)
		xcoord = pl->locY + r->perpWallDist * r->rayDirY;
	else 
		xcoord = pl->locX + r->perpWallDist * r->rayDirX;
	xcoord = xcoord - floor(xcoord);
	return ((int)(xcoord * 64));
}

float compute_dist(t_player *pl, t_ray *r)
{
	if(r->side == 0) 
		return ((r->mapX - pl->locX + (1 - r->stepX) / 2) / r->rayDirX);
	else          
		return((r->mapY - pl->locY + (1 - r->stepY) / 2) / r->rayDirY);
}
