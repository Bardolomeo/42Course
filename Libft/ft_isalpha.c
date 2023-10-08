//#include <stdio.h>
#include "libft.h"
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == 0))
		return (1);
	else
		return (0);
}

//int main()
//{
//	printf("%d\n", ft_isalpha('C'));
//}