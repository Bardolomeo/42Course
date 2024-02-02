/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:07:54 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/12 14:21:21 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_or_reverse(int ele, t_list **s, char which)
{
	if (check_distance(ele, *s) > 0)
		while (*(int *)(*s)->content != ele)
			rotate(s, which);
	if (check_distance(ele, *s) < 0)
		while (*(int *)(*s)->content != ele)
			rev_rotate(s, which);
}

int	check_distance_rel(int ele, t_list *s)
{
	if (ele == INT_MAX)
		return (INT_MAX);
	if (check_distance(ele, s) >= 0)
		return (check_distance(ele, s));
	else
		return (check_distance(ele, s) + ft_lstsize(s));
}

int	find_succ(int ele, int *arr, int size)
{
	int	i;

	i = 0;
	while (arr[i] != ele)
		i++;
	i++;
	if (i >= size)
		i = 0;
	return (arr[i]);
}

void	element_check(int *ele, t_list *cpy, int *arr, int i)
{
	if (*ele >= *(int *)cpy->content
		&& not_in_arr(*(int *)cpy->content, arr, i + 1))
		*ele = *(int *)cpy->content;
}
