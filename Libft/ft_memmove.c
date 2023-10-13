/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:18:54 by gsapio            #+#    #+#             */
/*   Updated: 2023/07/24 16:20:39 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *from;
	unsigned char *to;
	size_t	i;

	from = (unsigned char *)src;
	to = (unsigned char *)dest;

	if (to > from && to - from < n)
	{
		i = n;
		while (i--)
			to[i] = from[i];
		return dest;
	}

	if (to == from && from - to )
		return dest;
}
