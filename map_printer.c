/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:04:03 by lstorey           #+#    #+#             */
/*   Updated: 2024/04/24 10:35:45 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_printer(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		ft_printf("%s\n", map_array[i]);
		i++;
	}
}
