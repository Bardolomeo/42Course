/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_manager_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:38:09 by gsapio            #+#    #+#             */
/*   Updated: 2023/11/29 18:29:49 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mc_walls(char **map, int col)
{
	int	i;

	i = -1;
	while (map[0][++i] && map[col - 1][i])
	{
		if (map[0][i] != '1' || map[col - 1][i] != '1')
		{
			ft_putstr_fd("Error\nMap not walled", 1);
			free_matrix(map);
			return (0);
		}
	}
	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			ft_putstr_fd("Error\nMap not walled", 1);
			free_matrix(map);
			return (0);
		}
	}
	return (1);
}

int	mc_same_size_raws(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_putstr_fd("Error\nInvalid map (raws lenght)", 1);
			free_matrix(map);
			return (0);
		}
		i++;
	}
	return (1);
}

int	mc_invalid_char(char **map)
{
	int	i;
	int	j;
	int	p_count;

	i = -1;
	j = -1;
	p_count = 0;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (!character_control(map, i, j, p_count))
			{
				ft_putstr_fd("Error\nInvalid characters in map", 1);
				i = 0;
				free_matrix(map);
				return (0);
			}
			if (map[i][j] == 'P')
				p_count++;
		}
		j = -1;
	}
	return (1);
}

int	mc_size(char **map, int col)
{
	int	raw_len;

	raw_len = ft_strlen(map[0]);
	if ((raw_len - 1 < 4 && col < 5) || (col < 4 && raw_len - 1 < 5))
	{
		ft_putstr_fd("Error\n Map too small", 1);
		free_matrix(map);
		return (0);
	}
	return (1);
}

int	invalid_map_manager(int col, char **map)
{
	if (col < 3)
	{
		ft_putstr_fd("Error\nMap too small", 1);
		return (0);
	}
	if (!map)
		return (0);
	if (!mc_size(map, col) || !mc_invalid_char(map)
		|| !mc_same_size_raws(map) || !mc_walls(map, col) || !mc_path(map))
		return (0);
	return (1);
}
