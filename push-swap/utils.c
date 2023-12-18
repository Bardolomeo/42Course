/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:25:33 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 19:10:01 by gsapio           ###   ########.fr       */
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
	{
		cpy = sa;
		ele = INT_MAX;
		while (cpy)
		{
			if (ele > *(int *)cpy->content
				&& not_in_arr(*(int *)cpy->content, arr, ft_lstsize(sa)))
				ele = *(int *)cpy->content;
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

int	find_pred_index(int ele, t_list *sb, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != ele)
		i++;
	if (i == 0 && arr[i] == ele)
	{
		while (find_max(sb) != arr[i])
			i++;
		return (i);
	}
	i -= 1;
	while (!find_in_stack(arr[i], sb) && i >= 0)
		i--;
	if (i == -1)
		while (find_max(sb) != arr[i])
			i++;
	return (i);
}

int	find_succ_index(int ele, t_list *sa, int *arr, int size)
{
	int	i;

	i = 0;
	while (arr[i] != ele)
		i++;
	if (i == size && arr[i - 1] == ele)
	{
		i = 0;
		while (find_min(sa) != arr[i])
			i++;
		return (i);
	}
	i += 1;
	while (!find_in_stack(arr[i], sa) && i < size)
		i++;
	if (i == size)
	{
		i = 0;
		if (sa)
			while (find_min(sa) != arr[i])
				i++;
	}
	return (i);
}
