/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:35:11 by rakpinar          #+#    #+#             */
/*   Updated: 2023/02/26 18:42:50 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr(va_arg(list, unsigned int), 16, 0);
	else if (c == 'X')
		count += ft_putnbr(va_arg(list, unsigned int), 16, 1);
	else if (c == 'u')
		count += ft_putnbr(va_arg(list, unsigned int), 10, 0);
	else if (c == 'p')
		count += ft_pointer(va_arg(list, unsigned long), 16, 0);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		val;

	val = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			val += ft_check(*(str + 1), ap);
			str++;
		}
		else
			val += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (val);
}
