/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:45:37 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 17:46:35 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_stmin(size_t a, size_t b)
{
	return ((a > b) ? b : a);
}

int				ft_strcmp(char const *s1, char const *s2)
{
	return (ft_memcmp((unsigned char*)s1, (unsigned char*)s2,
					sizeof(char) * (ft_stmin(ft_strlen(s1),
										ft_strlen(s2)) + 1)));
}
