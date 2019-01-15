/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:53:59 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 17:59:50 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_stmin(size_t a, size_t b)
{
	return ((a > b) ? b : a);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_stmin(ft_strlen(dest), size);
	while (src[i] && (i + j + 1) < size)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (i + j < size)
		dest[i + j] = '\0';
	return (j + ft_strlen(src));
}
