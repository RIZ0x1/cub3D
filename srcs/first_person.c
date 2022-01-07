/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_person.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:24:54 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:45:49 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			color_transmutation(unsigned color, float x)
{
	unsigned		new_color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)(color >> 16 & 0x000000FF);
	g = (unsigned char)(color >> 8 & 0x000000FF);
	b = (unsigned char)(color & 0x000000FF);
	if (x > 10)
	{
		r /= x / 10;
		g /= x / 10;
		b /= x / 10;
	}
	new_color = 0;
	new_color |= (int)r << 16;
	new_color |= (int)g << 8;
	new_color |= (int)b;
	return (new_color);
}

static void	set_v_line(t_wall *w, t_img *sight, int n)
{
	int			i;
	unsigned	color;
	int			begin;

	begin = (sight->height / 2) - (w[n].wall_h / 2);
	i = begin;
	while (i < (begin + w[n].wall_h))
	{
		color = getcolor(w[n].txtr, w[n].offset,
						((i - begin) * (w[n].txtr->height) / w[n].wall_h));
		color = color_transmutation(color, w[n].depth);
		i = (i < 0) ? 0 : i;
		if (i >= sight->height)
			break ;
		putpixel(sight, n, i, color);
		(i++);
	}
}

void		show_frame(t_data *data)
{
	int		i;
	t_wall	*w;

	i = 0;
	w = data->walls;
	while (i < data->sight.width)
		set_v_line(w, &data->sight, i++);
	free(data->walls);
}
