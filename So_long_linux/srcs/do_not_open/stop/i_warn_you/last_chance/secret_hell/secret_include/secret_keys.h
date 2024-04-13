/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_keys.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:10:57 by crea              #+#    #+#             */
/*   Updated: 2024/04/13 11:58:54 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECRET_KEYS
# define SECRET_KEYS

#define PAUSE 119
#define SEND_KEY 28

#define KEY_TO_CHAR(key) \
    ( \
        (key == LINUX_KEY_A) ? 'a' : \
        (key == LINUX_KEY_S) ? 's' : \
        (key == LINUX_KEY_D) ? 'd' : \
        (key == LINUX_KEY_F) ? 'f' : \
        (key == LINUX_KEY_H) ? 'h' : \
        (key == LINUX_KEY_G) ? 'g' : \
        (key == LINUX_KEY_Z) ? 'z' : \
        (key == LINUX_KEY_X) ? 'x' : \
        (key == LINUX_KEY_C) ? 'c' : \
        (key == LINUX_KEY_V) ? 'v' : \
        (key == LINUX_KEY_B) ? 'b' : \
        (key == LINUX_KEY_Q) ? 'q' : \
        (key == LINUX_KEY_E) ? 'e' : \
        (key == LINUX_KEY_R) ? 'r' : \
        (key == LINUX_KEY_Y) ? 'y' : \
        (key == LINUX_KEY_T) ? 't' : \
        (key == LINUX_KEY_O) ? 'o' : \
        (key == LINUX_KEY_U) ? 'u' : \
        (key == LINUX_KEY_I) ? 'i' : \
        (key == LINUX_KEY_P) ? 'p' : \
        (key == LINUX_KEY_L) ? 'l' : \
        (key == LINUX_KEY_J) ? 'j' : \
        (key == LINUX_KEY_K) ? 'k' : \
        (key == LINUX_KEY_N) ? 'n' : \
        (key == LINUX_KEY_M) ? 'm' : \
        '?' \
    )
	
#endif