/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsapio <gsapio@student.42firenze.it >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:45:09 by gsapio            #+#    #+#             */
/*   Updated: 2023/11/10 12:52:20 by gsapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *cnt);
void	ft_putstr(char *s, int *cnt);
void	ft_printint(int n, int *cnt);
void	ft_printaddr(void *ptr, int *cnt);
void	ft_printuns(unsigned int nb, int *cnt);
void	ft_printhex(unsigned long int n, char c, int *cnt);

#endif
