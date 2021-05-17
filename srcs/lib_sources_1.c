/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_sources_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:00 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 04:25:43 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(const char *str)
{
	int			neg;
	long int	sum;

	neg = 1;
	sum = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		(str++);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		(str++);
	}
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		if (sum >= 2147483648 && neg == 1)
			return (-1);
		if (sum <= -2147483648 && neg == -1)
			return (0);
		(str++);
	}
	return (sum * neg);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*k;

	if ((p = ft_calloc(len + 1, sizeof(char))) == NULL || !s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (p);
	k = p;
	while (len-- && s[start])
	{
		*p = s[start];
		(start++);
		(p++);
	}
	return (k);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str != NULL)
		write(fd, str, ft_strlen(str));
}

void	ft_putnbr_fd(int nbr, int fd)
{
	long int	nb;
	char		c;

	nb = (long int)nbr;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	c = (nb % 10 + 48);
	write(fd, &c, 1);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
