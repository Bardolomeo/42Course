/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:47:22 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/26 19:44:00 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc_func(char *limit)
{
	int		fd;
	char	*str;
	char	*lim;

	fd = open("here_doc", O_WRONLY | O_CREAT, 0777);
	dup2(fd, 1);
	if (*limit == 0)
		lim = ft_strdup("\n");
	else
		lim = ft_strdup(limit);
	str = get_next_line(0);
	while (ft_strncmp(str, lim, ft_strlen(lim)))
	{
		ft_printf("%s", str);
		free(str);
		str = get_next_line(0);
		if (!str)
		{
			free(lim);
			perror("here_doc");
			return (0);
		}
	}
	free_strings(str, lim);
	return (1);
}

void	cleanup_bonus(t_pip *pip)
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
	free(pip->cmds);
	free(pip->path);
	close(pip->fd[0]);
	close(pip->fd[1]);
	unlink("here_doc");
}

int	program_bonus(t_pip *pip, char **envp, char **argv, int argc)
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
		pip->fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pip->fd[1] < 0)
		return (error("open output"));
	if (dup2(pip->fd[0], STDIN_FILENO) == -1)
		return (error("first dup2"));
	while (i < pip->ncmds)
		if (!fork_manager(pip, fd_pipe, envp, &i))
			return (0);
	i = -1;
	while (++i < pip->ncmds)
		wait(NULL);
	return (1);
}

void	free_strings(char *str, char *lim)
{
	while (str != NULL)
	{
		free(str);
		str = get_next_line(1);
	}
	free(lim);
}
