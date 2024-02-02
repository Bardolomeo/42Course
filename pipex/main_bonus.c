/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:17:53 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/24 19:08:30 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		error;
	t_pip	pipex;

	error = 0;
	pipex = default_values();
	if (argc > 5 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		pipex.limit = argv[2];
		if (!here_doc_func(argv[2]))
			error = -1;
	}
	if (!check_files(argc, argv)
		|| !check_cmds(argc, argv, &pipex, envp))
		error = -1;
	if (error == 0)
		if (!program_bonus(&pipex, envp, argv, argc))
			error = -1;
	cleanup_bonus(&pipex);
	return (error);
}
