/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:34:36 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 19:34:41 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_and_push_a_ii(t_list **sa, t_list **sb, int *arr, int i)
// {
// 	long int	ele;
// 	int			len;

// 	len = 0;
// 	while (len < ft_lstsize(*sa) + ft_lstsize(*sb))
// 		len++;
// 	while (!find_in_stack(arr[i], *sa) && i != len)
// 		i++;
// 	if (i == len)
// 		ele = 3000000000;
// 	else
// 		ele = arr[i];
// 	if (ele == 3000000000)
// 		push_minmax_abs(sa, sb, 'a');
// 	if (ele == 3000000000)
// 		return ;
// 	if (i == len && !find_in_stack(arr[len - 1], *sa))
// 		ele = find_max(*sa);
// 	rotate_or_reverse(ele, sa, 'a');
// 	push(sb, sa, 'b');
// }

// void	check_and_push_a(t_list **sa, t_list **sb, int *arr, int i)
// {
// 	if (arr[i] == *(int *)(*sa)->content)
// 	{
// 		rotate_or_reverse(find_max(*sa), sa, 'a');
// 		push(sb, sa, 'b');
// 	}
// 	else if (find_in_stack(arr[i], *sa))
// 	{
// 		rotate_or_reverse(arr[i], sa, 'a');
// 		push(sb, sa, 'b');
// 	}
// 	else
// 		check_and_push_a_ii(sa, sb, arr, i);
// }

// void	check_and_push_b_ii(t_list **sa, t_list **sb, int *arr, int i)
// {
// 	long int	ele;

// 	while (!find_in_stack(arr[i], *sb) && i != 0)
// 		i--;
// 	if (i == 0 && arr[i] == *(int *)(*sa)->content)
// 		ele = 3000000000;
// 	else
// 		ele = arr[i];
// 	if (ele == 3000000000)
// 		push_minmax_abs(sa, sb, 'b');
// 	if (ele == 3000000000)
// 		return ;
// 	if (i == 0 && !find_in_stack(arr[0], *sb))
// 		ele = find_max(*sb);
// 	rotate_or_reverse(ele, sb, 'b');
// 	push(sb, sa, 'b');
// }

// void	check_and_push_b(t_list **sa, t_list **sb, int *arr, int i)
// {
// 	if (arr[i] == *(int *)(*sa)->content)
// 	{
// 		rotate_or_reverse(find_max(*sb), sb, 'b');
// 		push(sb, sa, 'b');
// 	}
// 	else if (find_in_stack(arr[i], *sb))
// 	{
// 		rotate_or_reverse(arr[i], sb, 'b');
// 		push(sb, sa, 'b');
// 	}
// 	else
// 		check_and_push_b_ii(sa, sb, arr, i);
// }

void	push_swap(t_list **sa, t_list **sb)
{
	int	size;
	int	*arr;

	arr = sorted_arr(*sa);
	size = ft_lstsize(*sa);
	push(sb, sa, 'b');
	push(sb, sa, 'b');
	check_distances(sa, sb, arr);
	while (*sb != NULL)
		push(sa, sb, 'a');
	rotate_or_reverse(find_min(*sa), sa, 'a');
	free(arr);
}

void	check_distances(t_list **sa, t_list **sb, int *arr)
{
	t_res	src_b;
	t_res	src_a;

	while (*sa)
	{
		src_b.num = check_distance_sa(sa, sb, &src_b, arr);
		src_a.num = check_distance_sb(sa, sb, &src_a, arr);
		if (src_b.dist > src_a.dist)
			rot_a_push_b(sa, sb, src_a);
		else
			rot_b_push_b(sa, sb, src_b);
	}
}

int	check_distance_sa(t_list **sa, t_list **sb, t_res *src_b, int *arr)
{
	int		a_p_ind;
	t_list	*cpya;
	t_list	*cpyb;
	int		ret;
	int		off;

	cpya = *sa;
	cpyb = *sb;
	off = 0;
	src_b->dist = LONG_MAX;
	while (cpya != NULL)
	{
		a_p_ind = find_pred_index(*(int *)cpya->content, cpyb, arr);
		// if (offset > ft_lstsize(*sa) / 2)
		// 	offset = 0;
		if (check_distance_abs(arr[a_p_ind], cpyb) + off < src_b->dist)
		{
			src_b->dist = check_distance_abs(arr[a_p_ind], cpyb) + off;
			ret = arr[a_p_ind];
			src_b->off = off;
		}
		off++;
		cpya = cpya->next;
		// if (cpyb->next == NULL)
		// 	cpyb = *sb;
		// cpyb = cpyb->next;
	}
	return (ret);
}

int	check_distance_sb(t_list **sa, t_list **sb, t_res *src_a, int *arr)
{
	int		b_s_ind;
	t_list	*cpya;
	t_list	*cpyb;
	int		ret;
	int		off;

	cpya = *sa;
	cpyb = *sb;
	off = 0;
	src_a->dist = LONG_MAX;
	while (cpyb != NULL)
	{
		b_s_ind = find_succ_index(*(int *)cpyb->content, cpya, arr,
				ft_lstsize(*sa) + ft_lstsize(*sb));
		// if (offset > ft_lstsize(*sa) / 2)
		// 	offset = 0;
		if (check_distance_abs(arr[b_s_ind], cpya) + off < src_a->dist)
		{
			src_a->dist = check_distance_abs(arr[b_s_ind], cpya) + off;
			ret = arr[b_s_ind];
			src_a->off = off;
		}
		off++;
		cpyb = cpyb->next;
		// if (cpya == NULL)
		// 	cpya = *sa;
		// cpya = cpya->next;
	}
	return (ret);
}
