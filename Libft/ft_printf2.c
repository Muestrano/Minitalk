/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picarlie <picarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:35:45 by picarlie          #+#    #+#             */
/*   Updated: 2024/06/11 09:43:30 by picarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printf_ptr(void *ptr)
{
	int	check;
	int	check2;

	if (!ptr)
		return (write(1, "(nil)", 5));
	check = write(1, "0x", 2);
	if (check < 0)
		return (check);
	check2 = printf_number_ptr((unsigned long int)ptr, 0);
	if (check2 < 0)
		return (check2);
	return (check + check2);
}

int	printf_number_ptr(unsigned long int nb, int count_printed)
{
	unsigned long int	len_base;
	int					check;
	char				*base;

	len_base = 16;
	base = "0123456789abcdef";
	if (nb >= len_base)
	{
		check = printf_number_ptr(nb / len_base, count_printed);
		if (check < 0)
			return (check);
		return (printf_number_ptr(nb % len_base, count_printed + check));
	}
	check = write(1, &base[nb], 1);
	if (check < 0)
		return (check);
	return (count_printed + check);
}
