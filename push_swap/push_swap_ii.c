/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:47:14 by gsapio            #+#    #+#             */
/*   Updated: 2024/01/20 14:50:32 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_5_or_less(t_list **sa, int *arr)
{
	if (ft_lstsize(*sa) < 4)
	{
		order_stack_a(sa);
		rotate_or_reverse(find_min(*sa), sa, 'a');
		free(arr);
		return (1);
	}
	return (0);
}
