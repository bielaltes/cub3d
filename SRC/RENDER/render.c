/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:16 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 14:58:08 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  print_2d(t_game *game, int color1, int color2)
{
  int color;
  
  for(int y=0;y<15;y++)
  {
    for(int x=0;x<30;x++)
    {
      if(game->map.map[y][x]< '1')
      { 
          color = color1;
      }
      else
      { 
          color = color2;
      }
      for(int j=0; j<16;j++)
      {
        for(int k=0; k<16;k++)
        {
          my_pixel_put(&game->mlx.img, k + (x*16), j + (y*16), color);
        }
      }
    }
  }
}

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

float FixAng(float a) //funcion importante para no pasarnos del angulo que nos interesa.
{ 
     if(a > 359)
        a -= 360;
     if(a < 0)
        a += 360;
     return (a);
}

void  print_player(t_game game, int color)
{
	color = 0x00000000;
  for(int j=0; j<8;j++)
  {
    for(int k=0; k<8;k++)
    {
      my_pixel_put(&game.mlx.img, k + (game.player.locX*16), j + \
      (game.player.locY*16), color);
    }
  }
  for(int x=0; x<16; x++)
  {
	float angle = atan2(game.player.dirY, game.player.dirX);
    my_pixel_put(&game.mlx.img, x *cos(angle) \
    + (game.player.locX*16) + 4 , 4 + game.player.locY*16 - x * sin(angle) , color); 
  }
}

int	init_render_vars(t_player *pl, t_ray *r, int x)
{
	r->cameraX = 2*x/(float)WIDTH -1;
	r->rayDirX = pl->dirX + pl->planeX*r->cameraX;
	r->rayDirY = pl->dirY + pl->planeY*r->cameraX;
	r->mapX = pl->locX;
	r->mapY = pl->locY;
	r->deltaDistX = fabs(1/r->rayDirX);
	r->deltaDistY = fabs(1/r->rayDirY);
	r->hit = 0;
	return (SUCCESS);
}

int find_dist_to_edge(t_player *pl, t_ray *r)
{
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (pl->locX - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = (r->mapX + 1.0 - pl->locX) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{
		r->stepY = -1;
		r->sideDistY = (pl->locY - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = (r->mapY + 1.0 - pl->locY) * r->deltaDistY;
	}
	return (SUCCESS);
}

int find_collision(t_game *game, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (game->map.map[r->mapX][r->mapY] == '1')
			r->hit = 1;
	}
	return (SUCCESS);
}

int render(t_game *game)
{
	int			x;
	t_player 	pl;
	t_ray		r;
	
	x = 0;
	pl = game->player;
	while (x < WIDTH)
	{
		init_render_vars(&pl, &r, x);
		find_dist_to_edge(&pl, &r);
		find_collision(game, &r);
		r.perpWallDist = compute_dist(&pl, &r);
		draw_vertical(game, &game->mlx.img, &game->mlx.textures[choose_text(&r)], (int)(HEIGHT / r.perpWallDist), x, compute_xcoord(&pl, &r));
		++x;
	}	
	wasd_moves(game);
	rot_moves(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->mlx.img.img, 0, 0);
	
	return (SUCCESS);
}