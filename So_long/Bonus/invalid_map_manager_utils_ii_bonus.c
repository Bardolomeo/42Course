/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_manager_utils_ii_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:01:29 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 15:46:58 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	verify_path_horizontal(char **map, int *i, int j, int *found_ele)
{
	if (map[(*i)][j - 1] == 'E')
		manage_exit(map, *i, j - 1, found_ele);
	if (map[(*i)][j - 1] != '1' && map[(*i)][j - 1] != 'P'
			&& map[(*i)][j - 1] != 'E')
	{
		if (map[(*i)][j - 1] == 'C')
			found_ele[1]++;
		map[(*i)][j - 1] = 'P';
		*i = 0;
	}
	if (map[(*i)][j + 1] == 'E')
		manage_exit(map, *i, j + 1, found_ele);
	if (map[(*i)][j + 1] != '1' && map[(*i)][j + 1] != 'P'
			&& map[(*i)][j + 1] != 'E')
	{
		if (map[(*i)][j + 1] == 'C')
			found_ele[1]++;
		map[(*i)][j + 1] = 'P';
		*i = 0;
	}
}

int	character_control(char **map, int i, int j, int p_count)
{
	if ((map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C'
			&& map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'N') || p_count > 1)
		return (0);
	return (1);
}

int	elements_check(int *found_ele, char **map)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C')
				count++;
	}
	if (found_ele[0] != 1 || found_ele[2] != 1 || found_ele[1] != count)
	{
		ft_putstr_fd("Error\nWrong number of elements, or paths", 1);
		return (!free_matrix(map) - 1);
	}
	return (1);
}

void	manage_exit(char **map, int i, int j, int *found_ele)
{
	found_ele[2]++;
	map[i][j] = '1';
}
