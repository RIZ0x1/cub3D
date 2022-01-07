/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:24:43 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:45:27 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		sys_error(const int number, const char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putnbr_fd(number, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd((char*)error, 2);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void		clear_splitted(char **table)
{
	char **p;

	if (table && *table)
	{
		p = table;
		while (*p != NULL)
			free(*p++);
		free(table);
	}
}

void		error_handler(const short number)
{
	ft_putstr_fd("Error\n", 2);
	ft_putnbr_fd(-1, 2);
	ft_putstr_fd(": ", 2);
	if (number == ERR_SET_COLOR)
		ft_putstr_fd("Wrong color setting\n", 2);
	else if (number == ERR_GET_RES)
		ft_putstr_fd("Wrong resolution setting\n", 2);
	else if (number == ERR_INVALID_SYM)
		ft_putstr_fd("Invalid symbol in the configuration file\n", 2);
	else if (number == ERR_GET_TXTURE)
		ft_putstr_fd("Wrong path to wall texture (get)\n", 2);
	else if (number == ERR_SET_TXTURE)
		ft_putstr_fd("Wrong path to wall texture (set)\n", 2);
	else if (number == ERR_WRNG_SET_NBR)
		ft_putstr_fd("Invalid configuration file\n", 2);
	else if (number == ERR_COMMENT)
		ft_putstr_fd("Comment after settings\n", 2);
	else
		error_handler_2(number);
	exit(EXIT_FAILURE);
}

void		error_handler_2(const short number)
{
	ft_putstr_fd("Error\n", 2);
	ft_putnbr_fd(-1, 2);
	ft_putstr_fd(": ", 2);
	if (number == ERR_WRNG_MAP)
		ft_putstr_fd("Wrong map setted\n", 2);
	else if (number == ERR_CANT_SAVE_IMG)
		ft_putstr_fd("Can't save the image\n", 2);
	else if (number == ERR_WRNG_ARG)
		ft_putstr_fd("Wrong argument\n", 2);
	exit(EXIT_FAILURE);
}
