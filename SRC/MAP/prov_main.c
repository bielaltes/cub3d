/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prov_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:00 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/04 01:39:05 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/cub3d.h"


#define mapWidth 24
#define mapHeight 24
#define screenWidth 1920
#define screenHeight 1080



int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void  print_2d(t_image map, int color1, int color2);
void  print_player(t_game game, int color);


int	close_win(t_image *map)
{
	if (map)
		mlx_destroy_window(map->win_addr, map->win_ptr);
	exit(0);
}
int print_win(int key, t_game *game)
{
  if (key == W || key == A || key == S || key == D || key == 123 || key == 124)
  {
    if (key == W) //w
    {
      game->player.locY -= 0.5;
      if (worldMap[(int)game->player.locY][(int)game->player.locX] > 0)
        game->player.locY += 0.5;
    }
    if (key == A) //a
    {
      game->player.locX -= 0.5;
      if (worldMap[(int)game->player.locY][(int)game->player.locX] > 0)
        game->player.locX += 0.5;
    }
    if (key == S) //s
    {
      game->player.locY += 0.5;
      if (worldMap[(int)game->player.locY][(int)game->player.locX] > 0)
        game->player.locY -= 0.5;
    }
    if (key == D) //d
    {
      game->player.locX += 0.5;
      if (worldMap[(int)game->player.locY][(int)game->player.locX] > 0)
        game->player.locX -= 0.5;
    }
    if (key == 123) //izquierda
      game->player.angle += 5;
    if (key == 124) //derecha
      game->player.angle -= 5;
    game->player.angle = FixAng(game->player.angle);
    mlx_clear_window(game->map.win_addr, game->map.win_ptr);
    print_2d(game->map, 0x00af00af, 0x0000af00);
    print_player(*game, 0x0000ffff);
    mlx_put_image_to_window(game->map.win_addr, game->map.win_ptr, \
    game->map.img, 0, 0);
  }
  return (0);
}

void  my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
  char  *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

////////////////print player 2D
void  print_player(t_game game, int color)
{
  for(int j=0; j<8;j++)
  {
    for(int k=0; k<8;k++)
    {
      my_mlx_pixel_put(&game.map, k + (game.player.locX*16), j + \
      (game.player.locY*16), color);
    }
  }
  for(int x=0; x<16; x++)
  {
    my_mlx_pixel_put(&game.map, x *cos(game.player.angle * M_PI/180) \
    + (game.player.locX*16) + 4 , 4 + game.player.locY*16 - x * sin(game.player.angle * M_PI/180) , color); 
  }
}
////////////////print player 2D

int FixAng(int a)
{ 
     if(a>359)
          a-=360;
     if(a<0)
          a+=360;
     return a;
}


// void drawLineWithAngle(int x, int y, double angle, int length) {
//     // Convertir el ángulo de grados a radianes
//     double radians = angle * M_PI / 180.0;

//     // Calcular las coordenadas del punto final
//     int x2 = x + length * cos(radians);
//     int y2 = y - length * sin(radians); // Restar y para invertir la dirección del eje y

//     // Dibujar la línea
//     int i;
//     for (i = 0; i <= length; i++) {
//         put_pixel(x + i * cos(radians), y - i * sin(radians)); // Llama a tu función put_pixel para dibujar el píxel
//     }
// }

////////////////print angle hook 2D
int  print_angle(int key, t_game *game)
{
  if (key == 123 || key == 124)
  {
    if (key == 123) //izquierda
      game->player.angle += 5;
    if (key == 124) //derecha
      game->player.angle -= 5;
    game->player.angle = FixAng(game->player.angle);
    mlx_clear_window(game->map.win_addr, game->map.win_ptr);
    print_2d(game->map, 0x00af00af, 0x0000af00);
    print_player(*game, 0x0000ffff);
    mlx_put_image_to_window(game->map.win_addr, game->map.win_ptr, \
    game->map.img, 0, 0);
  }
  return (0);
}
////////////////print angle hook 2D


////////////////print map 2D
void  print_2d(t_image map, int color1, int color2)
{
  int color;
  
  for(int y=0;y<mapHeight;y++)
  {
    for(int x=0;x<mapWidth;x++)
    {
      if(worldMap[y][x]<1)
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
          my_mlx_pixel_put(&map, k + (x*16), j + (y*16), color);
        }
      }
    }
  }
}
////////////////print map 2D


int	main(void)
{
  t_game game;
	t_image	map;

  game.player.locX = 12;
  game.player.locY = 12;
  game.player.angle = 0;


////////////map creation
	map.win_addr = mlx_init();
	map.win_ptr = mlx_new_window(map.win_addr, screenWidth, screenHeight, \
	"tests");
////////////map creation

///////////////img creation
  map.img = mlx_new_image(map.win_ptr, screenHeight, screenWidth);
  map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, \
  &map.line_length, &map.endian);
///////////////img creation

////////////////print map 2D
print_2d(map, 0x00af00af, 0x0000af00);
////////////////print map 2D
  game.map = map;

////////////////print player 2D
print_player(game, 0x0000ffff);
////////////////print player 2D
  mlx_put_image_to_window(game.map.win_addr, game.map.win_ptr, \
  game.map.img, 0, 0);

  mlx_hook(map.win_ptr, 2, 0, print_win, &game);
  // mlx_hook(map.win_ptr, 2, 0, print_angle, &game);
	mlx_hook(map.win_ptr, 17, 0, close_win, &map);
	mlx_loop(map.win_addr);
  return (0);
}
