/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlena <jcarlena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 04:25:11 by jcarlena          #+#    #+#             */
/*   Updated: 2021/03/13 04:25:43 by jcarlena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))) != NULL)
	{
		new->next = NULL;
		new->content = content;
	}
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstn(t_list *lst, int n)
{
	if (lst)
	{
		while (--n > 0 && lst != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst && *lst && new)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_dellist(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		free(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
}
