/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:22 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 14:55:00 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Create a new list according to content
*/

t_list	*ft_lnew(void const *c, size_t cs)
{
	t_list *lst;

	if (!(lst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!c)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if (!(lst->content = ft_memalloc(cs)))
			return (NULL);
		ft_memcpy(lst->content, c, cs);
		lst->content_size = cs;
	}
	lst->next = NULL;
	return (lst);
}

/*
** Add a new node to the list according to content or create it
*/

void	ft_lfill(t_list **alst, void const *c, size_t cs)
{
	t_list	*lst;

	if (*alst == NULL)
		*alst = ft_lnew(c, cs);
	else
	{
		lst = ft_lnew(c, cs);
		lst->next = *alst;
		*alst = lst;
	}
	return ;
}
