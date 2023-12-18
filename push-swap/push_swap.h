/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:17:05 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 19:05:16 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_res
{
	int		num;
	long	dist;
	int		off;
}	t_res;

t_list	*initialize_stack_args(t_list *stack_a, int argc, char **argv);
void	free_stacks(t_list *stack_a);
int		error_management(int argc, char **argv, t_list *stack_a);
t_list	*initialize_stack_str(t_list *stack_a, int argc, char **argv);
int		check_min_max(char **strs);
void	del_elem(void *elem);
void	swap(t_list *stack, char which);
void	ss(t_list *stack_a, t_list *stack_b);
int		push(t_list **to, t_list **from, char which);
int		rotate(t_list **stack, char which);
int		rr(t_list **stack_a, t_list **stack_b);
int		rev_rotate(t_list **stack, char which);
int		rrr(t_list **stack_a, t_list **stack_b);
void	push_swap(t_list **sa, t_list **sb);
void	check_distances(t_list **sa, t_list **sb, int *arr);
int		check_distance_sa(t_list **sa, t_list **sb, t_res *src_b, int *arr);
t_list	*tree_sort(t_list **stack);
int		ft_abs(int num);
int		not_in_arr(int ele, int *arr, int size);
int		*sorted_arr(t_list *sa);
int		find_pred_index(int ele, t_list *sb, int *arr);
int		find_in_stack(int ele, t_list *sb);
int		find_min(t_list *sb);
void	push_swap(t_list **sa, t_list **sb);
void	push_minmax_abs(t_list **sa, t_list **sb, char which);
int		check_distance(int ele, t_list *s);
long	find_max(t_list *sb);
void	rotate_or_reverse(int ele, t_list **s, char which);
void	is_sorted_partial(t_list **sa, t_list **sb, int *arr);
void	check_and_push_b(t_list **sa, t_list **sb, int *arr, int i);
void	check_and_push_a(t_list **sa, t_list **sb, int *arr, int i);
int		check_distance_abs(int ele, t_list *s);
int		find_succ_index(int ele, t_list *sb, int *arr, int size);
int		check_distance_sb(t_list **sa, t_list **sb, t_res *src_a, int *arr);
void	rot_b_push_b(t_list **sa, t_list **sb, t_res src_b);
void	rot_a_push_b(t_list **sa, t_list **sb, t_res src_a);

#endif
