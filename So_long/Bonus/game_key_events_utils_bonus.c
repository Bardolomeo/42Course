/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_events_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:56:50 by gsapio            #+#    #+#             */
/*   Updated: 2023/11/29 18:22:35 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_open(int h, int k, char **map, t_mlx mlx)
{
	map[h][k] = 'W';
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.imgs[4].img, k * 50,
		h * 50);
}

void	find_player(char **map, int *i, int *j)
{
	while (map[++(*i)])
	{
		*j = -1;
		while (map[*i][++(*j)])
			if (map[*i][(*j)] == 'P')
				break ;
		if (map[*i][*j] == 'P')
			break ;
	}
}

void	check_collectibles(char **map, t_mlx mlx)
{
	int	c_flag;
	int	i;
	int	j;
	int	h;
	int	k;

	i = -1;
	c_flag = 1;
	h = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				c_flag = 0;
			if (map[i][j] == 'E')
			{
				h = i;
				k = j;
			}
		}
	}
	if (c_flag == 1 && h != -1)
		exit_open(h, k, map, mlx);
}

void	game_win_lose(char flag, t_mlx mlx)
{
	if (flag == 'W')
	{
		ft_putstr_fd("Congrats, you made the Moon Flower bloom~\n", 1);
		mlx_loop_end(mlx.mlx_ptr);
	}
	if (flag == 'N')
	{
		ft_putstr_fd("Oh no! the satyrs took you...", 1);
		mlx_loop_end(mlx.mlx_ptr);
	}
}

int	close_game(t_map_mlx *mmlx)
{
	mlx_loop_end(mmlx->mlx.mlx_ptr);
	return (0);
}
