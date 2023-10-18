/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:13:09 by gsapio            #+#    #+#             */
/*   Updated: 2023/10/17 14:13:17 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			i;

	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	if (to == from || n == 0)
		return (dest);
	if (to > from && to - from < (int)n)
	{
		i = n;
		while (--i)
			to[i] = from[i];
		return (dest);
	}
	if (from > to && from - to < (int)n)
	{
		i = -1;
		while (++i < n)
			from[i] = to[i];
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
/*
int main()
{
	char src[50] = "ciao papareddu";
	char dest[50] = "pezzo di merda vaffanculo";
	
	ft_memmove(dest, src, 5);
	printf("%s\n", dest);
	ft_memmove(dest, src, 0);
	printf("%s\n", dest);
		ft_memmove(dest, src, 1);
	printf("%s\n", dest);
	ft_memmove(dest, src, 20);
	printf("%s\n", dest);

}*/
