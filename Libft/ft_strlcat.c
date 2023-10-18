/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:32:12 by gsapio            #+#    #+#             */
/*   Updated: 2023/10/17 15:32:15 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = ft_strlen(src);
	j = ft_strlen(dst);
	if (size == 0)
		return (i);
	if ((int)size < j)
		i += size;
	else
		i += j;
	while (src[k] && (k + j) < (int)size - 1)
	{
		dst[j + k] = src[k];
		k++;
	}
	dst[j + k] = 0;
	return (i);
}
/*
int main()
{
	char dest[50] = "123456";
	char dest1[50] = "123456";
	
	printf("%d\t%s\n", (int)ft_strlcat(dest, "abc", 0), dest);
	printf("%d\t%s\n", (int)ft_strlcat(dest, "abc", 10), dest);
	printf("%d\t%s\n", (int)ft_strlcat(dest, "abc", 4), dest);
	printf("%d\t%s\n\n", (int)ft_strlcat(dest, "", 5), dest);
	printf("%d\t%s\n\n", (int)ft_strlcat(dest, "fddsfdfgfd", 12), dest);
	printf("%d\t%s\n", (int)strlcat(dest1, "abc", 0), dest1);
	printf("%d\t%s\n", (int)strlcat(dest1, "abc", 10), dest1);
	printf("%d\t%s\n", (int)strlcat(dest1, "abc", 4), dest1);
	printf("%d\t%s\n", (int)strlcat(dest, "", 5), dest1);
	printf("%d\t%s\n\n", (int)strlcat(dest1, "fddsfdfgfd", 12), dest1);
	printf("%d\n", (int)ft_strlcat("", "a", 3));
	printf("%d\n", (int)strlcat("", "a", 3));
}*/
