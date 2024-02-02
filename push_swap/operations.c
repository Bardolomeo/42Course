/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:35:59 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/11 14:57:43 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack, char which)
{
	int		*tmp_con;
	t_list	*tmp_nod;
	int		tmp_ind;

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
	if (which == 'a')
		write (1, "sa\n", 3);
	else if (which == 'b')
		write (1, "sb\n", 3);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a, 'c');
	swap(stack_b, 'c');
	write (1, "ss\n", 3);
}

int	push(t_list **to, t_list **from, char which)
{
	t_list	*tmp_nod;
	int		*tmp_con;
	int		index;

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
	if (which == 'a')
		ft_printf("pa\n");
	if (which == 'b')
		ft_printf("pb\n");
	return (1);
}

int	rotate(t_list **stack, char which)
{
	t_list	*tmp_nod;
	int		*tmp_con;
	int		index;

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
	if (which == 'a')
		ft_printf("ra\n");
	if (which == 'b')
		ft_printf("rb\n");
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (!rotate(stack_a, 'c'))
		return (0);
	if (!rotate (stack_b, 'c'))
		return (0);
	ft_printf("rr\n");
	return (1);
}
