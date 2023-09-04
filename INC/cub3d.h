/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/04 03:24:41 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_h
# define CUB3D_h

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../LIB/libft/libft.h"
# include "../LIB/minilibx_opengl_20191021/mlx.h"

# define PI 3.14159265359
# define SPEED 15
# define TURN 0.05
# define W 13
# define A 0
# define S 1
# define D 2


typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void    *win_ptr;
    void    *win_addr;
}		t_image;

typedef struct s_map {
    char    *tex_N;
    char    *tex_S;
    char    *tex_E;
    char    *tex_O;
    char    **map;
    int     cols;
    int     rows;
}       t_map;

typedef struct s_player {
    float locX;
    float locY;
    float angle;
}       t_player;

typedef struct s_game {
    t_player    player;
    t_image       map; //es t_map
    // t_image     image;
}       t_game;

float FixAng(float a);
void  my_mlx_pixel_put(t_image *data, int x, int y, int color);



#endif