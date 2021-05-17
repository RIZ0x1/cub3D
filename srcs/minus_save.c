/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_save.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:18 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/16 17:16:22 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		minus_save(t_data *data)
{
	set_ceiling_n_floor(data);
	raycasting(data);
	save_image_as_bmp(&data->sight, "carcosa");
	exit(EXIT_SUCCESS);
}
