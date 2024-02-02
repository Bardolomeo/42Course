/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:12:21 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/24 18:22:05 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "pipex.h"

/*bonus functions*/
int		here_doc_func(char *limit);
void	cleanup_bonus(t_pip *pip);
int		program_bonus(t_pip *pip, char **envp, char **argv, int argc);
void	free_strings(char *str, char *lim);

#endif
