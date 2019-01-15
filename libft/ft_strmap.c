/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:34:13 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:34:31 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ptr;
	char *begin;

	if (!s)
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	begin = ptr;
	while (*ptr && f)
	{
		*ptr = f(*ptr);
		ptr++;
	}
	return (begin);
}
