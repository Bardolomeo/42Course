/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ii_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:38:46 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/15 17:01:48 by gsapio           ###   ########.fr       */
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
	t_list	*scnd_last;

	which = 0;
	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		scnd_last = ft_lstscndlast(*stack);
		if (scnd_last)
			scnd_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a, 'c');
	rev_rotate(stack_b, 'c');
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
		count = INT_MAX;
	if (count > (ft_lstsize(s) / 2))
		return (count - ft_lstsize(s));
	else
		return (count);
}
