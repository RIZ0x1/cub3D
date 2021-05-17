/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:24:57 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 04:25:43 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_sprs(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->s_n)
	{
		free(data->sprs[i]);
		(i++);
	}
	free(data->sprs);
}