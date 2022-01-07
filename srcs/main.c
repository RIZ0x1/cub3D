/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:13 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 17:14:37 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		init_vars(t_data *data)
{
	int		i;

	g_floor = 0;
	g_ceiling = 0;
	data->paths.no = NULL;
	data->paths.so = NULL;
	data->paths.ea = NULL;
	data->paths.we = NULL;
	i = 0;
	while (i < N_SETTINGS)
		data->set[i++] = '0';
}

static void		init_images(t_data *data)
{
	int		w;
	int		h;

	mlx_get_screen_size(&w, &h);
	g_win_h = (g_win_h < 300) ? 300 : g_win_h;
	g_win_w = (g_win_w < 300) ? 300 : g_win_w;
	g_win_h = (g_win_h > h) ? h : g_win_h;
	g_win_w = (g_win_w > w) ? w : g_win_w;
	data->sight.width = g_win_w;
	data->sight.height = g_win_h;
	data->sight.img = mlx_new_image(data->mlx, data->sight.width,
								data->sight.height);
	data->sight.addr = mlx_get_data_addr(data->sight.img, &data->sight.bpp,
								&data->sight.ll, &data->sight.end);
}

static void		press_any_key(t_data *data)
{
	t_brick		screen;
	int			text_color;
	int			x;
	int			y;

	x = (data->sight.width / 2) - 72;
	y = (data->sight.height / 2) - 20;
	screen.x = 0;
	screen.y = 0;
	screen.color = g_ceiling;
	text_color = ~(g_ceiling << 4) & 0x00FFFFFF;
	print_brick(&data->sight, screen, data->sight.width, data->sight.height);
	mlx_put_image_to_window(data->mlx, data->win, data->sight.img, 0, 0);
	mlx_string_put(data->mlx, data->win, x,
				y, text_color, "PRESS ANY KEY TO START");
}

int				main(int arc, char **arv)
{
	t_data		data;

	if ((arc == 2 || arc == 3) && !ft_strcmp(ft_strrchr(arv[1], '.'), ".cub"))
	{
		data.mlx = mlx_init();
		init_vars(&data);
		validate_file(&data, arv[1]);
		init_images(&data);
		if (arc == 2)
		{
			data.win = mlx_new_window(data.mlx, g_win_w, g_win_h, "Carcosa");
			press_any_key(&data);
			mlx_hook(data.win, 2, 0, key_hook, &data);
			mlx_hook(data.win, 17, 0, end_program, &data);
			mlx_loop(data.mlx);
		}
		else if (arc == 3 && !ft_strcmp(arv[2], "--save"))
			minus_save(&data);
		else
			error_handler_2(ERR_WRNG_ARG);
	}
	else
		sys_error(EINVAL, strerror(EINVAL));
	return (0);
}
