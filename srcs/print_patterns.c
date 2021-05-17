/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:20 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/16 16:56:09 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		putpixel(t_img *image, int x, int y, unsigned color)
{
	char	*dst;

	dst = image->addr + (y * image->ll + x * (image->bpp / 8));
	*(unsigned int*)dst = color;
}

void		print_brick(t_img *image, t_brick brick, int sizex, int sizey)
{
	int		tmp_y;
	int		tmp_x;

	tmp_x = 0;
	while (tmp_x < sizex)
	{
		tmp_y = 0;
		while (tmp_y < sizey)
		{
			putpixel(image, brick.x + tmp_x, brick.y + tmp_y, brick.color);
			(tmp_y++);
		}
		(tmp_x++);
	}
}

void		set_ceiling_n_floor(t_data *data)
{
	t_brick background;

	background.x = 0;
	background.y = 0;
	background.color = g_ceiling;
	print_brick(&data->sight, background, data->sight.width,
				data->sight.height / 2);
	background.x = 0;
	background.y = (data->sight.height / 2) + 1;
	background.color = g_floor;
	print_brick(&data->sight, background, data->sight.width,
				(data->sight.height / 2) - (data->sight.height % 2 == 0));
}
