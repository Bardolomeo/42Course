/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:59 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/15 17:01:36 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char which)
{
	int		*tmp_con;
	t_list	*tmp_nod;
	int		tmp_ind;

	which = 0;
	if (stack)
	{
		tmp_nod = stack->next;
		tmp_con = stack->content;
		tmp_ind = stack->index;
		stack->content = tmp_nod->content;
		tmp_nod->content = tmp_con;
		stack->index = tmp_nod->index;
		tmp_nod->index = tmp_ind;
	}
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 'c');
	swap(stack_b, 'c');
}

int	push(t_list **to, t_list **from, char which)
{
	t_list	*tmp_nod;
	int		*tmp_con;
	int		index;

	which = 0;
	if (*from)
	{
		tmp_con = (*from)->content;
		tmp_nod = *from;
		index = (*from)->index;
		(*from) = (*from)->next;
		free (tmp_nod);
		tmp_nod = ft_lstnew(tmp_con, &index);
		if (!(*to))
		{
			(*to) = tmp_nod;
			(*to)->next = NULL;
		}
		else
			ft_lstadd_front(to, tmp_nod);
	}
	return (1);
}

int	rotate(t_list **stack, char which)
{
	t_list	*tmp_nod;
	int		*tmp_con;
	int		index;

	which = 0;
	if (*stack)
	{
		tmp_nod = *stack;
		tmp_con = (*stack)->content;
		index = (*stack)->index;
		*stack = (*stack)->next;
		free(tmp_nod);
		tmp_nod = ft_lstnew(tmp_con, &index);
		if (!tmp_nod)
			return (0);
		ft_lstadd_back(stack, tmp_nod);
	}
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (!rotate(stack_a, 'c'))
		return (0);
	if (!rotate (stack_b, 'c'))
		return (0);
	return (1);
}
