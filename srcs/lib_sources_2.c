/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_sources_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:04 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 04:40:50 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			*ft_calloc(size_t count, size_t size)
{
	void		*new;
	char		*p;
	size_t		fullsize;

	fullsize = (count * size);
	new = malloc(fullsize);
	if (new)
	{
		p = new;
		while (fullsize)
		{
			*p = '\0';
			(p++);
			(fullsize--);
		}
	}
	return (new);
}

static size_t	ft_countwords(const char *s, char c)
{
	size_t n;
	size_t i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
			(n++);
		while (s[i] != c && s[i])
			(i++);
		while (s[i] == c && s[i])
			(i++);
	}
	return (n);
}

static size_t	ft_wordsize(const char *word, const char c)
{
	size_t n;

	n = 0;
	while (*word == c)
		(word)++;
	while (word[n] != c && word[n])
		(n++);
	return (n);
}

void			*ft_clearlist(char **list, size_t i)
{
	i = 0;
	while (i > 0)
	{
		free(list[i]);
		(i++);
	}
	free(list);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**list;
	size_t	lsize;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	lsize = ft_countwords(s, c);
	if (!(list = malloc((lsize + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < lsize && lsize != 0)
	{
		while (s[j] == c)
			(j++);
		list[i] = ft_substr(s, j, ft_wordsize((s + j), c));
		if (list[i] == NULL)
			return (ft_clearlist(list, i));
		while (s[j] != c && s[j])
			(j++);
		(i++);
	}
	list[i] = NULL;
	return (list);
}
