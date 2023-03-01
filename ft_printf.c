/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakpinar <rakpinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:35:11 by rakpinar          #+#    #+#             */
/*   Updated: 2023/03/01 16:42:37 by rakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(list, int));		//va_arg(list, unsigned int): list argümanındaki bir sonraki değeri, unsigned int tipine dönüştürerek gönderir
	else if (c == 's')								// Bu işlev, değişken sayıda argümanlı fonksiyonlarda,
		count += ft_putstr(va_arg(list, char *));	//fonksiyona gönderilen değerlerin tipi belirtilmeyen bir şekilde alındığından,
	else if (c == 'd' || c == 'i')					//bu değerleri doğru bir şekilde kullanmak için gereklidir.
		count += ft_putnbr(va_arg(list, int), 10, 0);
	else if (c == 'x')
		count += ft_putnbr(va_arg(list, unsigned int), 16, 0);	//16: ft_putnbr fonksiyonuna sayıyı hangi tabanda yazdıracağımızı belirten ikinci argümanıdır.
	else if (c == 'X')											//1: Bu argüman, ft_putnbr fonksiyonunun sayıyı büyük harflerle yazdırıp yazdırmayacağını belirler
		count += ft_putnbr(va_arg(list, unsigned int), 16, 1);
	else if (c == 'u')
		count += ft_putnbr(va_arg(list, unsigned int), 10, 0);
	else if (c == 'p')
		count += ft_pointer(va_arg(list, unsigned long), 16, 0);
	else if (c == '%')						//void * veri tipinin bir işaretçi olduğu ve bellek adreslerinin genellikle unsigned long veri tipinde saklanmasıdır.			
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		val;

	val = 0;
	va_start(ap, str);	//va_start fonksiyonu, ap değişkenine argüman listesindeki ilk değişkenin adresini atayarak çalışmaktadır
	while (*str)		//Bu sayede, argüman listesindeki tüm değişkenlere tek tek erişim sağlamak mümkün hale gelmektedir.
	{
		if (*str == '%')
		{
			val += ft_check(*(str + 1), ap);//*(str + 1) ifadesi, str pointer'ının bir sonraki konumundaki karakteri ifade eder.
			str++;							// Yani % karakterinden sonra gelen karakteri temsil eder.
		}									//Bu karakter, format belirteci olarak kullanılacak olan karakteri belirleyecektir. 
		else
			val += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (val);
}
