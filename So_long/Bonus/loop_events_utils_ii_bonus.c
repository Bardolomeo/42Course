/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_events_utils_ii_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:49:51 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 17:34:50 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_up(int i, int j, t_map_mlx *mmlx)
{
	if (mmlx->map[i + 1][j] == '0')
	{
		mmlx->map[i + 1][j] = 'N';
		mmlx->map[i][j] = '0';
		mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
			mmlx->mlx.imgs[1].img, j * 50, i * 50);
	}
}

void	move_enemy_right(int i, int j, t_map_mlx *mmlx)
{
	if (mmlx->map[i][j - 1] == '0')
	{
		mmlx->map[i][j - 1] = 'N';
		mmlx->map[i][j] = '0';
		mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
			mmlx->mlx.imgs[1].img, j * 50, i * 50);
	}
}

void	move_enemy_left(int i, int j, t_map_mlx *mmlx)
{
	if (mmlx->map[i][j + 1] == '0')
	{
		mmlx->map[i][j + 1] = 'N';
		mmlx->map[i][j] = '0';
		mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
			mmlx->mlx.imgs[1].img, j * 50, i * 50);
	}
}
