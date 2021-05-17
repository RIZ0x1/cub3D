/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:40:30 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 08:14:54 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_conf
{
	char			*txture_path;
}					t_conf;

typedef struct		s_brick
{
	int				x;
	int				y;
	unsigned		color;
}					t_brick;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				end;
	int				height;
	int				width;
}					t_img;

typedef struct		s_player
{
	float			x;
	float			y;
	float			dirx;
	float			diry;
	float			angle;
}					t_player;

typedef struct		s_list
{
	char			*content;
	char			*p;
	struct s_list	*next;
}					t_list;

typedef struct		s_paths
{
	char			*no;
	char			*ea;
	char			*so;
	char			*we;
	char			*spr;
}					t_paths;

typedef struct		s_line
{
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	unsigned		color;
}					t_line;

typedef struct		s_raycast
{
	int		n;
	float	angle;
	float	delta_angle;
	float	x;
	float	y;
	float	xm;
	float	ym;
	float	dx;
	float	dy;
	float	v_depth;
	float	h_depth;
	float	reservx;
	float	reservy;
}					t_raycast;

typedef struct		s_wall
{
	int		wall_h;
	float	depth;
	float	offset;
	float	side;
	t_img	*txtr;
}					t_wall;

typedef struct		s_spr
{
	float	x;
	float	y;
	float	dir;
	float	dist;
	int		offh;
	int		offv;
	int		screen;
	float	scale;

}					t_spr;

typedef struct		s_map
{
	int				height;
	int				width;
}					t_map;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	char			**matrix;
	t_map			map;
	char			set[6];
	int				s_n;
	t_wall			*walls;
	t_spr			**sprs;
	t_player		pl;
	t_img			sight;
	t_img			no;
	t_img			ea;
	t_img			so;
	t_img			we;
	t_img			sprt;
	t_paths			paths;
}					t_data;

#endif
