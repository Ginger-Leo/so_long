/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:03:15 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/02 14:17:13 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_printer(t_game_list game)
{
	ft_printf("rows    : %i\n", game.rows);
	ft_printf("columns : %i\n", game.columns);
	ft_printf("P's     : %i\n", game.p_count);
	ft_printf("E's     : %i\n", game.e_count);
	ft_printf("C's     : %i\n", game.c_count);
	ft_printf("X P pos : %i\n", game.x_ppos);
	ft_printf("Y P pos : %i\n", game.y_ppos);
	ft_printf("X X pos : %i\n", game.x_xpos);
	ft_printf("Y X pos : %i\n", game.y_xpos);
	ft_printf("tilesize: %i\n", game.tile_size);
}
