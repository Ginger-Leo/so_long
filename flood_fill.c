/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:11:14 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/20 12:38:04 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game_list *game)
{
	fill(game->y_ppos, game->x_ppos, game);
	check_map(game);
	free_map(game->map_copy);
}

void	fill(int cur_y, int cur_x, t_game_list *game)
{
	if (game->map_copy[cur_y][cur_x] == '1' ||
			game->map_copy[cur_y][cur_x] == 'F')
		return ;
	(game->map_copy[cur_y][cur_x]) = 'F';
	fill(cur_y - 1, cur_x, game);
	fill(cur_y + 1, cur_x, game);
	fill(cur_y, cur_x - 1, game);
	fill(cur_y, cur_x + 1, game);
}

void	check_map(t_game_list *game)
{
	static int	y = 0;
	static int	x = 0;

	while (game->map_copy[y])
	{
		while (game->map_copy[y][x])
		{
			if (game->map_copy[y][x] == 'P' ||
			game->map_copy[y][x] == 'E' ||
			game->map_copy[y][x] == 'C')
			{
				ft_putstr_fd(FLOOD_ERR, 2);
				exit(1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}
