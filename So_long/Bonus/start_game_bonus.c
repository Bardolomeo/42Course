/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:30 by gsapio            #+#    #+#             */
/*   Updated: 2023/11/29 18:23:07 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	upload_sprites(t_mlx *mlx)
{
	mlx->imgs[0].img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL,
			&mlx->imgs[0].wid, &mlx->imgs[0].hei);
	mlx->imgs[1].img = mlx_xpm_file_to_image(mlx->mlx_ptr, GROUND,
			&mlx->imgs[1].wid, &mlx->imgs[1].hei);
	mlx->imgs[2].img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLECT,
			&mlx->imgs[2].wid, &mlx->imgs[2].hei);
	mlx->imgs[3].img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT_C,
			&mlx->imgs[3].wid, &mlx->imgs[3].hei);
	mlx->imgs[4].img = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT_O,
			&mlx->imgs[4].wid, &mlx->imgs[4].hei);
	mlx->imgs[5].img = mlx_xpm_file_to_image(mlx->mlx_ptr, IDLE_1,
			&mlx->imgs[5].wid, &mlx->imgs[5].hei);
	mlx->imgs[6].img = mlx_xpm_file_to_image(mlx->mlx_ptr, ENEMY_2,
			&mlx->imgs[6].wid, &mlx->imgs[6].hei);
	mlx->imgs[7].img = NULL;
}

void	get_sprites_addr(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (mlx->imgs[++i].img)
		mlx->imgs[i].addr = mlx_get_data_addr(mlx->imgs[i].img,
				&mlx->imgs[i].bits_per_pixel, &mlx->imgs[i].line_length,
				&mlx->imgs[i].endian);
}

void	image_to_window(char **map, t_mlx *mlx, int i, int j)
{
	if (map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->imgs[5].img, j * 50, i * 50);
	if (map[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->imgs[1].img, j * 50, i * 50);
	if (map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->imgs[0].img, j * 50, i * 50);
	if (map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->imgs[2].img, j * 50, i * 50);
	if (map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->imgs[3].img, j * 50, i * 50);
	if (map[i][j] == 'N')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->imgs[6].img, j * 50, i * 50);
}

void	initialize_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		j = -1;
		while (++j < (int)ft_strlen(map[i]))
		{
			image_to_window(map, mlx, i, j);
		}
	}
}

int	start_game(t_mlx *mlx, char **map)
{
	int	size[2];

	size[1] = 0;
	size[0] = ft_strlen(map[0]) * 50;
	while (map[size[1]])
		size[1]++;
	size[1] *= 50;
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, size[0], size[1], "Moon Bloom");
	if (!mlx->mlx_win)
	{
		free_matrix(map);
		return (0);
	}
	upload_sprites(mlx);
	if (!check_sprites(mlx, map))
		return (0);
	get_sprites_addr(mlx);
	initialize_map(mlx, map);
	return (1);
}
