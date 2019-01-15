/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:37:35 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:37:54 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *ptr;

	if (ft_strlen(src) < n)
	{
		ft_memcpy(dest, src, sizeof(char) * (ft_strlen(src)) + 1);
		ptr = &dest[ft_strlen(src)];
		ft_bzero(ptr, n - ft_strlen(src));
	}
	else
		ft_memcpy(dest, src, sizeof(char) * n);
	return (dest);
}
