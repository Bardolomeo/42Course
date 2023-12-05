/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:02:02 by gsapio            #+#    #+#             */
/*   Updated: 2023/11/14 18:54:42 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;
	char	*c2;

	i = 0;
	ptr = (char *)s;
	c2 = (char *)&c;
	while (ptr[i] != *c2 && ptr[i] != 0)
		i++;
	if (ptr[i] == *c2)
		return (&ptr[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*res;

	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((len) == 0)
		res = (char *)malloc(1 * sizeof(char));
	else
		res = (char *)malloc(((len) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (++i < len && s1[j] != 0)
		res[i] = s1[j++];
	j = 0;
	while (i < len && s2[j] != 0)
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

static char	*ft_allocstr(int *copy_len, int len)
{
	char	*copy;

	if (len >= (*copy_len) && *copy_len > 0)
		copy = (char *)malloc(sizeof(*copy) * (*copy_len) + 1);
	else
		copy = (char *)malloc(sizeof(*copy) * len + 1);
	if (!copy)
		return (NULL);
	return (copy);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*copy;
	int		i;
	int		copy_len;

	copy_len = ft_strlen(s) - start;
	copy = ft_allocstr(&copy_len, len);
	if (!copy)
		return (NULL);
	if (start >= (int)ft_strlen(s))
	{
		free (copy);
		copy = (char *)malloc(sizeof(*copy) * 1);
		if (!copy)
			return (NULL);
		*copy = 0;
		return (copy);
	}
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < len && s[i + start] != 0)
		copy[i] = s[i + start];
	copy[i] = 0;
	return (copy);
}
