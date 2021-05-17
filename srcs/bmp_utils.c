/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:16:17 by enena             #+#    #+#             */
/*   Updated: 2021/03/12 14:42:01 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		set_bmp_info_from_image(t_bitmapinfo *info, t_img *img)
{
	info->size = BMP_SIZEOFINFO;
	info->width = img->width;
	info->height = -img->height;
	info->planes = BMP_PLANES;
	info->bitcount = BMP_BITPERPIXEL;
	info->compression = BMP_COMPRESSION;
	info->sizeimage = BMP_SIZEIMAGE;
	info->xpelspermeter = BMP_XPELSPERMETER;
	info->ypelspermeter = BMP_YPELSPERMETER;
	info->clrused = BMP_CLRUSED;
	info->clrimportant = BMP_CLRIMPORTANT;
}

static void		set_bmp_data_from_image(t_bmpfile *bmp, t_img *img)
{
	ft_memcpy(bmp->fileheader.type, BMP_IDENTIFIER, sizeof(BMP_IDENTIFIER));
	bmp->fileheader.size = img->width * img->height * BMP_BYTEPERPIXEL +
		BMP_SIZEOFHEADER;
	bmp->fileheader.reserved = 0;
	bmp->fileheader.offset = BMP_SIZEOFHEADER;
	set_bmp_info_from_image(&bmp->info, img);
	bmp->data = img->addr;
}

int				save_image_as_bmp(t_img *img, const char *name)
{
	int			fd;
	char		*bmp_file_name;
	t_bmpfile	bmp_data;

	if (!(bmp_file_name = ft_strjoin(name, BMP_EXTN)))
		error_handler_2(ERR_CANT_SAVE_IMG);
	if ((fd = open(bmp_file_name, O_CREAT | O_WRONLY | O_TRUNC,
											S_IRUSR | S_IWUSR)) < 0)
		error_handler_2(ERR_CANT_SAVE_IMG);
	bmp_file_name = ft_sec_free(bmp_file_name);
	set_bmp_data_from_image(&bmp_data, img);
	if (!(ft_write_bmp(fd, &bmp_data)))
	{
		if (close(fd) < 0)
			error_handler_2(ERR_CANT_SAVE_IMG);
		error_handler_2(ERR_CANT_SAVE_IMG);
	}
	if (close(fd) < 0)
		error_handler_2(ERR_CANT_SAVE_IMG);
	return (1);
}
