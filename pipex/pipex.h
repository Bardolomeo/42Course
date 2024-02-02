/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:23:06 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/26 18:52:21 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

# define W_END 1
# define R_END 0

typedef int	t_pid;
typedef struct s_pip
{
	t_pid	pid;
	int		fd[2];
	char	***cmds;
	char	*limit;
	char	**path;
	int		ncmds;
}	t_pip;

/*main functions*/
t_pip	default_values(void);
int		check_files(int argc, char **argv);//, t_pip *pipex);
int		check_cmds(int argc, char **argv, t_pip *pipex, char **envp);
int		program(t_pip *pipex, char **envp, char **argv, int argc);
void	cleanup(t_pip *pipex);
/*error management functions*/
int		check_cmds_binaries(char ***cmds, char **envp, t_pip *pipex);
int		find_binary(char ***cmds, char **path, int ind, t_pip *pipex);
int		is_cmd_path(t_pip *pipex, int ind, char **path);
/*pipex functions*/
int		fork_manager(t_pip *pip, int *fd_pipe, char **envp, int *i);
int		child_manager(t_pip *pip, int *fd_pipe, char **envp, int *i);
/*utils functions*/
int		free_matrix(char **map);
char	*get_cmd_flags(char **cmd);
int		error(char *type);
int		init(t_pip *pipex);

#endif
