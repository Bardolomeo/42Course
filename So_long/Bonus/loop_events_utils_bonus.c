/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_events_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:38:50 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 16:44:43 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_down(int i, int j, t_map_mlx *mmlx)
{
	if (mmlx->map[i - 1][j] == '0')
	{
		mmlx->map[i - 1][j] = 'N';
		mmlx->map[i][j] = '0';
		mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
			mmlx->mlx.imgs[1].img, j * 50, i * 50);
	}
}

void	move_enemy(t_map_mlx *mmlx, int i, int j)
{
	static int	counter;

	if (counter % 2600 == 0)
	{
		if (rand() % 4 == 0)
		{
			move_enemy_up(i, j, mmlx);
			counter--;
		}
		else if (rand() % 4 == 1)
		{
			move_enemy_down(i, j, mmlx);
			counter--;
		}
		else if (rand() % 4 == 2)
		{
			move_enemy_left(i, j, mmlx);
			counter--;
		}
		else if (rand() % 4 == 3)
			move_enemy_right(i, j, mmlx);
	}
	counter++;
}

void	enemy_movement(t_map_mlx *mmlx)
{
	int	i[10];
	int	j[10];
	int	temp;
	int	k;

	temp = find_enemy(mmlx->map, i, j);
	i[temp] = -1;
	j[temp] = -1;
	k = -1;
	while (i[++k] != -1)
		move_enemy(mmlx, i[k], j[k]);
}

void	put_and_free_img(int *i, int *j, int h, t_map_mlx *mmlx)
{
	int	k;

	k = -1;
	while (i[++k] != -1)
	{
		mlx_put_image_to_window(mmlx->mlx.mlx_ptr, mmlx->mlx.mlx_win,
			mmlx->mlx.imgs[h].img, j[k] * 50, i[k] * 50);
	}
	if (h == 6)
		mlx_destroy_image(mmlx->mlx.mlx_ptr, mmlx->mlx.imgs[h].img);
}

int	count_enemies(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	ret = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'N')
				ret++;
	}
	if (ret >= 10)
		return (0);
	return (ret);
}
