/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:05:38 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/23 12:01:35 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *chain;

	if (!(chain = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		chain->content = NULL;
		chain->content_size = 0;
	}
	else
	{
		if (!(chain->content = ft_memalloc(content_size)))
		{
			free(chain);
			return (NULL);
		}
		chain->content = ft_memcpy(chain->content, content, content_size);
		chain->content_size = content_size;
	}
	chain->next = NULL;
	return (chain);
}
