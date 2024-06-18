/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:35:06 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/11 09:44:34 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_char(char c)
{
	return (write(1, &c, 1));
}

int	printf_string(char *str)
{
	int	count_printed;

	count_printed = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		if (printf_char(*str) < 0)
			return (-1);
		str++;
		count_printed++;
	}
	return (count_printed);
}

int	printf_number(long long int nb, char *base, int count_printed)
{
	int	len_base;
	int	check;

	len_base = ft_strlen(base);
	if (nb < 0)
	{
		check = write(1, "-", 1);
		if (check < 0)
			return (check);
		return (printf_number(-nb, base, count_printed) + check);
	}
	if (nb >= len_base)
	{
		check = printf_number(nb / len_base, base, count_printed);
		if (check < 0)
			return (check);
		return (printf_number(nb % len_base, base, count_printed + check));
	}
	check = write(1, &base[nb], 1);
	if (check < 0)
		return (check);
	return (count_printed + check);
}

int	redirect(va_list ap, char c)
{
	int	check;

	check = 0;
	if (c == '%')
		check = write(1, &c, 1);
	if (c == 'c')
		check = printf_char(va_arg(ap, int));
	if (c == 's')
		check = printf_string(va_arg(ap, char *));
	if (c == 'p')
		check = printf_ptr(va_arg(ap, void *));
	if (c == 'd')
		check = printf_number(va_arg(ap, int), "0123456789", 0);
	if (c == 'i')
		check = printf_number(va_arg(ap, int), "0123456789", 0);
	if (c == 'u')
		check = printf_number(va_arg(ap, unsigned int), "0123456789", 0);
	if (c == 'x')
		check = printf_number(va_arg(ap, unsigned int), "0123456789abcdef", 0);
	if (c == 'X')
		check = printf_number(va_arg(ap, unsigned int), "0123456789ABCDEF", 0);
	return (check);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		count_printed;
	int		check;

	count_printed = 0;
	if (!input)
		return (write(1, "NULL", 4));
	va_start(ap, input);
	while (*input)
	{
		if (*input != '%')
			check = write(1, input, 1);
		else
		{
			input++;
			check = redirect(ap, *input);
		}
		if (check < 0)
			return (check);
		count_printed += check;
		input++;
	}
	va_end(ap);
	return (count_printed);
}
