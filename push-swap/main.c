/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:15:19 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 14:40:06 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	int		*conv_str;

	stack_a = NULL;
	stack_b = NULL;
	if (error_management(argc, argv, stack_a))
		return (-1);
	i = -1;
	if (!ft_strchr(argv[1], ' '))
		stack_a = initialize_stack_args(stack_a, argc, argv);
	else
		stack_a = initialize_stack_str(stack_a, argc, argv);
	if (error_management(argc, argv, stack_a))
	{
		free_stacks(stack_a);
		return (0);
	}
	push_swap(&stack_a, &stack_b);
	// a_to_b(&stack_a, &stack_b);
	// ft_printf("\n\n\nAAAAA\tBBBBB\n\n");
	// while (stack_a || stack_b)
	// {
	// 	if (stack_a)
	// 	{
	// 		ft_printf("  %d\t", *(int *)(stack_a->content));
	// 		stack_a = stack_a->next;
	// 	}
	// 	else
	// 		ft_printf("\t");
	// 	if (stack_b)
	// 	{
	// 		ft_printf("  %d\n", *(int *)(stack_b->content));
	// 		stack_b = stack_b->next;
	// 	}
	// 	else
	// 		ft_printf("\n");
	// }
	free_stacks(stack_a);
}
