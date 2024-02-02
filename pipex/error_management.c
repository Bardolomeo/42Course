/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:27:32 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/26 20:05:04 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(int argc, char **argv)
{
	if (argc != 5 || access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
	{
		errno = EINVAL;
		if (argc != 5)
			perror("Error");
		else if (access(argv[1], F_OK) < 0 || (access(argv[1], R_OK) < 0))
			perror("Error");
		return (0);
	}
	if (!ft_strncmp(argv[1], argv[argc - 1], ft_strlen(argv[1]) + 100))
		return (0);
	if (*argv[argc - 1] == 0)
	{
		perror("Error");
		return (0);
	}
	if (access(argv[argc - 1], F_OK) == 0)
	{
		if (access(argv[argc - 1], W_OK) < 0)
		{
			perror("Error");
			return (0);
		}
	}
	return (1);
}

int	check_cmds(int argc, char **argv, t_pip *pipex, char **envp)
{
	int	i;
	int	j;

	i = -1;
	j = 2;
	pipex->ncmds = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		pipex->ncmds = argc - 4;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		j = 3;
	if (!init(pipex))
		return (error("Init"));
	pipex->cmds[pipex->ncmds] = NULL;
	while (++i < pipex->ncmds)
	{
		pipex->cmds[i] = ft_split(argv[j], ' ');
		if (!pipex->cmds[i])
			return (1);
		j++;
	}
	if (!check_cmds_binaries(pipex->cmds, envp, pipex))
		return (0);
	return (1);
}

int	check_cmds_binaries(char ***cmds, char **envp, t_pip *pipex)
{
	char	**path;
	char	*temp;
	int		i;

	while (ft_strncmp(*envp, "PATH", 4))
		envp++;
	path = ft_split(*envp, ':');
	if (!path)
		return (0);
	temp = ft_strtrim(*path, "PATH=");
	if (!temp)
		return (free_matrix(path));
	free(path[0]);
	path[0] = temp;
	i = -1;
	while (cmds[++i])
	{
		if (!find_binary(cmds, path, i, pipex))
		{
			ft_printf("binary: command not found: %s\n", cmds[i][0]);
			return (free_matrix(path));
		}
	}
	free_matrix(path);
	return (1);
}

int	find_binary(char ***cmds, char **path, int ind, t_pip *pipex)
{
	char	*str;

	if (!pipex->path || cmds[ind][0] == 0)
		return (0);
	if (ft_strchr(pipex->cmds[ind][0], '/'))
	{
		str = ft_strdup(ft_strrchr(pipex->cmds[ind][0], '/'));
		free(pipex->cmds[ind][0]);
		pipex->cmds[ind][0] = ft_strdup(++str);
		free(--str);
	}
	if (is_cmd_path(pipex, ind, path))
		return (1);
	return (0);
}

int	is_cmd_path(t_pip *pipex, int ind, char **path)
{
	char	*temp;
	char	*temp2;
	int		i;

	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		temp2 = ft_strjoin(temp, pipex->cmds[ind][0]);
		free(temp);
		if (access(temp2, X_OK) == 0)
		{
			pipex->path[ind] = temp2;
			return (1);
		}
		else
			free(temp2);
	}
	return (0);
}
