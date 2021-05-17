/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:49:06 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 05:49:08 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEED_H
# define NEED_H

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct	s_bitmapfileheader
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfo
{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	bitcount;
	int		compression;
	int		sizeimage;
	int		xpelspermeter;
	int		ypelspermeter;
	int		clrused;
	int		clrimportant;
}				t_bitmapinfo;

/*
** Sructure for setting/storage bmpfile image
*/
typedef struct	s_bmpfile
{
	t_bitmapfileheader	fileheader;
	t_bitmapinfo		info;
	char				*data;
}				t_bmpfile;

#endif
