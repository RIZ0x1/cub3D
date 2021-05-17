/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:12:52 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/30 00:17:02 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_find_nl(char **str)
{
	char		*str2;
	char		*tmp;

	str2 = NULL;
	tmp = NULL;
	if (str != NULL && ft_strchr(*str, '\n'))
	{
		str2 = ft_substr_nl(*str, 0,
		(ft_strlen(*str) - ft_strlen(ft_strchr(*str, '\n'))));
		tmp = ft_strdup(ft_strchr(*str, '\n') + 1);
		free(*str);
		*str = NULL;
		*str = (char *)ft_strdup(str2);
	}
	if (str2)
		free(str2);
	return (tmp);
}

static char		*ft_delnjoin(char *s1, char *s2)
{
	char		*tmp;

	tmp = ft_strdup(s1);
	free(s1);
	s1 = ft_strjoin(s2, tmp);
	free(tmp);
	free(s2);
	s2 = NULL;
	return (s1);
}

static int		ft_getpiece(int fd, char **str)
{
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			stop;
	int			ret;

	ret = 1;
	stop = 1;
	while ((ret > 0) && stop == 1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (fd < 0 || ret < 0)
			return (-1);
		buff[ret] = '\0';
		if (*str)
		{
			tmp = ft_strdup(*str);
			free(*str);
			*str = ft_strjoin(tmp, buff);
			free(tmp);
		}
		else
			*str = ft_strdup(buff);
		stop = ft_strchr(buff, '\n') ? 0 : 1;
	}
	return (ret);
}

static int		ft_delstring(char *str, int error)
{
	free(str);
	str = NULL;
	return (error);
}

int				get_next_line(const int fd, char **line)
{
	char			*p;
	static char		*stat;
	int				ret;

	p = ft_strdup("\0");
	ret = ft_getpiece(fd, &p);
	if (ret < 0 || !(line) || BUFFER_SIZE <= 0)
		return (ft_delstring(p, -1));
	p = (stat != NULL) ? ft_delnjoin(p, stat) : p;
	stat = NULL;
	if ((ret == 0 && !ft_strchr(p, '\n') && !ft_strchr(stat, '\n')))
	{
		*line = ft_strdup(p);
		return (ft_delstring(p, 0));
	}
	if (ret >= 0)
	{
		stat = ft_find_nl(&p);
		*line = ft_strdup(p);
	}
	return (ft_delstring(p, 1));
}
