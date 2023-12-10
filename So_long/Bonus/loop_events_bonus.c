/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:44:01 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/02 16:30:30 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	find_enemy(char **map, int *i, int *j)
{
	int	h;
	int	ene_numb;

	ene_numb = count_enemies(map);
	h = -1;
	while (++h < ene_numb)
	{
		i[h] = -1;
		while (map[++i[h]])
		{
			j[h] = -1;
			while (map[i[h]][++j[h]])
				if (map[i[h]][j[h]] == 'N')
					break ;
			if (map[i[h]][j[h]] == 'N')
			{
				map[i[h]][j[h]] = 'n';
				break ;
			}
		}
	}
	h = -1;
	while (++h < ene_numb)
		map[i[h]][j[h]] = 'N';
	return (ene_numb);
}

void	upload_frame(char *path, int *counter, t_map_mlx *mmlx, int h)
{
	int			i[10];
	int			j[10];
	int			temp;

	i[0] = -1;
	temp = -1;
	if (h == 5)
	{
		find_player(mmlx->map, &i[0], &j[0]);
		i[1] = -1;
		j[1] = -1;
	}
	else
	{
		temp = find_enemy(mmlx->map, i, j);
		i[temp] = -1;
		j[temp] = -1;
	}
	if (temp == 10)
		return ;
	mmlx->mlx.imgs[h].img = mlx_xpm_file_to_image(mmlx->mlx.mlx_ptr, path,
			&mmlx->mlx.imgs[h].wid, &mmlx->mlx.imgs[h].hei);
	put_and_free_img(i, j, h, mmlx);
	(*counter)++;
}

int	player_idle(t_map_mlx *mmlx)
{
	static int	counter;

	if (counter < 400)
		upload_frame(IDLE_1, &counter, mmlx, 5);
	else if (counter >= 400 && counter < 800)
		upload_frame(IDLE_2, &counter, mmlx, 5);
	else if (counter >= 800 && counter < 1200)
		upload_frame(IDLE_3, &counter, mmlx, 5);
	else if (counter >= 1200)
	{
		upload_frame(IDLE_4, &counter, mmlx, 5);
		if (counter >= 1600)
			counter = 0;
	}
	mlx_destroy_image(mmlx->mlx.mlx_ptr, mmlx->mlx.imgs[5].img);
	return (0);
}

int	enemy_idle(t_map_mlx *mmlx)
{
	static int	count_frame;

	if (count_frame < 700)
		upload_frame(ENEMY_1, &count_frame, mmlx, 6);
	else if (count_frame >= 700)
	{
		upload_frame(ENEMY_2, &count_frame, mmlx, 6);
		if (count_frame >= 1400)
			count_frame = 0;
	}
	return (0);
}

int	loop_events(t_map_mlx *mmlx)
{
	player_idle(mmlx);
	enemy_idle(mmlx);
	enemy_movement(mmlx);
	return (0);
}
