/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:12:25 by crea              #+#    #+#             */
/*   Updated: 2024/01/26 12:26:31 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int n)
{
	int					count;
	unsigned long int	nb;

	count = 0;
	nb = (unsigned long)n;
	if (n < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb == 0)
		return (count + ft_putchar('0'));
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar((char)(nb % 10 + '0'));
	return (count);
}
