/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:54:29 by lstorey           #+#    #+#             */
/*   Updated: 2024/05/27 09:14:38 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# define ERR_ARGS "Error.\nWrong ammount or args.\n"
# define ERR_FILE "Error.\nWrong file type.\n"
# define ERR_MAP "Error.\nMap is invalid.\n"
# define ERR_MAP_SIZE "Error.\nMap too big!....or small.\n"
# define ERR_DIR "Error.\nFile is directory.\n"
# define ERR_MLX "Error.\nMlx failure.\n"
# define ERR_ELEMENTS "Error.\nIncorrect elements (C's, P's or E's).\n"
# define READ_ERR "Error.\nRead error.\n"
# define FLOOD_ERR "Error.\nFlood fill error.\n"
# define BLOCK 50
# define W_WIDTH 1600
# define W_HEIGHT 900

typedef struct s_image
{
	mlx_texture_t	*txt_0;
	mlx_texture_t	*txt_1;
	mlx_texture_t	*txt_c;
	mlx_texture_t	*txt_p;
	mlx_texture_t	*txt_e;
	mlx_texture_t	*txt_bg;
	mlx_image_t		*img_0;
	mlx_image_t		*img_1;
	mlx_image_t		*img_c;
	mlx_image_t		*img_p;
	mlx_image_t		*img_e;
	mlx_image_t		*img_bg;
}	t_image;

typedef struct s_game_list
{
	char			**map_array;	
	char			**map_copy;		
	int				rows;			
	int				columns;		
	int				p_count;		
	int				e_count;		
	int				c_count;		
	int				x_ppos;			
	int				y_ppos;						
	int				x_xpos;			
	int				y_xpos;
	int				steps;
	size_t			tile_size;
	t_image			*img;
	mlx_t			*mlx_ptr;
}	t_game_list;

/*			  			so_long_utils.c					*/
void				parsing(int argc, char *str);
int					ft_open(char *argv);
char				**copy_map(t_game_list *game);
void				check_buf(char *buf, size_t bytes_read);

/*			  			map_printer.c					*/
void				map_printer(char **map_array);

/*			  			struct_printer.c				*/
void				struct_printer(t_game_list game);

/*			  			map_checker.c					*/
void				map_checker(t_game_list *game);
void				check_shape(t_game_list *game);
void				check_elements(t_game_list *game);
void				check_walls(t_game_list *game);
void				check_route(t_game_list *game);

/*			  			free_n_exit.c					*/
void				free_map(char **map);

/*			  			init_elements.c					*/
void				check_letters(t_game_list *game);
void				init_player(t_game_list *game);
void				init_exit(t_game_list *game);
void				init_collectables(t_game_list *game);

/*			  			struct_printer.c				*/
void				struct_printer(t_game_list game);

/*			  			flood_fill.c					*/
void				flood_fill(t_game_list *game);
void				fill(int cur_y, int cur_x, t_game_list *game);
void				check_map(t_game_list *game);

/*			  			img_init.c					*/
void				init_images(t_game_list *game, t_image *img);
void				load_0_images(t_game_list *game, t_image *img);
void				load_1_images(t_game_list *game, t_image *img);
void				load_c_images(t_game_list *game, t_image *img);
void				load_p_images(t_game_list *game, t_image *img);

/*			  			img_init_utils.c					*/
void				load_e_images(t_game_list *game, t_image *img);
void				load_bg_img(t_game_list *game, t_image *img);

/*			  			so_long_utils_2.c					*/
void				err_n_exit(int i);
void				close_game(t_game_list *game, mlx_t *mlx);
void				remove_collectable(t_game_list *game, int x, int y);
void				end_game(t_game_list *game, int nb);
char				*make_buf(int i);

/*			  			key_hooks.c					*/
void				player_controls(t_game_list *game, mlx_t *mlx);
void				myhook(mlx_key_data_t keyd, void *param);

/*			  		player_movement.c						*/
void				move_up(t_game_list *game);
void				move_down(t_game_list *game);
void				move_left(t_game_list *game);
void				move_right(t_game_list *game);

#endif
