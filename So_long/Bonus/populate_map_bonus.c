/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:40:25 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/03 17:34:32 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**fill_matrix(int count_col, char *map_name)
{
	char	**map;
	int		fd;
	int		i;

	map = (char **)ft_calloc(count_col + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(map_name, O_RDONLY);
	map[0] = get_next_line(fd);
	if (!map[0])
		return (free_matrix(map));
	map[0][ft_strlen(map[0]) - 1] = 0;
	i = 0;
	while (map[i])
	{
		map[++i] = get_next_line(fd);
		if (!map[i] && i != count_col)
			return (free_matrix(map));
		if (i != count_col)
			map[i][ft_strlen(map[i]) - 1] = 0;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**populate_map(char *map_name)
{
	char	**map;
	int		fd;
	int		count_col;
	char	*temp;

	fd = open(map_name, O_RDONLY);
	count_col = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		count_col++;
	}
	close(fd);
	if (count_col < 3)
		return (NULL);
	map = fill_matrix(count_col, map_name);
	if (!invalid_map_manager(count_col, map))
		return (NULL);
	return (map);
}
