/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:02:16 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/04 20:03:43 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  print_2d(t_game *game, int color1, int color2)
{
  int color;
  
  for(int y=0;y<31;y++)
  {
    for(int x=0;x<33;x++)
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
	float angle = atan(game.player.dirY/game.player.dirX);
	// angle = FixAng(angle);
	// printf("angle::::%f,dirY:::::::%f,dirX::::::%f\n", angle,game.player.dirY, game.player.dirX);
    my_pixel_put(&game.mlx.img, x *cos(angle) \
    + (game.player.locX*16) + 4 , 4 + game.player.locY*16 - x * sin(angle) , color); 
  }
}

int render(t_game *game)
{
	t_player pl = game->player;
	
	for (int x = 0; x < WIDTH; ++x)
	{
		//calculate ray position and direction
		float cameraX = 2*x/(float)(WIDTH-1); //x-coordinate in camera space
		float rayDirX = pl.dirX + pl.planeX*cameraX;
		float rayDirY = pl.dirY + pl.planeY*cameraX;

		//which box of the map we're in
		int mapX = pl.locX;
		int mapY = pl.locY;

		//length of ray from current position to next x or y-side
		float sideDistX;
		float sideDistY;

		//length of ray from one x or y-side to next x or y-side
		float deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		float deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		float perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (pl.locX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - pl.locX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (pl.locY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - pl.locY) * deltaDistY;
		}
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if ((mapX >= 0 && mapY >= 0 && mapX <2 && mapY <2) || game->map.map[mapY][mapX] == '1') hit = 1;
		}

		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);
		//Calculate height of line to draw on screen
		printf("ppwd:: %f\n", perpWallDist);
		int lineHeight = (int)(HEIGHT / perpWallDist);
		draw_vertical(game, &game->mlx.img, &game->mlx.textures[1], lineHeight, x, x%64);
	}
	print_2d(game, 0x00ff0000, 0x0000FF00);
	print_player(*game, 0x000af56F);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
		game->mlx.img.img, 0, 0);
	return (SUCCESS);
}