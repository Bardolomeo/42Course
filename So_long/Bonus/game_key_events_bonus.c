/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_events_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:44:12 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/04 13:16:45 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_up(t_map_mlx *mmlx)
{
	int	i;
	int	j;

	j = -1;
	find_player(mmlx->map, &j, &i);
	if (mmlx->map[j - 1][i] != '1')
	{
		if (mmlx->map[j - 1][i] == 'W' || mmlx->map[j - 1][i] == 'N')
			game_win_lose(mmlx->map[j - 1][i], mmlx->mlx);
		if (mmlx->map[j - 1][i] == '0' || mmlx->map[j - 1][i] == 'C')
		{
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 0, 0);
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 50, 0);
			mmlx->map[j][i] = '0';
			mmlx->map[j - 1][i] = 'P';
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[1].img, i * 50, j * 50);
			print_moves(mmlx);
		}
	}
	check_collectibles(mmlx->map, mmlx->mlx);
}

void	player_down(t_map_mlx *mmlx)
{
	int	i;
	int	j;

	j = -1;
	find_player(mmlx->map, &j, &i);
	if (mmlx->map[j + 1][i] != '1')
	{
		if (mmlx->map[j + 1][i] == 'W' || mmlx->map[j + 1][i] == 'N')
			game_win_lose(mmlx->map[j + 1][i], mmlx->mlx);
		if (mmlx->map[j + 1][i] == '0' || mmlx->map[j + 1][i] == 'C')
		{
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 0, 0);
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 50, 0);
			mmlx->map[j][i] = '0';
			mmlx->map[j + 1][i] = 'P';
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[1].img, i * 50, j * 50);
			print_moves(mmlx);
		}
	}
	check_collectibles(mmlx->map, mmlx->mlx);
}

void	player_left(t_map_mlx *mmlx)
{
	int	i;
	int	j;

	j = -1;
	find_player(mmlx->map, &j, &i);
	if (mmlx->map[j][i - 1] != '1')
	{
		if (mmlx->map[j][i - 1] == 'W' || mmlx->map[j][i - 1] == 'N')
			game_win_lose(mmlx->map[j][i - 1], mmlx->mlx);
		if (mmlx->map[j][i - 1] == '0' || mmlx->map[j][i - 1] == 'C')
		{
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 0, 0);
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 50, 0);
			mmlx->map[j][i] = '0';
			mmlx->map[j][i - 1] = 'P';
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[1].img, i * 50, j * 50);
			print_moves(mmlx);
		}
	}
	check_collectibles(mmlx->map, mmlx->mlx);
}

void	player_right(t_map_mlx *mmlx)
{
	int	i;
	int	j;

	j = -1;
	find_player(mmlx->map, &j, &i);
	if (mmlx->map[j][i + 1] != '1')
	{
		if (mmlx->map[j][i + 1] == 'W' || mmlx->map[j][i + 1] == 'N')
			game_win_lose(mmlx->map[j][i + 1], mmlx->mlx);
		if (mmlx->map[j][i + 1] == '0' || mmlx->map[j][i + 1] == 'C')
		{
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 0, 0);
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[0].img, 50, 0);
			mmlx->map[j][i] = '0';
			mmlx->map[j][i + 1] = 'P';
			mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
				mmlx->mlx.imgs[1].img, i * 50, j * 50);
			print_moves(mmlx);
		}
	}
	check_collectibles(mmlx->map, mmlx->mlx);
}

int	game_key_events(int keycode, t_map_mlx *mmlx)
{
	if (keycode == 0xff1b)
		mlx_loop_end(mmlx->mlx.mlx_ptr);
	if (keycode == 'w')
		player_up(mmlx);
	if (keycode == 's')
		player_down(mmlx);
	if (keycode == 'a')
		player_left(mmlx);
	if (keycode == 'd')
		player_right(mmlx);
	return (0);
}
