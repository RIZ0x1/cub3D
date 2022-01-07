/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:24:50 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:55:59 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		char_n(char *s, char c)
{
	int	x;

	x = 0;
	while (*s)
	{
		if (*s == c)
			(x++);
		(s++);
	}
	return (x);
}

void	catch_resolution(t_data *data, char *line)
{
	char	**resolution;
	int		i;
	int		j;

	resolution = ft_split(line, ' ');
	i = 0;
	j = 0;
	while (resolution[i] != NULL)
	{
		j = 0;
		while (resolution[i][j])
			if (!ft_isdigit(resolution[i][j++]))
				error_handler(ERR_GET_RES);
		(i++);
	}
	if (i != 2 || data->set[0] == '1')
		error_handler(ERR_GET_RES);
	if (!(g_win_w = ft_atoi(resolution[0])) ||
		!(g_win_h = ft_atoi(resolution[1])))
		error_handler(ERR_GET_RES);
	g_win_w = (g_win_w < 0) ? 10000 : g_win_w;
	g_win_h = (g_win_h < 0) ? 10000 : g_win_h;
	clear_splitted(resolution);
	data->set[0] = '1';
}

void	catch_color(char *line, unsigned *color)
{
	int			count;
	int			i;
	char		**table;

	count = 0;
	if ((table = ft_split(line, ',')) && (char_n(line, ',') != 2))
		error_handler(ERR_SET_COLOR);
	while (table[count] != NULL)
	{
		i = 0;
		if (count > 2)
			error_handler(ERR_SET_COLOR);
		while (table[count][i])
		{
			if (!ft_isdigit(table[count][i]) && table[count][i] != ' ')
				error_handler(ERR_SET_COLOR);
			(i++);
		}
		i = ft_atoi(table[count]);
		if (i > 255 || i < 0)
			error_handler(ERR_SET_COLOR);
		*color |= i << (8 * (2 - count));
		(count++);
	}
	clear_splitted(table);
}

void	catch_textures(t_data *data, char *line)
{
	char	**path;
	int		num;

	num = 0;
	if (!line[2] || line[2] != ' ')
		error_handler(ERR_GET_TXTURE);
	path = ft_split(&line[2], ' ');
	if (path[1] != NULL)
		error_handler(ERR_GET_TXTURE);
	if (line[0] == 'N' && line[1] == 'O' && (num = 1))
		data->paths.no = ft_strdup(*path);
	else if (line[0] == 'S' && line[1] == 'O' && (num = 2))
		data->paths.so = ft_strdup(*path);
	else if (line[0] == 'W' && line[1] == 'E' && (num = 3))
		data->paths.we = ft_strdup(*path);
	else if (line[0] == 'E' && line[1] == 'A' && (num = 4))
		data->paths.ea = ft_strdup(*path);
	clear_splitted(path);
	if (num && data->set[num] == '1')
		error_handler(ERR_GET_TXTURE);
	data->set[num] = '1';
}
