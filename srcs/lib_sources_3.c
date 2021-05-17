/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_sources_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:07 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 04:41:53 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned		i;
	char			*ps1;
	char			*ps2;

	if (!s1 || !s2)
		return (-1);
	ps1 = (char*)s1;
	ps2 = (char*)s2;
	i = 0;
	while (ps1[i] && ps2[2] && (ps1[i] == ps2[i]))
		(i++);
	return (ps1[i] - ps2[i]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	while (n && (dst || src))
	{
		*d = *s;
		(d++);
		(s++);
		(n--);
	}
	return (dst);
}

void	*ft_sec_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char*)s;
	i = 0;
	while (p[i])
		(i++);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (&p[i]);
		(i--);
	}
	return (NULL);
}
