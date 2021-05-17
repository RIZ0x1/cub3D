/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:29 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/14 09:06:30 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		set_textures(t_data *data)
{
	data->no.img = mlx_png_file_to_image(data->mlx, data->paths.no,
										&data->no.width, &data->no.height);
	data->ea.img = mlx_png_file_to_image(data->mlx, data->paths.ea,
										&data->ea.width, &data->ea.height);
	data->so.img = mlx_png_file_to_image(data->mlx, data->paths.so,
										&data->so.width, &data->so.height);
	data->we.img = mlx_png_file_to_image(data->mlx, data->paths.we,
										&data->we.width, &data->we.height);
	data->sprt.img = mlx_png_file_to_image(data->mlx, data->paths.spr,
									&data->sprt.width, &data->sprt.height);
	if (!data->no.img || !data->ea.img ||
		!data->so.img || !data->we.img ||
		!data->sprt.img)
		sys_error(ENOENT, strerror(ENOENT));
	data->no.addr = mlx_get_data_addr(data->no.img, &data->no.bpp,
										&data->no.ll, &data->no.end);
	data->ea.addr = mlx_get_data_addr(data->ea.img, &data->ea.bpp,
										&data->ea.ll, &data->ea.end);
	data->so.addr = mlx_get_data_addr(data->so.img, &data->so.bpp,
										&data->so.ll, &data->so.end);
	data->we.addr = mlx_get_data_addr(data->we.img, &data->we.bpp,
										&data->we.ll, &data->we.end);
	data->sprt.addr = mlx_get_data_addr(data->sprt.img, &data->sprt.bpp,
										&data->sprt.ll, &data->sprt.end);
}

static int		texture_case(char *line)
{
	return ((line[0] == 'N' && line[1] == 'O') ||
			(line[0] == 'S' && line[1] == 'O') ||
			(line[0] == 'W' && line[1] == 'E') ||
			(line[0] == 'E' && line[1] == 'A'));
}

static int		check_settings(char *set)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (i < 6 && ret != -1)
	{
		if (set[i] == '0')
			ret = 0;
		(i++);
	}
	return (ret && g_ceiling && g_floor);
}

static int		main_cases(t_data *data, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		catch_resolution(data, &line[1]);
	else if (texture_case(line))
		catch_textures(data, line);
	else if (line[0] == 'S')
		catch_sprite(data, line);
	else if (line[0] == 'F' && line[1] == ' ' && !g_floor)
		catch_color(&line[1], &g_floor);
	else if (line[0] == 'C' && line[1] == ' ' && !g_ceiling)
		catch_color(&line[1], &g_ceiling);
	else
		return (0);
	return (1);
}

void			validate_file(t_data *data, char *map_name)
{
	char		*line;
	int			fd;

	if ((fd = open(map_name, O_RDONLY)) < 0)
		sys_error(EBADF, strerror(EBADF));
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if ((line[0] == '\0' && !check_settings(data->set)))
			;
		else if (main_cases(data, line))
			;
		else if (check_settings(data->set) == 1)
			break ;
		else
			error_handler(ERR_WRNG_SET_NBR);
		free(line);
	}
	create_map(data, fd, line);
	validate_map(data);
	data->s_n = count_sprites(data);
	set_textures(data);
	close(fd);
}
