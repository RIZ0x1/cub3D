/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:34 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 04:39:33 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float		min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float		max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		build_walls(t_data *data, t_raycast *ray)
{
	const int	dist = (data->sight.width / (2 * tan(HALF_FOV)));
	t_wall		*w;

	w = &data->walls[ray->n];
	w->depth = min(ray->h_depth, ray->v_depth);
	w->side = w->depth;
	w->depth *= cos(data->pl.angle - ray->angle);
	w->depth = max(w->depth, 0.00001);
	w->wall_h = (dist / w->depth);
	if (w->side == ray->v_depth)
	{
		w->txtr = (ray->dx < 0) ? &data->we : &data->ea;
		w->offset = ray->reservy - floor(ray->reservy);
		w->offset = ray->x > data->pl.x ? w->offset : 1.0 - w->offset;
		w->offset *= w->txtr->width;
		w->offset = (w->offset < 0) ? w->offset + w->txtr->width : w->offset;
	}
	else if (w->side == ray->h_depth)
	{
		w->txtr = (ray->dy < 0) ? &data->no : &data->so;
		w->offset = ray->x - floor(ray->x);
		w->offset = ray->reservy > data->pl.y ? 1.0 - w->offset : w->offset;
		w->offset *= w->txtr->width;
		w->offset = (w->offset < 0) ? w->offset + w->txtr->width : w->offset;
	}
}
