/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:16 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 00:10:40 by jareste-         ###   ########.fr       */
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

void  print_player(t_game game, int color)
{
	color = 0x00000000;
  for(int j=0; j<8;j++)
  {
    for(int k=0; k<8;k++)
    {
      my_pixel_put(&game.mlx.img, k + (game.player.locx*16), j + \
      (game.player.locy*16), color);
    }
  }
  for(int x=0; x<16; x++)
  {
	float angle = atan2(game.player.diry, game.player.dirx);
    my_pixel_put(&game.mlx.img, x *cos(angle) \
    + (game.player.locx*16) + 4 , 4 + game.player.locy*16 - x * sin(angle) , color); 
  }
}

int	init_render_vars(t_player *pl, t_ray *r, int x)
{
	r->camerax = 2*x/(float)WIDTH -1;
	r->raydirx = pl->dirx + pl->planex*r->camerax;
	r->raydiry = pl->diry + pl->planey*r->camerax;
	r->mapx = pl->locx;
	r->mapy = pl->locy;
	r->deltadistx = fabs(1/r->raydirx);
	r->deltadisty = fabs(1/r->raydiry);
	r->hit = 0;
	return (SUCCESS);
}

int find_dist_to_edge(t_player *pl, t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (pl->locx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - pl->locx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (pl->locy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - pl->locy) * r->deltadisty;
	}
	return (SUCCESS);
}

int find_collision(t_game *game, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (game->map.map[r->mapx][r->mapy] == '1')
			r->hit = 1;
	}
	return (SUCCESS);
}

int render(t_game *game)
{
	int				x;
	t_player	pl;
	t_ray			r;
	
	x = 0;
	pl = game->player;
	while (x < WIDTH)
	{
		init_render_vars(&pl, &r, x);
		find_dist_to_edge(&pl, &r);
		find_collision(game, &r);
		r.perpwalldist = compute_dist(&pl, &r);
		draw_vertical(game, &game->mlx.img, &game->mlx.textures[choose_text(&r)], \
		(int)(HEIGHT / r.perpwalldist), x, compute_xcoord(&pl, &r));
		++x;
	}	
	wasd_moves(game);
	rot_moves(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->mlx.img.img, 0, 0);
	
	return (SUCCESS);
}