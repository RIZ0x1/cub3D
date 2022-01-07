/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:31 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:38:18 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_for_junk(char **mx, int h, int w)
{
	int		y;
	int		x;
	int		us;
	char	c;

	us = 0;
	y = 1;
	x = 0;
	while (y < (h - 1))
	{
		x = 0;
		while (x < w)
		{
			c = mx[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S' &&
			c != 'E' && c != 'W' && c != ' ' && c != '\0')
				return (0);
			else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				if (++us > 1)
					return (0);
			(x++);
		}
		(y++);
	}
	return (us);
}

static int	check_edge(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		(i++);
	}
	return (1);
}

static int	check_body(char **mx, int h, int w)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 1;
	while (y < (h - 1))
	{
		x = 0;
		while (x < w)
		{
			c = mx[y][x];
			if (c == '0' || c == '2' || c == 'N' ||
				c == 'S' || c == 'E' || c == 'W')
			{
				if (mx[y - (y > 0)][x] == ' ' || mx[y + (y < h)][x] == ' ' ||
					mx[y][x - (x > 0)] == ' ' || mx[y][x + (x < w)] == ' ' ||
					x == 0 || x == (w - 1))
					return (0);
			}
			(x++);
		}
		(y++);
	}
	return (1);
}

void		validate_map(t_data *data)
{
	if (!check_for_junk(data->matrix, data->map.height, data->map.width))
		error_handler_2(ERR_WRNG_MAP);
	if (!check_edge(data->matrix[0]))
		error_handler_2(ERR_WRNG_MAP);
	if (!check_body(data->matrix, data->map.height, data->map.width))
		error_handler_2(ERR_WRNG_MAP);
	if (!check_edge(data->matrix[data->map.height - 1]))
		error_handler_2(ERR_WRNG_MAP);
	set_player(data);
}
