/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:40:02 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 17:14:34 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
**KEYS
*/
# define ESC 	53
# define SPC	49
# define UP		126
# define DO		125
# define RI		124
# define LE		123
# define W		13
# define A		0
# define S		1
# define D		2
# define Q		12
# define I		34
/*
**CONSTANTS
*/
# define N_SETTINGS 5
# define PI			3.14159265358979323846264338327950288
# define PI2		6.28318531
# define ROTATION	0.0625
# define MOVE		0.0625
# define FOV		1.15192
# define HALF_FOV	0.57596
# define DIST		20000
/*
**ERRORS
*/
# define ERR_SET_COLOR		0
# define ERR_GET_RES		1
# define ERR_INVALID_SYM	2
# define ERR_GET_TXTURE		3
# define ERR_SET_TXTURE		5
# define ERR_WRNG_SET_NBR	7
# define ERR_COMMENT		8
# define ERR_WRNG_MAP		9
# define ERR_CANT_SAVE_IMG	10
# define ERR_WRNG_ARG		11

#endif
