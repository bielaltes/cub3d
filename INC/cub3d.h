/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/30 16:41:50 by baltes-g         ###   ########.fr       */
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


typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_image;

typedef struct s_map {
    char    *tex_N;
    char    *tex_S;
    char    *tex_E;
    char    *tex_O;
    char    **map;
}       t_map;

typedef struct s_player {
    float locX;
    float locY;
    float angle;
}       t_player;

typedef struct s_game {
    t_player    player;
    t_map       map;
}       t_game;

#endif