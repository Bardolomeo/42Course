/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:06:11 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/15 16:43:40 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min_max(char **strs)
{
	int		i;
	char	*str;

	i = 0;
	if (strs[1])
	{
		while (strs[++i])
		{
			str = ft_itoa(ft_atoi(strs[i]));
			if (ft_strncmp(str, strs[i], ft_strlen(str)))
			{
				free (str);
				return (1);
			}
			free (str);
		}
	}
	return (0);
}

int	check_for_errors(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
			if ((a[i][j] != ' ') && (a[i][j] < '0' || a[i][j] > '9')
				&& a[i][j] != '-')
				return (1);
	}
	i = 1;
	while (a[++i])
	{
		{
			j = -1;
			while (a[i][++j])
				if ((a[i][j] < '0' || a[i][j] > '9') && a[i][j] != '-')
					return (1);
		}
	}
	return (0);
}

int	has_duplicate(t_list *stack_a)
{
	t_list	*cpy;
	t_list	*head;

	cpy = NULL;
	if (stack_a)
		cpy = stack_a;
	while (cpy)
	{
		head = cpy->next;
		while (head)
		{
			if (*(int *)head->content == *(int *)cpy->content)
				return (1);
			head = head->next;
		}
		cpy = cpy->next;
	}
	return (0);
}

int	is_sorted(t_list *stack_a)
{
	t_list	*head;

	if (stack_a)
	{
		head = stack_a;
		while (head->next)
		{
			if (*(int *)head->content > *(int *)head->next->content)
				return (0);
			head = head->next;
		}
	}
	ft_printf("OK\n");
	return (1);
}

int	error_management(int argc, char **argv, t_list *stack_a)
{
	if (argc == 1)
		return (1);
	if ((ft_strchr(argv[1], ' ') && argc > 2)
		|| check_for_errors(argv)
		|| has_duplicate(stack_a)
		|| check_min_max(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc < 3 && !ft_strchr(argv[1], ' '))
		return (1);
	if ((stack_a && is_sorted(stack_a)))
	{
		return (1);
	}
	return (0);
}
