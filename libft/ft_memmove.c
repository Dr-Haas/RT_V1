/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:11:24 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 17:11:46 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = -1;
	s = (char*)src;
	d = (char*)dest;
	if (s < d)
		while ((int)--n >= 0)
			*(d + n) = *(s + n);
	else
		while (++i < n)
			*(d + i) = *(s + i);
	return (dest);
}
