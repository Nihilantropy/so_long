/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crea <crea@student.42roma.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:04:59 by crea              #+#    #+#             */
/*   Updated: 2024/04/09 21:36:17 by crea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/* main */
# define ERROR_ARG_NBR "\nError. Choose a map!\n"

/* check_map_extention */
# define CORRECT_MAP_EXT "\nMap extention in good! Bravo!\n"
# define ERROR_MAP_EXT "\nError. Wrong map extention! .ber is not that hard... Not that easy too tho.\n"

/* get_map */
# define ERROR_MATRIX_ALLOC "\nError. Can't allocate memory for the map! Nothing else to say...\n"
# define MAP_CHECK_OK "\nALL good! Go haed hellwalker Skeletronk!\n"

/* get_map_utils */
# define PLAYER_POS "\nSkeletronk position is somewhere!\n"
# define ENEMY_POS "\nEnemy NVM, pos is {x} {y}\n"
# define ENEMY_ALIVE "\nEnemy boh, is alive.\n"
# define ENEMY_INDEX "\nEnemy index is i don't know\n"
# define ENEMY_NEW_POS "\nEnemy (42 doesn't want us to know) new position is {x} {y}\n"
# define ERROR_CANT_OPEN_MAP_FILE "\nError. Map file can't be open. Have you checked the name of the map file?\n"

/* check_map_interior */
# define CORRECT_PLAYER_NBR "\nTHE ONE PLAYER START! The one and only... Skeletronk!!!\n"
# define ERROR_PLAYER_NBR "\nError. Wrong number of player start: 0\n"
# define CORRECT_EXIT_NBR "\nTHE ONE EXIT! You can escape hell!\n"
# define ERROR_EXIT_NBR "\nError. Wrong number of exit: 0. What are you? A pussycat?\n"
# define CORRECT_COLLECT_NBR "\nLots COLLECTABLES to pick up! Your D is knocking on heaven's door!\n"
# define ERROR_COLLECT_NBR "\nError. Not enoght bones: 0. What about your boner? It's sad, isn't it?\n"
# define CORRECT_SYMBOLS_IN_MAP "\nAll symbols in map are good! Great job my hellwalker!\n"
# define ERROR_SYMBOL_IN_MAP "\nError. Wrong symbol in map! Cheating isn't allowd here! Try in 42...\n"
# define ENEMY_NBR "\n1 ENEMY in hell right now. It's time to turno your punta into a drill!\n"
# define ENEMIES_NBR "\nA lot of ENEMIES in hell right now. Try to avoid, or give them the punta!\n"
# define NO_ENEMY "\nThere are no enemies in hell... what an easy life for your lazy ass.\n"

/* check_map_edges */
# define ERROR_MAP_TOP "\nError. Hell top isn't closed! Angles will pee on you!\n"
# define MAP_TOP_OK "\nHell top is well closed! You won't get wet!\n"
# define ERROR_MAP_BOTTOM "\nError. Hell boottom isn't closed! You'll drown in pee!\n"
# define MAP_BOTTOM_OK "\nHell bottom is well closed! You won't drown in pee!\n"
# define ERROR_MAP_SIDES "\nError. Sides are open! They will reach you...\n"
# define MAP_SIDES_OK "\nHell sides are well-fanced! They won't be able to reach you...\n"
# define ERROR_MAP_RECT "\nError. Hell is what? circol? triangle? wtf?! Make a rectangle!\n"
# define MAP_RECT_OK "\nYour Hell is perfectly square! Top notch!\n"

/* che_if_map_is_complete */
# define MAP_CAN_BE_COMPLETED "\nYou can get all your bones and escape! Go get that boner!\n"
# define ERROR_CANT_REACH_COLLECT "\nError. Some of your bones are trapped! Oh no! Your boner!!!.\n"
# define ERROR_CANT_REACH_EXIT "\nError. Someone doesn't want you to escape... What a coward.\n"
# define ERROR_MAP_CANT_BE_COMPLETED "\nYou won't be able to escape hell... Ask your daddy for help.\n"
# define ERROR_BOOL_MATRIX_ALLOC "\nError. Can't allocate the boolean matrix.\n"

