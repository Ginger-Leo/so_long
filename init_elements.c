/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:42:18 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/27 09:13:21 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game_list *game)
{
	int	x;
	int	y;

	game->p_count = 0;
	x = 0;
	y = 0;
	while (game->map_array[y])
	{
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == 'P')
			{
				game->p_count++;
				game->x_ppos = x;
				game->y_ppos = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_exit(t_game_list *game)
{
	int	y;
	int	x;

	game->e_count = 0;
	y = 0;
	x = 0;
	while (game->map_array[++y])
	{
		while (game->map_array[y][++x])
		{
			if (game->map_array[y][x] == 'E')
			{
				game->e_count++;
				game->x_xpos = x;
				game->y_xpos = y;
			}
		}
		x = 0;
	}
}

void	init_collectables(t_game_list *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	game->c_count = 0;
	while (game->map_array[++y])
	{
		while (game->map_array[y][++x])
		{
			if (game->map_array[y][x] == 'C')
			{
				game->c_count++;
			}
		}
		x = 0;
	}
}

void	check_letters(t_game_list *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map_array[y])
	{
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == '1' || game->map_array[y][x] == '0' ||
			game->map_array[y][x] == 'C' || game->map_array[y][x] == 'P'
			|| game->map_array[y][x] == 'E')
				x++;
			else
			{
				ft_putstr_fd(ERR_ELEMENTS, 2);
				exit(1);
			}
		}
		x = 0;
		y++;
	}
}
