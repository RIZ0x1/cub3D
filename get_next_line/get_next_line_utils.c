/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:06:04 by jcarlena          #+#    #+#             */
/*   Updated: 2020/12/30 00:17:04 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char					*ft_substr_nl(char *str, int start, int len)
{
	int		i;
	char	*output;

	i = 0;
	if (!str)
		return (NULL);
	if (!(output = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start < len && (str[start] != '\n'))
	{
		output[start] = str[start];
		(start++);
	}
	output[start] = '\0';
	return (output);
}

size_t					ft_strlen(const char *s)
{
	int	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n] != '\0')
		(n++);
	return (n);
}

char					*ft_strchr(const char *s, int c)
{
	int					i;
	char				*tmp;

	i = 0;
	tmp = (char *)s;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*tmp)
			(tmp++);
		return (tmp);
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		(i++);
	}
	if (*tmp == '\0' && c == '\0')
		return (tmp);
	return (NULL);
}

char					*ft_strdup(const char *s)
{
	char	*output;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(output = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		output[i] = s[i];
		(i++);
	}
	output[i] = '\0';
	return (output);
}

char					*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	char			*k;
	unsigned int	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((p = malloc((size + 1) * sizeof(s1))) == NULL)
		return (NULL);
	k = p;
	while (*s1)
	{
		*p = *s1;
		(p++);
		(s1++);
	}
	while (*s2)
	{
		(*p) = (*s2);
		(p++);
		(s2++);
	}
	*p = '\0';
	return (k);
}
