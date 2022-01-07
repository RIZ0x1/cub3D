/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:23 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:35:47 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		stop_loop_v(t_data *data, t_raycast *ray)
{
	int z;

	z = 0;
	if (ray->dx < 0)
		z = -1;
	if ((ray->y < 0 || ray->y >= data->map.height) ||
		((int)(ray->x + z) < 0) ||
		((int)(ray->x + z) >= data->map.width) ||
		((int)(ray->y + z) < 0) ||
		((int)(ray->y + z) >= data->map.height) ||
		(data->matrix[(int)(ray->y)][(int)(ray->x + z)] == '1') ||
		((pow((ray->x - data->pl.x), 2) + pow(ray->y - data->pl.y, 2)) > DIST))
		return (1);
	else
		return (0);
}

static int		stop_loop_h(t_data *data, t_raycast *ray)
{
	int	z;

	z = 0;
	if (ray->dy < 0)
		z = -1;
	if ((ray->y < 0 || ray->y >= data->map.height) ||
		(((int)ray->x + z) < 0) ||
		(((int)ray->x + z) >= data->map.width) ||
		(((int)ray->y + z) <= 0) ||
		(((int)ray->y + z) >= data->map.height) ||
		(data->matrix[(int)(ray->y + z)][(int)(ray->x)] == '1') ||
		((pow((ray->x - data->pl.x), 2) + pow(ray->y - data->pl.y, 2)) > DIST))
		return (1);
	else
		return (0);
}

static int		calculate_v_depth(t_data *data, t_raycast *ray)
{
	ray->v_depth = (ray->x - data->pl.x) / cos(ray->angle);
	ray->y = data->pl.y + ray->v_depth * sin(ray->angle);
	if (stop_loop_v(data, ray))
		return (0);
	ray->x += ray->dx;
	return (1);
}

static int		calculate_h_depth(t_data *data, t_raycast *ray)
{
	ray->h_depth = (ray->y - data->pl.y) / sin(ray->angle);
	ray->x = data->pl.x + ray->h_depth * cos(ray->angle);
	if (stop_loop_h(data, ray))
		return (0);
	ray->y += ray->dy;
	return (1);
}

void			raycasting(t_data *data)
{
	t_raycast		ray;

	raycast_init(data, &ray);
	data->walls = malloc(sizeof(t_wall) * data->sight.width);
	while (ray.n < data->sight.width)
	{
		ray.x = ray.xm + 1 - (cos(ray.angle) <= 0.0);
		ray.dx = (cos(ray.angle) <= 0.0) ? -1 : 1;
		while (1)
			if (!calculate_v_depth(data, &ray))
				break ;
		ray.reservy = ray.y;
		ray.y = ray.ym + 1 - (sin(ray.angle) <= 0.0);
		ray.dy = (sin(ray.angle) <= 0.0) ? -1 : 1;
		while (1)
			if (!calculate_h_depth(data, &ray))
				break ;
		build_walls(data, &ray);
		(ray.n++);
		ray.angle += ray.delta_angle;
	}
	show_frame(data);
}
