/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:15:19 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/15 15:26:34 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	push_swap(&stack_a, &stack_b);
	free_stacks(stack_a);
	ft_printf("\0");
	return (0);
}
