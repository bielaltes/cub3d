/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:23:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/07 05:04:42 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void  print_2d(t_game *game)
// {
//   int color;  

//   for(int y=0;y<game->map.n_rows;y++)
//   {
//     for(int x=0;x<game->map.n_cols;x++)
//     {
//       if(game->map.map[y][x] < '1')
//       { 
//           color = 0x00ffffff;
//       }
//       else
//       { 
//           color = 0x00000000;
//       }
//       for(int j=0; j<16;j++)
//       {
//         for(int k=0; k<16;k++)
//         {
//           my_pixel_put(&game->mlx.img, \
//           k + (x*16) + 10, j + (y*16)+10, color);
//         }
//       }
//     }
//   }
// }

// void  print_player(t_game *game)
// {
//   int color;

// 	color = 0x0000ffff;
//   for(int j=0; j<16;j++)
//   {
//     for(int k=0; k<16;k++)
//     {
//       my_pixel_put(&game->mlx.img,\
//       (game->player.locy*64/16) + j,\
//       (game->player.locx*64/16) + k, color);
//     }
//   }
  // for(int x=0; x<16; x++)
  // {
	// float angle = atan2(game.player.diry, game.player.dirx);
  //   my_pixel_put(&game.mlx.img, x *cos(angle) \
  //   + (game.player.locx*16) + 4 , 4 + \
  //   game.player.locy*16 - x * sin(angle) , color); 
  // }
// }
