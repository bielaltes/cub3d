/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:07:53 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 23:52:48 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *line)
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

int is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != ' ')
			return (0);
		++i;
	}
	free(line);
	return (1);
}

int read_map(int fd, t_game *game)
{
	char	*line;
	char	*str_map;
	
	game->map.n_rows = 0;
	game->map.n_cols = 0;
	line = get_next_line(fd);
	str_map = ft_strdup("", NO);
	while (is_empty(line))
		line = get_next_line(fd);
	while (line && is_map(line) && !is_empty(line))
	{
		game->map.n_rows++;
		if ((int)ft_strlen(line) -1 > game->map.n_cols)
			game->map.n_cols = ft_strlen(line) -1;
		str_map = ft_strjoin(str_map, line, BOTH);
		if (!str_map)
			exit_parse("Error malloc");
		line = get_next_line(fd);
	}
	while (line && is_empty(line))
		line = get_next_line(fd);
	if (line)
		exit_parse("There is something strange around the map");
	game->map.map = ft_split(str_map, "\n");
	free(str_map);
	return (SUCCESS);
}

int check_inside(char *line, t_player *player, int *found, int row)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		line[i++] = '-';
	while (line[i] && (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'))
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		{
			if (*found == 0)
			{
				setup_pl(player, line[i], i, row);
				*found = 1;
			}
			else
				exit_parse("Two players were found");
		}
		if (line[i] == ' ')
			line[i] = '0';
		++i;
	}
	if (line[i] != '\n' && line[i] != '\0')
		return (exit_parse("No map character was found in map"));
	return (SUCCESS);
}

int	check_map(t_game *game, char **map, t_player *player)
{
	int	i;
	int	found;
	char *visited;

	found = 0;
	i = 0;
	while (map[i])
	{
		check_inside(map[i], player, &found, i);
		++i;
	}
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < game->map.n_cols)
			map[i] = ft_strjoin(map[i], create_string(game, '-', game->map.n_cols - ft_strlen(map[i])), BOTH);
		++i;
	}
	found = 0;
	visited = create_string(game, '0', game->map.n_cols * game->map.n_rows);
	dfs(&game->map, visited, player->locx, player->locy, &found);
	if (found)
		exit_parse("Map is opened somewhere");
	free(visited);
	return (SUCCESS);
}