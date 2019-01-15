/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:36:26 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:37:13 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_stmin(size_t a, size_t b)
{
	return ((a > b) ? b : a);
}

int				ft_strncmp(const void *s1, const void *s2, size_t n)
{
	return (ft_memcmp((unsigned char*)s1, (unsigned char*)s2,
		sizeof(char) * ft_stmin(n, (ft_stmin(ft_strlen(s1),
				ft_strlen(s2))) + 1)));
}
