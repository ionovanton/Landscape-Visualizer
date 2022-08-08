/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:56:59 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:43:55 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// Options
# define WINDOW_NAME		"fdf"
# define STD_WIDTH			1280
# define STD_HEIGHT			720
# define STD_OFFSET			200
# define STD_ANGLE			0.988888888
# define STD_ZOOM			40
# define SUCCESS			0
# define FAIL				1

// Shifts
# define SHIFT_ANGLE		0.03
# define SHIFT_ZOOM			1
# define SHIFT_POS			10

// Projections
# define P_ISOMETRIC		1
# define P_SIDE				2
# define P_FLAT				3

// Colors
# define COLOR_DEBUG		0xFF2425
# define COLOR_BACKGROUND	0x19191D
# define COLOR_GREEN		0x6CDF91
# define COLOR_WHITE		0xE6E2E6

// Events
# define EVENT_CLOSE		17

// Keys
# ifdef __APPLE__
#  define KEY_1				18
#  define KEY_2				19
#  define KEY_3				20
#  define KEY_MINUS			27
#  define KEY_PLUS			24
#  define KEY_Q				12
#  define KEY_E				14
#  define KEY_W				13
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_UP			126
#  define KEY_LEFT			123
#  define KEY_RIGHT			124
#  define KEY_DOWN			125
#  define KEY_ESC			53
# elif __unix__
#  define KEY_1				49
#  define KEY_2				50
#  define KEY_3				51
#  define KEY_MINUS			45
#  define KEY_PLUS			61
#  define KEY_Q				113
#  define KEY_E				101
#  define KEY_W				119
#  define KEY_A				97
#  define KEY_S				115
#  define KEY_D				100
#  define KEY_UP			65362
#  define KEY_LEFT			65361
#  define KEY_RIGHT			65363
#  define KEY_DOWN			65364
#  define KEY_ESC			65307
# endif

# define MSG_ERROR_PATH		"Usage: \"./fdf PATH_TO_MAP\""
# define MSG_ERROR_INIT		"Init error."

#endif // DEFINE_H
