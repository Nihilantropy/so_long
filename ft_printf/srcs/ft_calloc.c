/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:04:35 by crea              #+#    #+#             */
/*   Updated: 2024/03/25 16:04:36 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buf;

	buf = malloc(n * size);
	if (!buf)
		return (NULL);
	if (buf)
		ft_bzero(buf, n * size);
	return (buf);
}