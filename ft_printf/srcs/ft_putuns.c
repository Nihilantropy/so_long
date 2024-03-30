/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:56:34 by crea              #+#    #+#             */
/*   Updated: 2024/01/26 12:33:58 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putuns(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb >= 10)
		count += ft_putuns(nb / 10);
	return (count + ft_putchar((char)(nb % 10 + '0')));
}
