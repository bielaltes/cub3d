/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jareste- <jareste-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:29:20 by baltes-g          #+#    #+#             */
/*   Updated: 2023/09/06 22:35:48 by jareste-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int exit_parse(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (1);
	return (FAILURE);
}

void free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

int	ft_strlen_n(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != ' ')
	{
		++str;
		++len;
	}
	return (len);
}

int	ft_ptrlen(char **str)
{
	int	len;

	len = 0;
	while (str[len] != NULL)
	{
		++len;
	}
	return (len);
}

int	ft_atoi_cub(char *str, int free_args)
{
	int		sum;
	char	*aux;

	aux = str;
	sum = 0;
	if (ft_strlen(str) > 4)
		exit_parse("Number too long in colours");
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10 + *str - 48;
		++str;
	}
	if (*str != '\0' && *str != '\n')
		exit_parse("Invalid char between numbers");
	if (sum > 256)
		exit_parse("Number too long in colours");
	if (free_args == FIRST)
		free(aux);
	return (sum);
}

char	*create_string(t_game *game, char c, int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(size);
	if (!str)
		clean_exit(game);
	while (i < size -1)
	{
		str[i] = c;
		++i;
	}
	str[i] = '\0';
	return (str);
}

void	dfs(t_map *m, char *visited, int i, int j, int *found)
{
	if (i < 0 || j < 0 || i >= m->n_rows || j > m->n_cols || m->map[i][j] == '-')
	{
		*found = 1;
		return ;
	}
	if (visited[i * m->n_cols + j] == '1' || m->map[i][j] == '1')
		return;
	visited[i * m->n_cols + j] = '1';
	dfs(m, visited, i + 1, j, found);
	dfs(m, visited, i, j +1, found);
	dfs(m, visited, i, j + 1, found);
	dfs(m, visited, i, j - 1, found);
}