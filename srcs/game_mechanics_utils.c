/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mechanics_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:53:34 by crea              #+#    #+#             */
/*   Updated: 2024/03/30 22:36:14 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int random_range(unsigned int min, unsigned int max)
{
    return (min + rand() % (max - min + 1));
}

long long current_timestamp(void)
{
    struct timespec	tp;
    clock_gettime(CLOCK_MONOTONIC, &tp);
    return ((long long)tp.tv_sec * 1000LL + (long long)tp.tv_nsec / 1000000LL);
}
