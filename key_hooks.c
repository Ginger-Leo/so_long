/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:43 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/08 14:14:25 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_controls(t_game_list *game, mlx_t *mlx)
{
	mlx_key_hook(mlx, &myhook, game);
}

void	myhook(mlx_key_data_t keyd, void *param)
{
	t_game_list	*game;

	game = param;
	if (keyd.key == MLX_KEY_ESCAPE || keyd.key == MLX_KEY_Q)
		end_game(game, 1);
	if (keyd.key == MLX_KEY_UP && keyd.action == MLX_PRESS)
		move_up(game);
	if (keyd.key == MLX_KEY_DOWN && keyd.action == MLX_PRESS)
		move_down(game);
	if (keyd.key == MLX_KEY_LEFT && keyd.action == MLX_PRESS)
		move_left(game);
	if (keyd.key == MLX_KEY_RIGHT && keyd.action == MLX_PRESS)
		move_right(game);
}
