/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/31 22:30:46 by baltes-g         ###   ########.fr       */
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

# define SUCCESS 1
# define FAILURE 0

# define NO 0
# define FIRST 1
# define SECOND 2
# define BOTH 3

typedef struct s_color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
}       t_color;

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
    t_color floor;
    t_color ceiling;
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

//PARSE
int         exit_parse(char *str);
void        free_split(char **split);
int	        ft_strlen_n(const char *str);
int         parse(int argc, char **argv, t_game *game);
int	        ft_ptrlen(char **str);


#endif