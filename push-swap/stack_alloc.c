/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:30:27 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 14:27:24 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_elem(void *elem)
{
	free(elem);
}

void	*free_matrix(char **mtx)
{
	int	i;

	i = -1;
	if (mtx)
	{
		while (mtx[++i])
			free(mtx[i]);
		free(mtx);
	}
	return (NULL);
}

void	free_stacks(t_list *stack_a)
{
	if (stack_a)
		ft_lstclear(&stack_a, del_elem);
}

t_list	*initialize_stack_args(t_list *stack_a, int argc, char **argv)
{
	int					i;
	t_list				*new;
	int					*n;
	static int			index;

	i = -1;
	index = 0;
	while (++i < argc - 1)
	{
		n = ft_calloc(1, sizeof(int));
		*n = ft_atoi(argv[i + 1]);
		new = ft_lstnew(n, &index);
		index++;
		ft_lstadd_back(&stack_a, new);
	}
	return (stack_a);
}

t_list	*initialize_stack_str(t_list *stack_a, int argc, char **argv)
{
	char	**strs;
	int		i;
	int		*n;
	t_list	*new;

	strs = ft_split(argv[1], ' ');
	if (check_min_max(strs))
	{
		ft_printf("Error\n");
		return (free_matrix(strs));
	}
	i = -1;
	while (strs[++i])
	{
		n = ft_calloc(1, sizeof(int));
		*n = ft_atoi(strs[i]);
		new = ft_lstnew(n, &i);
		ft_lstadd_back(&stack_a, new);
	}
	i = -1;
	free_matrix(strs);
	return (stack_a);
}
