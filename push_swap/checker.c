/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:50:17 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/15 16:57:06 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

int	op_control(char *str)
{
	if (!ft_strncmp(str, "sa\n", 3) || !ft_strncmp(str, "sb\n", 3)
		|| !ft_strncmp(str, "ss\n", 3) || !ft_strncmp(str, "ra\n", 3)
		|| !ft_strncmp(str, "rb\n", 3) || !ft_strncmp(str, "rr\n", 3)
		|| !ft_strncmp(str, "pa\n", 3) || !ft_strncmp(str, "pb\n", 3)
		|| !ft_strncmp(str, "rra\n", 4) || !ft_strncmp(str, "rrb\n", 4)
		|| !ft_strncmp(str, "rrr\n", 4))
		return (1);
	return (0);
}

void	check_order(t_list *sa, t_list *sb)
{
	int		cont;
	t_list	*cpy;

	while (sa->next)
	{
		cont = *(int *)sa->content;
		cpy = sa;
		while (cpy)
		{
			if (cont > *(int *)cpy->content || sb)
			{
				ft_printf("KO\n");
				return ;
			}
			cpy = cpy->next;
		}
		sa = sa->next;
	}
	ft_printf("OK\n");
}

void	exec_ops(t_list **sa, t_list **sb, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		swap(*sa, 'a');
	else if (!ft_strncmp(str, "sb\n", 3))
		swap(*sb, 'b');
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(*sa, *sb);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(sa, 'a');
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(sb, 'b');
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(sa, sb);
	else if (!ft_strncmp(str, "pa\n", 3))
		push(sa, sb, 'a');
	else if (!ft_strncmp(str, "pb\n", 3))
		push(sb, sa, 'b');
	else if (!ft_strncmp(str, "rra\n", 4))
		rev_rotate(sa, 'a');
	else if (!ft_strncmp(str, "rrb\n", 4))
		rev_rotate(sb, 'b');
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(sa, sb);
}

int	checker_func(t_list **sa, t_list **sb)
{
	char	*str;

	str = ft_strdup(" ");
	while (*str)
	{
		free(str);
		str = get_next_line(0);
		if (!str)
			break ;
		if (op_control(str))
			exec_ops(sa, sb, str);
		else
		{
			free(str);
			return (0);
		}
	}
	check_order(*sa, *sb);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		error;

	stack_a = NULL;
	stack_b = NULL;
	error = error_management(argc, argv, stack_a);
	if (error == 1)
		return (0);
	if (!ft_strchr(argv[1], ' '))
		stack_a = initialize_stack_args(stack_a, argc, argv);
	else
		stack_a = initialize_stack_str(stack_a, argv);
	if (error_management(argc, argv, stack_a))
	{
		free_stacks(stack_a);
		return (0);
	}
	if (!checker_func(&stack_a, &stack_b))
		write (2, "Error\n", 6);
	free_stacks(stack_a);
	return (0);
}
