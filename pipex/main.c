/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:17:53 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/24 16:54:25 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		error;
	t_pip	pipex;

	error = 0;
	pipex = default_values();
	if (!check_files(argc, argv)
		|| !check_cmds(argc, argv, &pipex, envp))
		error = -1;
	if (error == 0)
		if (!program(&pipex, envp, argv, argc))
			error = -1;
	cleanup(&pipex);
	return (error);
}
