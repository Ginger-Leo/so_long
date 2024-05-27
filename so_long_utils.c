/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:48 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/20 12:27:32 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_dir(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_putstr_fd(ERR_DIR, 2);
		exit(1);
	}
}

void	parsing(int argc, char *str)
{
	static int	i = 0;

	if (argc != 2)
		err_n_exit(1);
	is_dir(str);
	while (str[i])
	{
		if (ft_strncmp(str, ".ber", 4) == 0)
		{
			i += 4;
			if (str[i] != '\0')
			{
				ft_putstr_fd(ERR_FILE, 2);
				exit(1);
			}
		}
		i++;
	}
}

int	ft_open(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(READ_ERR, 2);
		exit(1);
	}
	return (fd);
}

char	**copy_map(t_game_list *game)
{
	int		y;

	y = 0;
	game->map_copy = malloc(sizeof(char *) * (game->rows + 1));
	if (game->map_copy == NULL)
		return (NULL);
	while (game->map_array[y])
	{
		game->map_copy[y] = ft_strdup(game->map_array[y]);
		y++;
	}
	game->map_copy[y] = NULL;
	return (game->map_copy);
}

void	check_buf(char *buf, size_t bytes_read)
{
	size_t	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buf[i] == '\n')
		{
			if (buf[i + 1] && buf[i + 1] == '\n')
			{
				ft_putstr_fd(ERR_MAP, 2);
				free(buf);
				exit(1);
			}
		}
		i++;
	}
}
