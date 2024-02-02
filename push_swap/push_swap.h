/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:17:05 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/20 14:51:26 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_res
{
	int		ret_a;
	int		ret_b;
}	t_res;

t_list	*initialize_stack_args(t_list *stack_a, int argc, char **argv);
void	free_stacks(t_list *stack_a);
int		error_management(int argc, char **argv, t_list *stack_a);
t_list	*initialize_stack_str(t_list *stack_a, char **argv);
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
int		not_in_arr(int ele, int *arr, int size);
int		*sorted_arr(t_list *sa);
int		find_pred_index(int ele, t_list *sb, int *arr, int size);
int		find_in_stack(int ele, t_list *sb);
int		find_min(t_list *sb);
void	push_swap(t_list **sa, t_list **sb);
int		check_distance(int ele, t_list *s);
long	find_max(t_list *sb);
void	rotate_or_reverse(int ele, t_list **s, char which);
int		check_distance_rel(int ele, t_list *s);
int		find_succ(int ele, int *arr, int size);
void	element_check(int *ele, t_list *cpy, int *arr, int i);
int		is_5_or_less(t_list **sa, int *arr);
void	order_stack_a(t_list **sa);

#endif
