/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:23:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 19:23:45 by baltes-g         ###   ########.fr       */
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