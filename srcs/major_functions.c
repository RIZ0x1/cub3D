/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:15 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/16 16:16:47 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		is_empty(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s != ' ')
				return (0);
			(s++);
		}
	}
	return (1);
}

void			create_map(t_data *data, int fd, char *line)
{
	t_list		*list;
	int			len;

	list = NULL;
	data->map.height = 0;
	data->map.width = 0;
	if (!is_empty(line))
		while (is_empty(line) && get_next_line(fd, &line) > 0)
			free(line);
	while (1)
	{
		ft_lstadd_back(&list, ft_lstnew(ft_strdup(line)));
		len = ft_strlen(line);
		data->map.width = (len > data->map.width) ? len : data->map.width;
		(data->map.height++);
		free(line);
		if (get_next_line(fd, &line) <= 0)
			break ;
	}
	data->map.width = (len > data->map.width) ? len : data->map.width;
	ft_lstadd_back(&list, ft_lstnew(ft_strdup(line)));
	free(line);
	data->map.height += (!!data->map.height);
	matrix_map(&list, data);
	close(fd);
}

static void		alloc_matrix(t_data *data)
{
	int		i;

	i = 0;
	if ((data->map.height < 3) || (data->map.width < 3))
		error_handler_2(ERR_WRNG_MAP);
	data->matrix = malloc((data->map.height + 1) * sizeof(char*));
	while (i < data->map.height)
		data->matrix[i++] = malloc((data->map.width + 1) * sizeof(char));
}

void			matrix_map(t_list **list, t_data *data)
{
	char		*p;
	int			i;
	int			j;
	t_list		*tmp;

	tmp = *list;
	alloc_matrix(data);
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		p = (tmp->content);
		while (j < data->map.width)
		{
			if (*p)
				data->matrix[i][j] = *p++;
			else
				data->matrix[i][j] = '\0';
			(j++);
		}
		tmp = tmp->next;
		(i++);
	}
	data->matrix[i] = NULL;
	ft_dellist(list);
}

int				key_hook(int key, t_data *data)
{
	if (key == ESC)
		end_program(data, key);
	else if ((key >= 0 && key <= 2) || key == W)
		move_player(data, key);
	else if (key >= 123 && key <= 126)
		rotate_cam(data, key);
	set_ceiling_n_floor(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->sight.img, 0, 0);
	return (key);
}
