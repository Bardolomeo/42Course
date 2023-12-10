/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_error_management.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:58:52 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 17:34:17 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_map_mlx *mmlx)
{
	mmlx->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(mmlx->moves, 1);
	ft_putchar_fd('\n', 1);
}

int	check_sprites(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->imgs[++i].img)
		;
	if (i != 9)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		j = -1;
		while (++j < i)
			mlx_destroy_image(mlx->mlx_ptr, mlx->imgs[j].img);
		free_matrix(map);
		j = 9;
		while (--j > i)
			if (mlx->imgs[j].img)
				mlx_destroy_image(mlx->mlx_ptr, mlx->imgs[j].img);
		mlx_destroy_display(mlx->mlx_ptr);
		return (0);
	}
	return (1);
}
