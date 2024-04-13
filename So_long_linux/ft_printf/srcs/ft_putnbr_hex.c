/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:02:43 by crea              #+#    #+#             */
/*   Updated: 2024/01/26 13:52:39 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	baselen(size_t nb);

int	ft_putnbr_hex(size_t nb, char c)
{
	char	*base;
	char	*str;
	int		i;
	int		count;

	count = baselen(nb);
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	str = ft_calloc(sizeof(char), baselen(nb) + 1);
	if (!str)
		return (0);
	str[0] = '0';
	i = 0;
	while (nb > 0)
	{
		str[i] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	ft_strrev(str);	
	return (count);
}

static int	baselen(size_t nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}
