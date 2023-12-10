/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_error_management_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:58:52 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 17:35:06 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(t_map_mlx *mmlx)
{
	char	*moves;

	mmlx->moves++;
	mlx_string_put(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win, 5, 20,
		0x00FFFF00, "Moves:");
	moves = ft_itoa(mmlx->moves);
	mlx_string_put(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win, 50, 20,
		0x00FFFF00, moves);
	free(moves);
}

int	check_sprites(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->imgs[++i].img)
		;
	if (i != 7)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		j = -1;
		while (++j < i)
			mlx_destroy_image(mlx->mlx_ptr, mlx->imgs[j].img);
		free_matrix(map);
		j = 7;
		while (--j > i)
			mlx_destroy_image(mlx->mlx_ptr, mlx->imgs[j].img);
		mlx_destroy_display(mlx->mlx_ptr);
		return (0);
	}
	return (1);
}
