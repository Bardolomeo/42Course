/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:34:36 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/20 14:49:32 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **sa, t_list **sb);
t_res	find_eff_ele(t_list *sa, t_list *sb, int size, int *arr);
void	ps_function(t_res num, t_list **sa, t_list **sb);
void	order_stack_a(t_list **sa);
void	push_to_a(t_list **sa, t_list **sb, int *arr);

void	push_swap(t_list **sa, t_list **sb)
{
	int		size;
	int		*arr;
	t_res	cont;

	arr = sorted_arr(*sa);
	if (is_5_or_less(sa, arr))
		return ;
	push(sb, sa, 'b');
	push(sb, sa, 'b');
	size = ft_lstsize(*sa);
	while (size > 3)
	{
		cont = find_eff_ele(*sa, *sb, size, arr);
		ps_function(cont, sa, sb);
		size = ft_lstsize(*sa);
	}
	rotate_or_reverse(find_max(*sb), sb, 'b');
	order_stack_a(sa);
	rotate_or_reverse(find_min(*sa), sa, 'a');
	push_to_a(sa, sb, arr);
	free(arr);
}

t_res	find_eff_ele(t_list *sa, t_list *sb, int size, int *arr)
{
	t_res	ret;
	int		rot_a;
	int		ind;
	int		dis;
	t_list	*head_b;

	rot_a = 0;
	head_b = sb;
	ret.ret_b = INT_MAX;
	size = ft_lstsize(sa) + ft_lstsize(sb);
	while (sa)
	{
		ind = find_pred_index(*(int *)sa->content, sb, arr, size);
		if (check_distance_rel(arr[ind], sb) < rot_a)
			dis = check_distance_rel(arr[ind], sb) + rot_a;
		else
			dis = check_distance_rel(arr[ind], sb);
		if (check_distance_rel(ret.ret_b, sb) > dis)
			ret.ret_a = *(int *)sa->content;
		if (check_distance_rel(ret.ret_b, sb) > dis)
			ret.ret_b = arr[ind];
		sa = sa->next;
		rot_a++;
	}
	return (ret);
}

void	ps_function(t_res num, t_list **sa, t_list **sb)
{
	while (*(int *)(*sa)->content != num.ret_a
			&& *(int *)(*sb)->content != num.ret_b)
		rr(sa, sb);
	while (*(int *)(*sa)->content != num.ret_a)
		rotate(sa, 'a');
	while (*(int *)(*sb)->content != num.ret_b)
		rotate(sb, 'b');
	push(sb, sa, 'b');
}

void	order_stack_a(t_list **sa)
{
	int	min;
	int	max;

	if (ft_lstsize(*sa) == 2)
	{
		rotate_or_reverse(find_min(*sa), sa, 'a');
		return ;
	}
	min = find_min(*sa);
	max = find_max(*sa);
	if (*(int *)(*sa)->content > *(int *)(*sa)->next->content
		&& *(int *)(*sa)->content == max && *(int *)(*sa)->next->content == min)
		return ;
	else if (*(int *)(*sa)->content > *(int *)(*sa)->next->content)
		swap(*sa, 'a');
	else if (*(int *)(*sa)->next->content > *(int *)(*sa)->next->next->content
		&& *(int *)(*sa)->next->content == max
		&& *(int *)(*sa)->next->next->content == min)
		return ;
	else if (*(int *)(*sa)->next->content > *(int *)(*sa)->next->next->content)
	{
		rotate(sa, 'a');
		swap(*sa, 'a');
	}
}

void	push_to_a(t_list **sa, t_list **sb, int *arr)
{
	int	succ;
	int	size;

	size = ft_lstsize(*sa) + ft_lstsize(*sb);
	while (*sb)
	{
		succ = find_succ(*(int *)(*sb)->content, arr, size);
		if (*(int *)(*sb)->content == arr[size - 1])
			succ = arr[0];
		if (*(int *)(*sa)->content != succ && find_in_stack(succ, *sa))
			rotate_or_reverse(succ, sa, 'a');
		push(sa, sb, 'a');
	}
	rotate_or_reverse(find_min(*sa), sa, 'a');
}
