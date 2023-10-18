/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:18:27 by gsapio            #+#    #+#             */
/*   Updated: 2023/10/18 17:18:34 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char			*str1;
	char			*str2;
	unsigned long	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (*str1 == *str2 && *str1 != 0 && i < n - 1)
	{
		str1++;
		str2++;
		i++;
	}
	if ((*str1 - *str2) < 0)
		return (-1);
	else if ((*str1 - *str2) > 0)
		return (1);
	else
		return (0);
}
/*
int main()
{
	printf("%d\n", ft_strncmp("abba", "abbaio", 10));
	printf("%d\n", ft_strncmp("abba", "abba", 5));
	printf("%d\n", ft_strncmp("", "abbaio", 2));
	printf("%d\n\n", ft_strncmp("cappa", "abbaio", 4));
	printf("%d\n", strncmp("abba", "abbaio", 10));
	printf("%d\n", strncmp("abba", "abba", 5));
	printf("%d\n", strncmp("", "abbaio", 2));
	printf("%d\n", strncmp("cappa", "abbaio", 4));
}*/
