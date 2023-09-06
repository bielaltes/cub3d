/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prov_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:00 by jareste-          #+#    #+#             */
/*   Updated: 2023/09/06 19:21:00 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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

  }
  if (angle <= 180 && angle > 90)
  {
    rx = (game->player.locX) * 16;
    ry = (game->player.locY) * 16;

  }
  if (angle <= 270 && angle > 180)
  {
    rx = (game->player.locX) * 16;
    ry = (mapHeight - game->player.locY) * 16;
  }
  if (angle <= 360 && angle > 270)
  {
    rx = (mapWidth - game->player.locX) * 16 ;
    ry = (mapHeight - game->player.locY) * 16;
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
  // printf("rx::::%f,ry::::::%f,dist::::::%f, ang::::%f,\n", rx, ry, distance, angle);
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
  float x;

  x = 0;
  for (int i = 0; i < WIDTH; i++)
  {
    printf("%d\n", i);
    angle = game->player.angle - 30 + x; 
    angle = FixAng(angle);
    ray_distance = ray_colision(game, angle);
    //printf("distance::::::::%f,\n", ray_distance);
    draw_vertical(game, &game->mlx.img, &game->mlx.textures[0], 10000/ray_distance, i, i%64);

    x+= 0.3125;
  }
  mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->mlx.img.img, 0, 0);
}
////////first raycast tests



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
    mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
    print_rays(game);
  }
  return (0);
}

////////////////print player 2D

////////////////print player 2D

// float FixAng(float a) //funcion importante para no pasarnos del angulo que nos interesa.
// { 
//      if(a > 359)
//         a -= 360;
//      if(a < 0)
//         a += 360;
//      return (a);
// }

////////////////print map 2D

////////////////print map 2D


int	main(void)
{
  t_game game;
	t_image	map;

  game.player.locX = 12;
  game.player.locY = 12;
  game.player.angle = 45;


////////////map creation
	game.mlx.mlx = mlx_init();
	game.mlx.mlx_win = mlx_new_window(game.mlx.mlx, screenWidth, screenHeight, \
	"tests");
////////////map creation

///////////////img creation
  map.img = mlx_new_image(game.mlx.mlx, screenHeight, screenWidth);
  map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, \
  &map.line_length, &map.endian);
///////////////img creation

////////////////print map 2D
print_2d(map, 0x00af00af, 0x0000af00);
////////////////print map 2D
  game.mlx.img = map;
print_rays(&game);

////////////////print player 2D
print_player(game, 0x0000ffff);
////////////////print player 2D
  mlx_put_image_to_window(game.mlx.mlx, game.mlx.mlx_win,
		game.mlx.img.img, 0, 0);

  mlx_hook(game.mlx.mlx, 2, 0, print_win, &game);
  // mlx_hook(map.win_ptr, 2, 0, print_angle, &game);
	mlx_loop(game.mlx.mlx);
  return (0);
}*/

