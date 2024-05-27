/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:57:42 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/27 09:14:19 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_game_list *game)
{
	check_shape(game);
	check_elements(game);
	check_walls(game);
	check_route(game);
	return ;
}

void	check_shape(t_game_list *game)
{
	static int	i = 0;
	int			len;

	len = ft_strlen(game->map_array[i]);
	game->columns = len;
	if (len > 50 || len < 3)
	{
		ft_putstr_fd(ERR_MAP_SIZE, 2);
		exit (1);
	}
	while (game->map_array[i])
	{
		if ((int)ft_strlen(game->map_array[i]) != game->columns)
		{
			ft_putstr_fd(ERR_MAP, 2);
			exit(1);
		}
		i++;
	}
	game->rows = i;
	if (i > 25)
	{
		ft_putstr_fd(ERR_MAP_SIZE, 2);
		exit (1);
	}
}

void	check_elements(t_game_list *game)
{
	check_letters(game);
	init_player(game);
	init_exit(game);
	init_collectables(game);
	game->tile_size = 50;
	game->steps = 0;
	if (game->c_count < 1 || game->p_count != 1 || game->e_count != 1)
	{
		ft_putstr_fd(ERR_ELEMENTS, 2);
		exit (1);
	}
}

void	check_walls(t_game_list *game)
{
	static int	j = 0;

	while (game->map_array[0][j] && game->map_array[game->rows - 1][j])
	{
		if (game->map_array[0][j] != '1' ||
		game->map_array[game->rows - 1][j] != '1')
		{
			ft_putstr_fd(ERR_MAP, 2);
			exit (1);
		}
		j++;
	}
	j = 0;
	while (game->map_array[j] && game->map_array[j][game->columns - 1])
	{
		if (game->map_array[j][0] != '1' ||
		game->map_array[j][game->columns - 1] != '1')
		{
			ft_putstr_fd(ERR_MAP, 2);
			exit (1);
		}
		j++;
	}
}

void	check_route(t_game_list *game)
{
	game->map_copy = copy_map(game);
	flood_fill(game);
}
