/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:26 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/16 18:22:38 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	set_sprites_location(t_data *data)
{
	int		y;
	int		x;
	int		n;

	n = 0;
	x = 0;
	y = 1;
	while (y < (data->map.height - 1))
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->matrix[y][x] == '2')
			{
				data->sprs[n]->y = y + 0.5;
				data->sprs[n]->x = x + 0.5;
				(n++);
			}
			(x++);
		}
		(y++);
	}
	return (n);
}

void		get_sprites(t_data *data)
{
	int		i;

	if (data->s_n == 0)
		return ;
	data->sprs = malloc(sizeof(t_spr*) * data->s_n);
	i = 0;
	while (i < data->s_n)
		data->sprs[i++] = malloc(sizeof(t_spr));
	set_sprites_location(data);
	i = 0;
	while (i < data->s_n)
	{
		data->sprs[i]->dir = atan2(data->sprs[i]->y - data->pl.y,
									data->sprs[i]->x - data->pl.x);
		data->sprs[i]->dist = sqrt(pow(data->pl.x - data->sprs[i]->x, 2) +
									pow(data->pl.y - data->sprs[i]->y, 2));
		data->sprs[i]->offh = (data->sprs[i]->dir - data->pl.angle) /
					(FOV * data->sprt.width / 2) + (data->sprt.width / 2) /
					2 - (data->sprt.height * data->sprt.width) / 2;
		data->sprs[i]->offv = (data->sprt.height / 2);
		(i++);
	}
}

void		draw_sp_pixel(t_data *data, t_spr sprite, int i, int j)
{
	unsigned color;

	color = getcolor(&data->sprt, i * data->sprt.width / sprite.scale,
									j * data->sprt.height / sprite.scale);
	if ((color & 0xFF000000) >> 24 < 0x7F)
		putpixel(&data->sight, sprite.offh + i, sprite.offv + j, color);
}

void		draw_sp_collumn(t_data *data, t_spr *sp)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < sp->scale)
	{
		if (sp->offh + i < 0 || sp->offh + i >= data->sight.width)
			(i++);
		else if (data->walls[sp->offh + i].depth < sp->dist)
			(i++);
		else
		{
			j = 0;
			while (j < sp->scale)
			{
				if (!(sp->offv + j < 0 || sp->offv + j >= data->sight.height))
					draw_sp_pixel(data, *sp, i, j);
				(j++);
			}
			(i++);
		}
	}
}

void		draw_sprite(t_data *data, t_spr *sp)
{
	sp->dir = atan2f(sp->y - data->pl.y, sp->x - data->pl.x);
	while (sp->dir - data->pl.angle < -PI)
		sp->dir += 2 * PI;
	while (sp->dir - data->pl.angle > PI)
		sp->dir -= 2 * PI;
	sp->dist = sqrt(pow(sp->x - data->pl.x, 2) + pow(sp->y - data->pl.y, 2));
	sp->dist = max(sp->dist, 0.001);
	sp->scale = 400 * (((float)data->sight.height / (float)data->sprt.height)
		+ ((float)data->sight.width / (float)data->sprt.width)) / sp->dist;
	sp->offh = (sp->dir - data->pl.angle) / FOV * (data->sight.width)
							+ data->sight.width / 2 - sp->scale / 2;
	sp->offv = data->sight.height / 2 - sp->scale / 2;
	draw_sp_collumn(data, sp);
}
