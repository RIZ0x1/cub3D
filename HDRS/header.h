/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:40:10 by jcarlena          #+#    #+#             */
/*   Updated: 2022/01/07 16:47:33 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include "defines.h"
# include "get_next_line.h"
# include "structures.h"
# include "mlx.h"
# include "need.h"
# include "bmp_utils.h"

/*
** GLOBAL VARS
*/

int			g_win_w;
int			g_win_h;
unsigned	g_ceiling;
unsigned	g_floor;
/*
** LST
*/
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstn(t_list *lst, int n);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_dellist(t_list **lst);
/*
** LIB_SOURCES_1
*/
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *str, int fd);
void		ft_putnbr_fd(int nbr, int fd);
int			ft_isdigit(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
/*
** LIB_SOURCES_2
*/
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
void		*ft_clearlist(char **list, size_t i);
/*
** LIB_SOURCES_3
*/
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_sec_free(void *p);
char		*ft_strrchr(const char *s, int c);
/*
** PRINT PATTERNS
*/
void		putpixel(t_img *image, int x, int y, unsigned color);
void		print_line(t_img *image, t_line line);
void		print_brick(t_img *image, t_brick brick, int sizex, int sizey);
void		fill_img_by(t_img *image, unsigned color);
void		set_ceiling_n_floor(t_data *data);
/*
** MAJOR FUNCTIONS
*/

int			key_hook(int key, t_data *data);
void		create_map(t_data *data, int fd, char *line);
void		matrix_map(t_list **list, t_data *data);
/*
** UTILS 1
*/

int			end_program(t_data *data, int key);
void		move_player(t_data *data, int key);
void		rotate_cam(t_data *data, int key);
int			getcolor(t_img *img, int x, int y);
/*
** UTILS 2
*/

void		set_player(t_data *data);
char		set_position(t_data *data);
float		delta(float a, float b);
void		raycast_init(t_data *data, t_raycast *ray);
/*
** UTILS 3
*/

void		error_handler(const short number);
void		error_handler_2(const short number);
void		sys_error(const int number, const char *error);
void		clear_splitted(char **table);
/*
** UTILS 4
*/

int			char_n(char *s, char c);
void		catch_textures(t_data *data, char *line);
void		catch_color(char *line, unsigned *color);
void		catch_resolution(t_data *data, char *line);

/*
** RAYCASTING
*/

void		raycasting(t_data *data);
/*
**FIRST PERSON
*/
float		min(float a, float b);
float		max(float a, float b);
int			color_transmutation(unsigned color, float x);
void		build_walls(t_data *data, t_raycast *ray);
void		show_frame(t_data *data);
/*
** VALIDATE CONFIG
*/
void		validate_file(t_data *data, char *map_name);
/*
** MINUS_SAVE
*/
void		minus_save(t_data *data);
/*
** VALIDATE_MAP
*/
void		validate_map(t_data *data);

#endif
