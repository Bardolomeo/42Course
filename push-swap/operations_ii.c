/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:38:46 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/14 18:16:36 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstscndlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next && ptr->next->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

int	rev_rotate(t_list **stack, char which)
{
	t_list	*last;
	int		*tmp_con;
	t_list	*scnd_last;

	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		scnd_last = ft_lstscndlast(*stack);
		if (scnd_last)
			scnd_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	if (which == 'a')
		ft_printf("rra\n");
	if (which == 'b')
		ft_printf("rrb\n");
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a, 'c');
	rev_rotate(stack_b, 'c');
	ft_printf("rrr\n");
	return (1);
}

int	check_distance(int ele, t_list *s)
{
	int		count;
	t_list	*cpy;

	cpy = s;
	count = 0;
	if (find_in_stack(ele, s))
	{
		while (cpy && *(int *)(cpy)->content != ele)
		{
			cpy = cpy->next;
			count++;
		}
	}
	else
	{

	}
	if (count > (ft_lstsize(s) / 2))
		return (count - ft_lstsize(s));
	else
		return (count);
}
