/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:34:50 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:35:15 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	char			*begin;
	unsigned int	i;

	if (!s)
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	begin = ptr;
	i = 0;
	while (*ptr && f)
	{
		*ptr = f(i, *ptr);
		ptr++;
		i++;
	}
	return (begin);
}