/* images upload */
# define ERROR_WALL_IMG_UPLOAD "\nError. Can't upload wall images.\n"
# define ERROR_PLAYER_IMG_UPLOAD "\nError. Can't upload player images.\n"
# define ERROR_PLAYER_D_IMG_UPLOAD "\nError. Can't upload player d images.\n"
# define ERROR_PLAYER_INV_IMG_UPLOAD "\nError. Can't upload player inverted images.\n"
# define ERROR_PLAYER_D_INV_IMG_UPLOAD "\nError. Can't upload player d inverted images.\n"
# define ERROR_COLLECT_IMG_UPLOAD "\nError. Can't upload collectable images.\n"
# define ERROR_EXIT_IMG_UPLOAD "\nError. Can't upload exit images.\n"
# define ERROR_ENEMY_IMG_UPLOAD "\nError. Can't upload enemy images.\n"
# define ERROR_NUMBER_IMG_UPLOAD "\nError. Can't upload number images.\n"

/* render map */
# define ERROR_NUMBER_IMG_ALLOC "\nError. Number images can't be allocated.\n"
# define ERROR_FREE_IMAGE "\nError. Can't deallocate memory for some images.\n"

/* player movement_utils */
# define ERROR_INVALID_ROUT "\nError. Are you trying to brake the wall? What are you, a Pink floyd fan?\n"
# define ERROR_INVALID_KEY "\nError. Try to smash another button... Or I'll smash your sis.\n"
# define COLLECTABLES_NBR "\nRemaining bones: a lot! You're boner is getting harder!\n"
# define ALL_COLLECT_PICKEDUP "\nYou've earned FULL POWER! Don't waste time! Your boner might disappear!\n"
# define MOVES_NBR "\nYou've made a lot of moves! Keep goin Skeletronk!\n"
# define ERROR_EXIT_NOT_OPEN "\nError. Do you have all the bones? Are you sure? That doesn't seems a big boner to me...\n"
# define NEW_PLAYER_POS "\nYour new position is somewhere! Keep navigate hell!\n"

/* player movement */
# define EARLY_GAME_CLOSE "\nLeaving hell? already? what about your boner???\n"
# define FINAL_MOVE "\nYou got that boner with not so many moves! You're a real champ!\n"
# define FINAL_JOKE "\nSo many moves to get a boner??? Should i call you Rocco or just turtle? Anyway...\n"
# define WIN_MSG "\nWHAT AN AMAZING BONER! CONGRATS!\n"
# define WIN_JOKE "\nA PERFECTLY RESPECTABLE BONER! CONGRATS TURTLE!\n"
# define SECRET_LOCKED "\nSECRET IS LOCKED! Try to make secret come true\n"
# define SECRET_UNLOCKED "\nSECRET HAS BEEN DISCOVERED! Congratulation mighty hero!\n"

/* losing msg */
# define PLAYER_GOT_CAUGHT "\nYOU DIED\n"
# define ENEMY_GOT_PLAYER "\nHELL GOT YOU\n"
# define GAME_LOST "\nGame lost. Maybe you can try minecraft...\n"

/* enemy mechanics */
# define ENEMY_BUMP_PLAYER "\nThey really want to die... what a bunch of idiots!\n"

/* player mechanics */
# define ON_FIRE "\nYour pipi is on fire!!! It's time to give some punta\n"
# define RUN_OUT "\nChill now. You're gonna die for dehydration...\n"
# define PLAYER_DESTROY_ENEMY "\nUlala! That's some hard smashing D! Right between the eyes!\n"
# define ENEMIES_ALIVE_NBR "\nStill a lot of enemies alive! Someone has to do all the work...\n"
# define ENEMY_ALIVE_1 "\nOnly one enemy alive! Dig that hole dwarf! Diggy diggy hole!\n"
# define NO_MORE_ENEMIES "\nAll enemies are gone! You could break a wall with that you know? That's some nasty shi...\n"

/* enemy mechanics utils */
# define ERROR_ENEMY_ALLOC "\nError. Can't allocate memory for enemy array.\n"

/* player mechanics utils */
# define ERROR_REALLOC_ENEMY_ARR "\nError. Reallocation of enemy array failed.\n"

#endif