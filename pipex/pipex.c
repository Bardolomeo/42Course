/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:15:28 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/23 20:03:37 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	program(t_pip *pip, char **envp, char **argv, int argc)
{
	int		fd_pipe[2];
	int		i;

	i = 0;
	pip->fd[0] = open(argv[1], O_RDONLY);
	if (pip->fd[0] < 0)
		return (error("open input"));
	if (ft_strncmp(argv[1], "here_doc", 9))
		pip->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		pip->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->fd[1] < 0)
		return (error("open output"));
	if (dup2(pip->fd[0], STDIN_FILENO) == -1)
		return (error("first dup2"));
	while (i < pip->ncmds)
		if (!fork_manager(pip, fd_pipe, envp, &i))
			return (0);


	return (1);
}

int	fork_manager(t_pip *pip, int *fd_pipe, char **envp, int *i)
{
	if (pipe(fd_pipe) == -1)
		return (error("pipe"));
	pip->pid = fork();
	if (pip->pid == -1)
		return (error("pipe"));
	if (pip->pid == 0)
	{
		if (!child_manager(pip, fd_pipe, envp, i))
			return (0);
	}
	else
	{
		(*i)++;
		if (pip->ncmds != *i)
			if (close(fd_pipe[1]) == -1)
				return (error("close"));
		if (dup2(fd_pipe[0], STDIN_FILENO))
			return (error("last dup2"));
	}
	return (1);
}

int	child_manager(t_pip *pip, int *fd_pipe, char **envp, int *i)
{
	if (close(fd_pipe[0]) == -1)
		return (error("close"));
	if (*i == pip->ncmds - 1)
	{
		if (dup2(pip->fd[1], STDOUT_FILENO) == -1)
			return (error("dup last"));
	}
	else
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			return (error("dup"));
	execve(pip->path[*i], pip->cmds[*i], envp);
	ft_printf("failed to execute command: %s", pip->cmds[*i][0]);
	return (1);
}

void	cleanup(t_pip *pip)
{
	int	i;
	int	j;

	i = -1;
	while (pip->cmds[++i])
	{
		j = -1;
		while (pip->cmds[i][++j])
			free(pip->cmds[i][j]);
		free(pip->cmds[i]);
	}
	i = -1;
	while (pip->path[++i])
		free(pip->path[i]);
	free(pip->path);
	free(pip->cmds);
	close(pip->fd[0]);
	close(pip->fd[1]);
}

t_pip	default_values(void)
{
	t_pip	ret;

	ret.fd[0] = 0;
	ret.fd[1] = 0;
	ret.limit = NULL;
	ret.ncmds = 0;
	ret.cmds = ft_calloc(1, sizeof(char **));
	ret.path = ft_calloc(1, sizeof(char *));
	return (ret);
}
