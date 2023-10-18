/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:57:39 by gsapio            #+#    #+#             */
/*   Updated: 2023/10/18 16:57:41 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	ptr = (char *)s;
	i = ft_strlen(ptr) + 1;
	while (--i > 0)
		if (ptr[i] == c)
			return (&ptr[i]);
	return (NULL);
}
/*
int main()
{
	char str[50] = "ciau suca";
	printf("%s\n", ft_strrchr(str, 'u'));
	printf("%s\n", ft_strrchr("zio pera", 'u'));
	printf("%s\n", ft_strrchr("uuuuuu", 'u'));
	printf("%s\n", ft_strrchr("", '\0'));
}*/
