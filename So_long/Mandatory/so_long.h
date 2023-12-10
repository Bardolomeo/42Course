/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:57:32 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 15:45:18 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# define WALL "./textures/tree_b.xpm"
# define GROUND "./textures/tile.xpm"
# define COLLECT "./textures/collectible.xpm"
# define EXIT_C "./textures/exit_closed.xpm"
# define EXIT_O "./textures/exit_open.xpm"
# define IDLE_1 "./textures/char_idle_f1.xpm"
# define IDLE_2 "./textures/char_idle_f2.xpm"
# define ENEMY_1 "./textures/enemy_f1.xpm"
# define ENEMY_2 "./textures/enemy_f2.xpm"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		wid;
	int		hei;
}	t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	imgs[10];
}	t_mlx;

typedef struct s_map_mlx
{
	t_mlx	mlx;
	char	**map;
	int		moves;
}	t_map_mlx;

void	verify_path_horizontal(char **map, int *i, int j, int *found_ele);
char	**free_matrix(char **map);
int		mc_path(char **map);
char	**populate_map(char *map_name);
int		invalid_map_manager(int col, char **map);
int		start_game(t_mlx *mlx, char **map);
int		character_control(char **map, int i, int j, int p_count);
int		check_sprites(t_mlx *mlx, char **map);
int		game_key_events(int keycode, t_map_mlx *mmlx);
void	find_player(char **map, int *i, int *j);
void	check_collectibles(char **map, t_mlx mlx);
void	game_win_lose(char flag, t_mlx mlx);
int		close_game(t_map_mlx *mmlx);
void	print_moves(t_map_mlx *mmlx);
int		elements_check(int *found_ele, char **map);
void	manage_exit(char **map, int i, int j, int *found_ele);

#endif
