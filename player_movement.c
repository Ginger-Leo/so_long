/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:12:34 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/08 14:51:13 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game_list *game)
{
	if (game->map_array[game->y_ppos - 1][game->x_ppos] != '1')
	{
		game->steps++;
		ft_printf("steps taken: %i\n", game->steps);
		game->y_ppos -= 1;
		game->img->img_p->instances->y -= game->tile_size;
		if (game->map_array[game->y_ppos][game->x_ppos] == 'C')
		{
			ft_printf("You found an egg!\n");
			remove_collectable(game, game->x_ppos, game->y_ppos);
			ft_printf("collectables left:%i\n", game->c_count);
		}
		if (game->c_count == 0 && game->map_array
			[game->y_ppos][game->x_ppos] == 'E')
			end_game(game, 0);
	}
}

void	move_down(t_game_list *game)
{
	if (game->map_array[game->y_ppos + 1][game->x_ppos] != '1')
	{
		game->steps++;
		ft_printf("steps taken: %i\n", game->steps);
		game->y_ppos += 1;
		game->img->img_p->instances->y += game->tile_size;
		if (game->map_array[game->y_ppos][game->x_ppos] == 'C')
		{
			ft_printf("You found an egg!\n");
			remove_collectable(game, game->x_ppos, game->y_ppos);
			ft_printf("collectables left:%i\n", game->c_count);
		}
		if (game->c_count == 0 && game->map_array
			[game->y_ppos][game->x_ppos] == 'E')
			end_game(game, 0);
	}
}

void	move_left(t_game_list *game)
{
	if (game->map_array[game->y_ppos][game->x_ppos - 1] != '1')
	{
		game->steps++;
		ft_printf("steps taken: %i\n", game->steps);
		game->x_ppos -= 1;
		game->img->img_p->instances->x -= game->tile_size;
		if (game->map_array[game->y_ppos][game->x_ppos] == 'C')
		{
			ft_printf("You found an egg!\n");
			remove_collectable(game, game->x_ppos, game->y_ppos);
			ft_printf("collectables left:%i\n", game->c_count);
		}
		if (game->c_count == 0 && game->map_array
			[game->y_ppos][game->x_ppos] == 'E')
			end_game(game, 0);
	}
}

void	move_right(t_game_list *game)
{
	if (game->map_array[game->y_ppos][game->x_ppos + 1] != '1')
	{
		game->steps++;
		ft_printf("steps taken: %i\n", game->steps);
		game->x_ppos += 1;
		game->img->img_p->instances->x += game->tile_size;
		if (game->map_array[game->y_ppos][game->x_ppos] == 'C')
		{
			ft_printf("You found an egg!\n");
			remove_collectable(game, game->x_ppos, game->y_ppos);
			ft_printf("collectables left:%i\n", game->c_count);
		}
		if (game->c_count == 0 && game->map_array
			[game->y_ppos][game->x_ppos] == 'E')
			end_game(game, 0);
	}
}
