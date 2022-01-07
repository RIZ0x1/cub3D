/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:24:33 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:45:13 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		set_position(t_data *data)
{
	int		i;
	int		j;
	char	c;

	data->pl.x = 0;
	data->pl.y = 0;
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			c = data->matrix[i][j];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				data->pl.x = (float)(j + 0.4921875);
				data->pl.y = (float)(i + 0.4921875);
				return (data->matrix[i][j]);
			}
			(j++);
		}
		(i++);
	}
	return (0);
}

void		set_player(t_data *data)
{
	char direction;

	direction = set_position(data);
	if (direction == 'N')
		data->pl.angle = 4.71239;
	else if (direction == 'E')
		data->pl.angle = 0.0;
	else if (direction == 'W')
		data->pl.angle = PI;
	else
		data->pl.angle = 1.5708;
	data->pl.dirx = cos(data->pl.angle) * MOVE;
	data->pl.diry = sin(data->pl.angle) * MOVE;
}

void		raycast_init(t_data *data, t_raycast *ray)
{
	ray->dx = 0;
	ray->dy = 0;
	ray->xm = (int)data->pl.x;
	ray->ym = (int)data->pl.y;
	ray->angle = (data->pl.angle - (HALF_FOV));
	ray->n = 0;
	ray->delta_angle = (FOV / data->sight.width);
}

float		delta(float a, float b)
{
	return (fabs(a - b));
}