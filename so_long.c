/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:47:37 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/21 15:17:58 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_list		game;
	t_image			img;
	mlx_t			*mlx;
	int				fd;
	char			*buf;

	parsing(argc, argv[1]);
	fd = ft_open(argv[1]);
	buf = make_buf(3000);
	read(fd, buf, 3000);
	check_buf(buf, 3000);
	game.map_array = ft_split(buf, '\n');
	free(buf);
	map_checker(&game);
	mlx = mlx_init(game.columns * game.tile_size,
			game.rows * game.tile_size, "so_long", true);
	if (mlx == NULL)
		err_n_exit(2);
	game.mlx_ptr = mlx;
	game.img = &img;
	init_images(&game, &img);
	player_controls(&game, mlx);
	mlx_loop(game.mlx_ptr);
	return (0);
}
