/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:37:47 by rakpinar          #+#    #+#             */
/*   Updated: 2023/03/01 16:45:41 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!(str))
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}

int	ft_putnbr(long double number, int base, int is_upper)//t_putnbr fonksiyonunda long double veri tipi kullanılmış olmasının sebebi,
{														//verilen sayının boyutu ve hassasiyeti ile ilgilidir.
	int	count;											//double veri tipi, float veri tipine göre daha büyük sayıları tutabilir ve daha yüksek bir hassasiyete sahiptir.
														// Bu nedenle, ft_putnbr fonksiyonu gibi büyük sayılarla çalışan fonksiyonlarda,
	count = 1;											//long double veri tipi kullanılması gerekebilir.
	if (number < 0)
	{
		count++;
		number = -number;
		write(1, "-", 1);
	}
	if (number >= base)
		count += ft_putnbr(number / base, base, is_upper);
	if (is_upper)
		write(1, &UPPER_BASE[(unsigned long)number % base], 1);
	else
		write(1, &LOWER_BASE[(unsigned long)number % base], 1);
	return (count);
}

int	ft_pointer(long double number, int base, int is_upper)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr(number, base, is_upper);
	return (count);
}
