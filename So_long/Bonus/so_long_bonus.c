/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:14:34 by gsapio            #+#    #+#             */
/*   Updated: 2023/11/25 18:52:28 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_game(char **map, t_mlx *mlx)
{
	int	i;

	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	i = -1;
	while (mlx->imgs[++i].img != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->imgs[i].img);
	free_matrix(map);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

char	input_error_manager(int argc, char **argv)
{
	char	*check_ext;
	char	*ext;

	ext = ft_strdup("ber");
	if (!ext)
		return (1);
	if (argc != 2)
		ft_putstr_fd("Error\nWrong number of arguments (<mapname>.ber)", 1);
	if (argc != 2)
	{
		free(ext);
		return (1);
	}
	check_ext = ft_strrchr(argv[1], '.');
	if (!check_ext || ft_strncmp(check_ext + 1, ext, 3))
	{
		free(ext);
		ft_putstr_fd("Error\nInvalid file name (<mapname>.ber)", 1);
		return (1);
	}
	free(ext);
	return (0);
}

int	main(int argc, char *argv[])
{
	char		**map;
	t_mlx		mlx;
	t_map_mlx	map_mlx;

	if (input_error_manager(argc, argv))
		return (-1);
	mlx.mlx_ptr = mlx_init();
	map = populate_map(argv[1]);
	if (!map)
		return (-1);
	if (!start_game(&mlx, map))
	{
		ft_putstr_fd("An error occurred with sprites or with the window", 1);
		return (-1);
	}
	map_mlx.map = map;
	map_mlx.mlx = mlx;
	map_mlx.moves = 0;
	mlx_key_hook(mlx.mlx_win, game_key_events, &map_mlx);
	mlx_hook(map_mlx.mlx.mlx_win, 17, 1L << 2, close_game, &map_mlx);
	mlx_loop_hook(map_mlx.mlx.mlx_ptr, loop_events, &map_mlx);
	mlx_loop(mlx.mlx_ptr);
	destroy_game(map, &mlx);
	return (0);
}
