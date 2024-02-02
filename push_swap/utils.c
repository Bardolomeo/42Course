/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:25:33 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/12 14:10:54 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *sb)
{
	int		tmp;
	t_list	*cpy;

	cpy = sb;
	tmp = INT_MAX;
	while (cpy)
	{
		if (*(int *)cpy->content < tmp)
			tmp = *(int *)cpy->content;
		cpy = cpy->next;
	}
	return (tmp);
}

int	not_in_arr(int ele, int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (arr[i] == ele)
			return (0);
	return (1);
}

int	*sorted_arr(t_list *sa)
{
	int		*arr;
	t_list	*cpy;
	int		i;
	int		ele;

	arr = ft_calloc(sizeof(int), ft_lstsize(sa));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < ft_lstsize(sa))
		arr[i] = INT_MIN;
	i = -1;
	while (++i < ft_lstsize(sa))
	{
		cpy = sa;
		ele = INT_MAX;
		while (cpy)
		{
			element_check(&ele, cpy, arr, i);
			cpy = cpy->next;
		}
		arr[i] = ele;
	}
	return (arr);
}

int	find_in_stack(int ele, t_list *sb)
{
	t_list	*cpy;

	cpy = sb;
	while (cpy)
	{
		if (*(int *)cpy->content == ele)
			return (1);
		cpy = cpy->next;
	}
	return (0);
}

int	find_pred_index(int ele, t_list *sb, int *arr, int size)
{
	int	i;

	i = 0;
	if (ele == arr[0])
	{
		while (!find_in_stack(arr[size - 1], sb) && size > 0)
			size--;
		return (size - 1);
	}
	while (arr[i] != ele)
		i++;
	i -= 1;
	while (!find_in_stack(arr[i], sb) && i >= 0)
		i--;
	if (i == -1)
		while (find_max(sb) != arr[i])
			i++;
	return (i);
}
