/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:36:30 by isam-alv          #+#    #+#             */
/*   Updated: 2025/06/10 14:12:34 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_putchar_ptg(void)
{
	write (1, "%", 1);
	return (1);
}

int	ft_conversions(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(ap, void *), 16);
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_dig(va_arg(ap, int), 10);
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_putchar_ptg();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		char_count;

	if (!format)
		return (-1);
	va_start(ap, format);
	char_count = 0;
	while (*format)
	{
		if (*format == %)
		{
			format++;
			if (*format == '\0')
				break ;
			char_count += ft_conversions(*format, &ap);
		}
		else
		{
			ft_putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(ap);
	return (char_count);
}

int	main(void)
{
	printf("how you doing, %s\n", "Ivo");
	return (0);
}
