/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map_manager_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:30:34 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 15:47:47 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_matrix(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free (map);
	return (NULL);
}

char	**ft_matdup(char **mat)
{
	char	**dup;
	int		count;

	count = 0;
	while (mat[count])
		count++;
	dup = (char **)malloc((count + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	count = -1;
	while (mat[++count])
	{
		dup[count] = ft_strdup(mat[count]);
		if (!dup[count])
			return (free_matrix(dup));
	}
	dup[count] = NULL;
	return (dup);
}

void	verify_and_fill(char **map, int *i, int j, int *found_ele)
{
	if (map[*i][j] == 'P')
	{
		found_ele[0] = 1;
		if (map[(*i) - 1][j] == 'E')
			manage_exit(map, (*i) - 1, j, found_ele);
		if (map[(*i) - 1][j] != '1' && map[(*i) - 1][j] != 'P'
				&& map[(*i) - 1][j] != 'E')
		{
			if (map[(*i) - 1][j] == 'C')
				found_ele[1]++;
			map[(*i) - 1][j] = 'P';
			*i = 0;
		}
		if (map[(*i) + 1][j] == 'E')
			manage_exit(map, (*i) + 1, j, found_ele);
		if (map[(*i) + 1][j] != '1' && map[(*i) + 1][j] != 'P'
				&& map[(*i) + 1][j] != 'E')
		{
			if (map[(*i) + 1][j] == 'C')
				found_ele[1]++;
			map[(*i) + 1][j] = 'P';
			*i = 0;
		}
		verify_path_horizontal(map, i, j, found_ele);
	}
}

int	check_path(char **cpy, char **map)
{
	int	i;
	int	j;
	int	found_ele[3];

	i = -1;
	while (++i < 3)
		found_ele[i] = 0;
	i = -1;
	while (cpy[++i])
	{
		j = -1;
		while (cpy[i][++j])
			verify_and_fill(cpy, &i, j, found_ele);
	}
	i = -1;
	if (!elements_check(found_ele, map))
		return (0);
	free_matrix(cpy);
	return (1);
}

int	mc_path(char **map)
{
	char	**cpy;

	cpy = ft_matdup(map);
	if (!cpy)
		return (0);
	if (!check_path(cpy, map))
		return (0);
	return (1);
}
