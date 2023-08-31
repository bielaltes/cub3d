/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:53:45 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/31 22:40:24 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int read_colour(t_game * game, char *line)
{
	char **split;

	split = ft_split(line, " ,");
	if (!split)
		exit_parse("Malloc error");
	if (ft_ptrlen(split) != 4)
	{
		exit_parse("Problems reading a line in the map file");
	}
	if (line[0] == 'C')
	{
		printf("%s %s %s\n", split[1], split[2], split[3]);
		game->map.ceiling.r = ft_atoi(split[1], NO);
		game->map.ceiling.g = ft_atoi(split[2], NO);
		game->map.ceiling.b = ft_atoi(split[3], NO);
	}
	else if (line[0] == 'F')
	{
		game->map.floor.r = ft_atoi(split[1], NO);
		game->map.floor.g = ft_atoi(split[2], NO);
		game->map.floor.b = ft_atoi(split[3], NO);
	}
	else
		exit_parse("Invalid identifier for colour");
	free_split(split);
	return (SUCCESS);
}


static int read_texture(t_game * game, char *line)
{
	char **split;

	split = ft_split(line, " ");
	if (!split)
		exit_parse("Malloc error");
	if (ft_ptrlen(split) != 2)
	{
		printf("Printing: %s, %d\n", split[0], ft_ptrlen(split));
		exit_parse("Problems reading a line in the map file");
	}
	if (line[0] == 'N' && line[1] == 'O')
		game->map.tex_N = ft_strdup(split[1], NO);
	else if (line[0] == 'S' && line[1] == 'O')
		game->map.tex_S = ft_strdup(split[1], NO);
	else if (line[0] == 'E' && line[1] == 'A')
		game->map.tex_E = ft_strdup(split[1], NO);
	else if (line[0] == 'W' && line[1] == 'E')
		game->map.tex_O = ft_strdup(split[1], NO);
	else
		exit_parse("Invalid identifier for texture");
	free_split(split);
	return (SUCCESS);
}


static int	is_map(char *line)
{
	while (*line != '\0')
	{
		if (*line != ' ' && *line != '0' && *line != '1' && *line != 'N' && *line != 'S' && *line != 'W' && *line != 'E' && *line != '\n')
		{
			return (0);
		}
		++line;
	}
	return (1);
}

int read_textures_colours(int fd, t_game *game)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line && count < 6)
	{
		while (*line == ' ')
			++line;
		if (*line != '\n' && line && !is_map(line))
		{
			if (ft_strlen_n(line) == 2)
			{
				read_texture(game, line);
				++count;
			}
			else if (ft_strlen_n(line) == 1)
			{
				read_colour(game, line);
				++count;
			}
			else
			{
				exit_parse("Syntax error in map file");
			}
		}
		free(line);
		if (count < 6)
			line = get_next_line(fd);
	}
	if (count != 6)
		exit_parse("There should be 4 textures and 2 colours before the map");
	return (SUCCESS);
}

int read_map(int fd, t_game *game)
{
	char	*line;
	char	*str_map;

	line = get_next_line(fd);
	str_map = ft_strdup("", NO);
	while (line && is_map(line))
	{
		str_map = ft_strjoin(str_map, line, BOTH);
		if (!str_map)
			exit_parse("Error malloc");
		line = get_next_line(fd);
	}
	if (line)
		exit_parse("There is something strange around the map");
	game->map.map = ft_split(str_map, "\n");
	return (SUCCESS);
}

int parse(int argc, char **argv, t_game *game)
{
	int     fd;

	if (argc != 2)
		exit_parse("Invalid number of arguments");
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_parse("Cannot open map file");
	read_textures_colours(fd, game);
	//check_textures(&game->map);
	read_map(fd, game);
	//check_map();
	return (SUCCESS);
}