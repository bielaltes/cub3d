/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:45 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/30 17:30:28 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_n(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != '\n')
	{
		++str;
		++len;
	}
	return (len);
}

char **read_map(char *str, int fd)
{

}

char	*get_texture(char *line)
{
	int		i;
	char	*ret;
	
	i = 0;
	while (line[i] == ' ')
		++i;
	ret = ft_substr(line, i, ft_strlen_n(line), NO);
	while (line[i])
	{
		if (line[i] != ' ')
			return (NULL);
		++i;
	}
	return (ret);
}

int get_num(char *lime, int *i)
{

}

int	get_colour(char *line, t_color *col)
{
	t_color ret;
	int i;
	
	while (line[i] == ' ')
		++i;
	ret.r = get_num(line, &i);
	if (!i)
		return (FAILURE);
	ret.g = get_num(line, &i);
	if (!i)
		return (FAILURE);
	ret.b = get_num(line, &i);
	if (!i)
		return (FAILURE);
	return (SUCCESS);
}

int parse(int argc, char **argv, t_game *game)
{
	int     fd;
	char    line;
	fd = open(argv[1], O_RDONLY);
	
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line))
		{
			game->map.map = read_map(line, fd);
			if (!game->map.map)
				return (FAILURE);
		}
		if (!ft_strncmp("NO ", line, 3))
		{
			game->map.tex_N = get_texture(line + 2);
			if (!game->map.tex_N)
				return (FAILURE);
		}
		if (!ft_strncmp("SO ", line, 3))
		{
			game->map.tex_S = get_texture(line + 2);
			if (!game->map.tex_N)
				return (FAILURE);
		}
		if (!ft_strncmp("EA ", line, 3))
		{
			game->map.tex_E = get_texture(line + 2);
			if (!game->map.tex_N)
				return (FAILURE);
		}
		if (!ft_strncmp("WE ", line, 2))
		{
			game->map.tex_O = get_texture(line + 2);
			if (!game->map.tex_N)
				return (FAILURE);
		}
		if (!ft_strncmp("F ", line, 2))
		{
			if (!get_colour(line + 1, &game->map.floor))
				return (FAILURE);
		}
		if (!ft_strncmp("C ", line, 2))
		{
			if (!get_colour(line + 1, &game->map.floor))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}