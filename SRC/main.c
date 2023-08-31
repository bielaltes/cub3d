/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:51:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/08/31 19:14:28 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game game;
	parse(argc, argv, &game);
		printf("NO: %s\n", game.map.tex_N);
		printf("SO: %s\n", game.map.tex_S);
		printf("EA: %s\n", game.map.tex_E);
		printf("WE: %s\n", game.map.tex_O);
		printf("Floor: %d %d %d\n", game.map.floor.r, game.map.floor.g, game.map.floor.b);
		printf("Ceeiling: %d %d %d\n", game.map.ceiling.r, game.map.ceiling.g, game.map.ceiling.b);
		printf("\n Map:\n");
		int i = 0;
		while (game.map.map[i])
		{
			printf("%s\n", game.map.map[i]);
			++i;
		}
}