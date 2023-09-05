/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/05 18:53:08 by baltes-g         ###   ########.fr       */
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
# define SPEED 0.09
# define TURN 0.05
# define W 13
# define A 0
# define S 1
# define D 2


# define SUCCESS 1
# define FAILURE 0

# define NO 0
# define FIRST 1
# define SECOND 2
# define BOTH 3

# define HEIGHT 1080
# define WIDTH 1920

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
	int		width;
	int		height;
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
	float dirX;
	float dirY;
	float planeX;
	float planeY;
}       t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_image		img;
	t_image		textures[4];
}		t_mlx;

typedef struct	s_key {
	char	w;
	char	a;
	char	s;
	char	d;
	char	left;
	char	right;
}		t_key;

typedef struct s_game {
	t_player    player;
	t_map       map;
	t_mlx       mlx;
	t_key		key;
}       t_game;

//PARSE
int         exit_parse(char *str);
void        free_split(char **split);
int	        ft_strlen_n(const char *str);
int         parse(int argc, char **argv, t_game *game);
int	        ft_ptrlen(char **str);
int 		init(t_game *game);

//HOOKS

int			key_hook(int key_code, t_game *game);
int 		key_hook_release(int key, t_game *game);
int			wasd_moves(t_game *game);
int			rot_moves(t_game *game);




//UTILS
int 		c2int(t_color *c);
void		my_pixel_put(t_image *data, int x, int y, int color);
int			my_pixel_get(t_image *img, int x, int y);


//RENDER

int draw_vertical(t_game *game, t_image *img, t_image *tex, int height, int x, int x_tex);
float FixAng(float a);
void  print_rays(t_game *game);
int print_win(int key, t_game *game);
int render(t_game *game);

#endif