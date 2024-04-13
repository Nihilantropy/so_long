/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:27 by crea              #+#    #+#             */
/*   Updated: 2024/01/26 13:35:44 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	digits_nb(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	while (n != 0)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

static void	print_ptr(uintptr_t addr)
{
	static char	*digits;

	digits = "0123456789abcdef";
	if (addr >= 16)
		print_ptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}

int	ft_putptr(void *addr)
{
	if (!addr)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	print_ptr((uintptr_t)addr);
	return (digits_nb((uintptr_t)addr) + 2);
}
