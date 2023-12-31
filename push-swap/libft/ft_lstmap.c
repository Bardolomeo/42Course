/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:46:22 by gsapio            #+#    #+#             */
/*   Updated: 2023/12/16 14:29:57 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;
	void	*res;
	int		index;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		res = f(lst->content);
		temp = ft_lstnew(res, &index);
		index++;
		if (!temp)
		{
			del(res);
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&head, temp);
	}
	return (head);
}
