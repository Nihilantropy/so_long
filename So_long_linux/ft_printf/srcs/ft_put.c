/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:55:41 by crea              #+#    #+#             */
/*   Updated: 2024/01/26 15:49:24 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put(char c, va_list args)
{
	int	count;

	count = 0;

	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putuns(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		count += ft_putnbr_hex(va_arg(args, long long), c);
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}
