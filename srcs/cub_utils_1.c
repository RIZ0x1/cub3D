/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:24:21 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/14 09:15:07 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			end_program(t_data *data, int key)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
	return (key);
}

static void	spr_collision(t_data *data, float x, float y)
{
	if (data->matrix[(int)(data->pl.y)][(int)(data->pl.x)] == '1' ||
		data->matrix[(int)(data->pl.y)][(int)(data->pl.x)] == '2' ||
		data->matrix[(int)(delta(data->pl.y, y) / 2)][(int)(delta(data->pl.x, x) / 2)] == '1' ||
		data->matrix[(int)(delta(data->pl.y, y) / 2)][(int)(delta(data->pl.x, x) / 2)] == '2')
	{
		data->pl.y = y;
		data->pl.x = x;
	}
}

void		move_player(t_data *data, int key)
{
	int		dir;
	float	x;
	float	y;

	x = data->pl.x;
	y = data->pl.y;
	if (key == W || key == S)
	{
		dir = (key == W) ? 1 : -1;
		data->pl.x += data->pl.dirx * dir;
		data->pl.y += data->pl.diry * dir;
	}
	if (key == A)
	{
		data->pl.x -= cos(data->pl.angle + 1.5708) * MOVE;
		data->pl.y -= sin(data->pl.angle + 1.5708) * MOVE;
	}
	if (key == D)
	{
		data->pl.x += cos(data->pl.angle + 1.5708) * MOVE;
		data->pl.y += sin(data->pl.angle + 1.5708) * MOVE;
	}
	spr_collision(data, x, y);
}

void		rotate_cam(t_data *data, int key)
{
	if (key == LE)
	{
		data->pl.angle -= ROTATION;
		if (data->pl.angle < 0)
			data->pl.angle += PI2;
		data->pl.dirx = cos(data->pl.angle) * MOVE;
		data->pl.diry = sin(data->pl.angle) * MOVE;
	}
	else if (key == RI)
	{
		data->pl.angle += ROTATION;
		if (data->pl.angle > PI2)
			data->pl.angle -= PI2;
		data->pl.dirx = cos(data->pl.angle) * MOVE;
		data->pl.diry = sin(data->pl.angle) * MOVE;
	}
}

int			getcolor(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bpp / 8));
	if (dst)
		return (*(int*)dst);
	else
		return (-1);
}
