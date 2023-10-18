/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:37:16 by gsapio            #+#    #+#             */
/*   Updated: 2023/10/18 16:37:22 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != (char)c && ptr[i] != 0)
		i++;
	if (ptr[i] == c)
		return (&ptr[i]);
	return (NULL);
}
/*
int main()
{
	char str[50] = "ciau suca";
	printf("%s\n", ft_strchr(str, 'u'));
	printf("%s\n", ft_strchr("zio pera", 'u'));
	printf("%s\n", ft_strchr("uuuuuu", 'u'));
	printf("%s\n", ft_strchr("", '\0'));
}*/
