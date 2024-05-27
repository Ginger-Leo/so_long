/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:09:58 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/17 11:37:21 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_n_exit(int i)
{
	if (i == 1)
	{
		ft_putstr_fd(ERR_ARGS, 2);
		exit(1);
	}
	if (i == 2)
	{
		ft_putstr_fd(ERR_MLX, 2);
		exit(1);
	}
}

void	close_game(t_game_list *game, mlx_t *mlx)
{
	mlx_delete_image(mlx, game->img->img_0);
	mlx_delete_image(mlx, game->img->img_1);
	mlx_delete_image(mlx, game->img->img_c);
	mlx_delete_image(mlx, game->img->img_p);
	mlx_delete_image(mlx, game->img->img_e);
	mlx_delete_image(mlx, game->img->img_bg);
}

void	end_game(t_game_list *game, int nb)
{
	if (nb == 0)
		ft_printf("You did it you craazy son-of-a-bitch!!!\n");
	else if (nb == 1)
		ft_printf("Boooooo, quitter!\n");
	mlx_close_window(game->mlx_ptr);
	close_game(game, game->mlx_ptr);
	mlx_terminate(game->mlx_ptr);
	exit(nb);
}

void	remove_collectable(t_game_list *game, int x, int y)
{
	int	i;

	i = 0;
	x = x * game->tile_size + 18;
	y = y * game->tile_size + 18;
	while (&game->img->img_c->instances[i])
	{
		if (game->img->img_c->instances[i].x == x
			&& game->img->img_c->instances[i].y == y)
		{
			game->img->img_c->instances[i].enabled = false;
			game->c_count--;
			game->map_array[game-> y_ppos][game->x_ppos] = '0';
			if (game->c_count == 0)
				ft_printf("Get to the coop little chicken!\n");
			return ;
		}
		i++;
	}
}

char	*make_buf(int i)
{
	char	*buf;

	buf = ft_calloc(i, sizeof(char));
	if (buf == NULL)
		err_n_exit(1);
	return (buf);
}
