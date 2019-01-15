/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:59:20 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 17:00:43 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	alloc_size(int i)
{
	while (i / 10 != 0)
		return (1 + alloc_size(i / 10));
	return (1);
}

static void		itoa_res(int n, char *str, int neg)
{
	unsigned int	i;
	static size_t	index;

	index = neg;
	if (n < 0)
		str[0] = '-';
	i = ((n < 0) ? -n : n);
	if (n / 10 != 0)
	{
		itoa_res(i / 10, str, neg);
		index++;
	}
	str[index] = (i % 10) + 48;
}

char			*ft_itoa(int n)
{
	int				i;
	char			*str;

	i = (n < 0) ? 1 : 0;
	str = ft_strnew((alloc_size(n) + i) * sizeof(char));
	if (!str)
		return (NULL);
	itoa_res(n, str, i);
	return (str);
}
