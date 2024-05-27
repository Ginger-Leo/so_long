/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:56:19 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/17 13:33:27 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_game_list *game, t_image *img)
{
	load_bg_img(game, img);
	load_0_images(game, img);
	load_1_images(game, img);
	load_c_images(game, img);
	load_e_images(game, img);
	load_p_images(game, img);
}

void	load_0_images(t_game_list *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	img->txt_0 = mlx_load_png("textures/0_block.png");
	if (img->txt_0 == NULL)
		exit (1);
	img->img_0 = mlx_texture_to_image(game->mlx_ptr, img->txt_0);
	mlx_delete_texture(img->txt_0);
	if (!mlx_resize_image(img->img_0, game->tile_size, game->tile_size))
		exit(1);
	while (game->map_array[y])
	{
		x = 0;
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == '0' || game->map_array[y][x] == 'P' ||
			game->map_array[y][x] == 'C' || game->map_array[y][x] == 'E' )
				mlx_image_to_window(game->mlx_ptr, img->img_0,
					game->tile_size * x, game->tile_size * y);
			x++;
		}
		y++;
	}
}

void	load_1_images(t_game_list *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	img->txt_1 = mlx_load_png("textures/1_block.png");
	if (img->txt_1 == NULL)
		exit (1);
	img->img_1 = mlx_texture_to_image(game->mlx_ptr, img->txt_1);
	mlx_delete_texture(img->txt_1);
	if (!mlx_resize_image(img->img_1, game->tile_size, game->tile_size))
		exit(1);
	while (game->map_array[y])
	{
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == '1')
				mlx_image_to_window(game->mlx_ptr, img->img_1,
					game->tile_size * x, game->tile_size * y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_c_images(t_game_list *game, t_image *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	img->txt_c = mlx_load_png("textures/C_block.png");
	if (img->txt_c == NULL)
		exit (1);
	img->img_c = mlx_texture_to_image(game->mlx_ptr, img->txt_c);
	mlx_delete_texture(img->txt_c);
	if (!mlx_resize_image(img->img_c, game->tile_size / 3, game->tile_size / 3))
		exit(1);
	while (game->map_array[y])
	{
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == 'C')
				mlx_image_to_window(game->mlx_ptr, img->img_c,
					game->tile_size * x + 18, game->tile_size * y + 18);
			x++;
		}
		x = 0;
		y++;
	}
}

void	load_p_images(t_game_list *game, t_image *img)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	img->txt_p = mlx_load_png("textures/P_block.png");
	if (img->txt_p == NULL)
		exit (1);
	img->img_p = mlx_texture_to_image(game->mlx_ptr, img->txt_p);
	mlx_delete_texture(img->txt_p);
	if (!mlx_resize_image(img->img_p, game->tile_size / 2, game->tile_size / 2))
		exit(1);
	while (game->map_array[y])
	{
		while (game->map_array[y][x])
		{
			if (game->map_array[y][x] == 'P')
				mlx_image_to_window(game->mlx_ptr, img->img_p,
					game->tile_size * x + 15, game->tile_size * y + 15);
			x++;
		}
		x = 0;
		y++;
	}
}
