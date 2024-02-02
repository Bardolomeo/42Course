/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:02:00 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/23 21:51:28 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_matrix(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	free (map);
	return (0);
}

char	*get_cmd_flags(char **cmd)
{
	char	*temp;
	char	*temp2;
	char	*ret;

	cmd++;
	ret = ft_strdup(*cmd);
	if (!ret)
		return (NULL);
	while (*cmd)
	{
		temp = ft_strjoin(ret, " ");
		free(ret);
		if (!temp)
			return (NULL);
		temp2 = ft_strjoin(temp, *(cmd + 1));
		free(temp);
		if (!temp2)
			return (NULL);
		ret = temp2;
		cmd++;
	}
	return (ret);
}

int	error(char *type)
{
	perror(type);
	return (0);
}

int	init(t_pip *pipex)
{
	free(pipex->cmds);
	pipex->cmds = ft_calloc(pipex->ncmds + 1, sizeof(char **));
	free(pipex->path);
	pipex->path = ft_calloc(pipex->ncmds + 1, sizeof(char *));
	pipex->path[pipex->ncmds] = NULL;
	if (!pipex->cmds || !pipex->path)
		return (0);
	return (1);
}
