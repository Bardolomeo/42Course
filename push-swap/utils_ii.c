/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:07:54 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 19:05:39 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_minmax_abs(t_list **to, t_list **from, char which)
// {
// 	if (check_distance(find_min(*to), *to) > 0)
// 	{
// 		while (*(int *)(*to)->content != find_min(*to))
// 			rotate(to, which);
// 	}
// 	if (check_distance(find_min(*to), *to) < 0)
// 	{
// 		while (*(int *)(*to)->content != find_min(*to))
// 			rev_rotate(to, which);
// 	}
// 	if (which == 'a')
// 		push(from, to, 'b');
// 	else
// 		push(to, from, 'b');
// }

long int	find_max(t_list *sb)
{
	int		tmp;
	t_list	*cpy;

	cpy = sb;
	tmp = INT_MIN;
	while (cpy)
	{
		if (*(int *)cpy->content > tmp)
			tmp = *(int *)cpy->content;
		cpy = cpy->next;
	}
	return (tmp);
}

void	rot_a_push_b(t_list **sa, t_list **sb, t_res src_a)
{
	int	smt;

	smt = src_a.off;
	if (smt > ft_lstsize(*sa) / 2)
		while (smt--)
			rrr(sa, sb);
	rotate_or_reverse(src_a.num, sa, 'a');
	push(sb, sa, 'b');
}

void	rot_b_push_b(t_list **sa, t_list **sb, t_res src_b)
{
	int	smt;

	smt = src_b.off;
	if (smt > ft_lstsize(*sb) / 2)
		while (smt--)
			rrr(sa, sb);
	rotate_or_reverse(src_b.num, sb, 'b');
	push(sb, sa, 'b');
}
// void	is_sorted_partial(t_list **sa, t_list **sb, int *arr)
// {
// 	t_list	*cpy;
// 	int		i;
// 	int		j;

// 	cpy = *sa;
// 	while (cpy)
// 	{
// 		if (cpy->next)
// 			i = find_pred_index(*(int *)cpy->next->content, arr);
// 		while (*(int *)cpy->content == arr[i])
// 		{
// 			if (!find_min(*sa))
// 				rotate_or_reverse(*(int *)cpy->content, sa, 'a');
// 			i = find_pred_index(*(int *)(*sa)->content, arr);
// 			check_and_push_b(sa, sb, arr, i);
// 			if (cpy->next)
// 				i = find_pred_index(*(int *)cpy->next->content, arr);
// 			else
// 				i = -1;
// 		}
// 		cpy = cpy->next;
// 	}
// }

void	rotate_or_reverse(int ele, t_list **s, char which)
{
	if (check_distance(ele, *s) > 0)
		while (*(int *)(*s)->content != ele)
			rotate(s, which);
	if (check_distance(ele, *s) < 0)
		while (*(int *)(*s)->content != ele)
			rev_rotate(s, which);
}

int	check_distance_abs(int ele, t_list *s)
{
	if (check_distance(ele, s) >= 0)
		return (check_distance(ele, s));
	else
		return (check_distance(ele, s) * -1);
}
