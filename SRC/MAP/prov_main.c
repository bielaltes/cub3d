/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prov_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:00 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/04 04:36:38 by jareste-         ###   ########.fr       */
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

float radang(float angle)
{
  return (angle * M_PI / 180);
}



float  ray_colision(t_game *game, float angle)
{
  //////quiero saber si en la diagonal que estoy trazando, donde acaba 
  //////colisionando para dibujar la linea.
  float rx;
  float ry;
  /////////printing rx && ry (distance to walls)
  if (angle <= 90 && angle > 0)
  {
    rx = (mapWidth - game->player.locX) * 16;
    ry = (game->player.locY) * 16;
    for (int x = 0; x<rx;x++)
      my_mlx_pixel_put(&game->map, x + (game->player.locX*16) + 4 , \
      4 + game->player.locY*16, 0x00ffffff); 
  
    for (int x = 0; x<ry;x++)
      my_mlx_pixel_put(&game->map,(game->player.locX*16) + 4 , \
      4 + game->player.locY*16 - x, 0x00ffffff);
  }
  if (angle <= 180 && angle > 90)
  {
    rx = (game->player.locX) * 16;
    ry = (game->player.locY) * 16;
    
    for (int x = 0; x<rx;x++)
      my_mlx_pixel_put(&game->map, -x + (game->player.locX*16) + 4 , \
       4 + game->player.locY*16, 0x00ffffff); 
  
    for (int x = 0; x<ry;x++)
      my_mlx_pixel_put(&game->map,(game->player.locX*16) + 4 , \
      4 + game->player.locY*16 - x, 0x00ffffff);

  }
  if (angle <= 270 && angle > 180)
  {
    rx = (game->player.locX) * 16;
    ry = (mapHeight - game->player.locY) * 16;
    for (int x = 0; x<rx;x++)
      my_mlx_pixel_put(&game->map, -x + (game->player.locX*16) + 4 , \
      4 + game->player.locY*16, 0x00ffffff); 
  
    for (int x = 0; x<ry;x++)
      my_mlx_pixel_put(&game->map,(game->player.locX*16) + 4 , \
      4 + game->player.locY*16 + x, 0x00ffffff);
  }
  if (angle <= 360 && angle > 270)
  {
    rx = (mapWidth - game->player.locX) * 16 ;
    ry = (mapHeight - game->player.locY) * 16;
    for (int x = 0; x<rx;x++)
      my_mlx_pixel_put(&game->map, +x + (game->player.locX*16) + 4 , \
      4 + game->player.locY*16, 0x00ffffff); 
  
    for (int x = 0; x<ry;x++)
      my_mlx_pixel_put(&game->map,(game->player.locX*16) + 4 , \
      4 + game->player.locY*16 + x, 0x00ffffff);
  }
  /////////printing rx && ry (distance to walls)
  // rx -= 16;
  // ry -= 16;

  //now with rx & ry we should calculate the ray properly.
  float  distance = 0;
  if (angle < game->player.angle)
    distance = rx / cos(radang(angle));
  else
    distance = ry / cos(radang(90 - angle));
  // int start = 
  // for ()
  printf("rx::::%f,ry::::::%f,dist::::::%f, ang::::%f,\n", rx, ry, distance, angle);
  // if (angle < 45)
    // return (0);
  return (distance);
}


////////first raycast tests
void  print_rays(t_game *game)
{
   //Quiero imprimir rayos desde el POV del jugador y +-30.
  float angle;
  float ray_distance;

  for (int x = 0; x < 60; x += 3)
  {
    angle = game->player.angle - 30 + x; 
    angle = FixAng(angle);
    ray_distance = ray_colision(game, angle);
    // printf("distance::::::::%f,\n", ray_distance);
    for (int j = 0; j<ray_distance;j++)
    {
      printf("map_pos:::::%i,\n", worldMap[(int)((j *cos(radang(angle)) + game->player.locX*16)/16)][(int)(((game->player.locY*16) - j * sin(radang(angle)))/16)]);
      if (worldMap[(int)((j *cos(radang(angle)) + game->player.locX*16)/16)][(int)(((game->player.locY*16) - j * cos(radang(90 - angle)))/16)] > 0)
        break;
      my_mlx_pixel_put(&game->map, j *cos(radang(angle)) \
      + (game->player.locX*16) + 4 , 4 + game->player.locY*16 - j * sin(radang(angle)) , 0x00000000); 
    }
  }

}



////////first raycast tests



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
    print_rays(game);
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

float FixAng(float a) //funcion importante para no pasarnos del angulo que nos interesa.
{ 
     if(a > 359)
        a -= 360;
     if(a < 0)
        a += 360;
     return (a);
}

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
  game.player.angle = 45;


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
print_rays(&game);

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
