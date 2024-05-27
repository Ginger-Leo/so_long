/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:41:53 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/08 14:18:00 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_e_images(t_game_list *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	img->txt_e = mlx_load_png("textures/E_block.png");
	if (img->txt_e == NULL)
		exit (1);
	img->img_e = mlx_texture_to_image(game->mlx_ptr, img->txt_e);
	mlx_delete_texture(img->txt_e);
	if (!mlx_resize_image(img->img_e, game->tile_size, game->tile_size))
		exit(1);
	while (game->map_array[y])
	{
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == 'E')
				mlx_image_to_window(game->mlx_ptr,
					img->img_e, game->tile_size * x, game->tile_size * y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_bg_img(t_game_list *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	img->txt_bg = mlx_load_png("textures/BG.png");
	if (img->txt_bg == NULL)
		exit (1);
	img->img_bg = mlx_texture_to_image(game->mlx_ptr, img->txt_bg);
	mlx_delete_texture(img->txt_bg);
	if (!mlx_resize_image(img->img_bg, game->tile_size, game->tile_size))
		exit(1);
	while (y < game->rows)
	{
		while (x < game->columns)
		{
			mlx_image_to_window(game->mlx_ptr, img->img_bg,
				game->tile_size * x, game->tile_size * y);
			x++;
		}
		x = 0;
		y++;
	}
}
