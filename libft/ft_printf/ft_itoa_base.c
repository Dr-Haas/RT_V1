/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:26:58 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:49:24 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"
#include <limits.h>

int			unsigned_size(size_t nb, char *base, int acc)
{
	size_t		index;
	size_t		len;

	acc++;
	len = ft_strlen(base);
	index = nb % len;
	nb = nb / len;
	if (nb > 0)
		acc = unsigned_size(nb, base, acc);
	return (acc);
}

int			ft_uitoa_base(size_t nb, char *base, int acc)
{
	size_t		index;
	size_t		len;

	acc++;
	len = ft_strlen(base);
	index = nb % len;
	nb = nb / len;
	if (nb > 0)
		acc = ft_uitoa_base(nb, base, acc);
	ft_putchar(base[index]);
	return (acc);
}

int			signed_size(ssize_t nb, char *base, int acc)
{
	ssize_t		index;
	ssize_t		len;

	if (nb < 0)
		nb = -nb;
	acc++;
	len = (ssize_t)ft_strlen(base);
	index = nb % len;
	nb = nb / len;
	if (nb > 0)
		acc = signed_size(nb, base, acc);
	return (acc);
}

int			ft_itoa_base(ssize_t nb, char *base, int acc)
{
	ssize_t		index;
	ssize_t		len;

	if (nb == LONG_MIN)
	{
		ft_putstr("9223372036854775808");
		return (20);
	}
	if (nb < 0)
		nb = -nb;
	acc++;
	len = (ssize_t)ft_strlen(base);
	index = nb % len;
	nb = nb / len;
	if (nb > 0)
		acc = ft_itoa_base(nb, base, acc);
	ft_putchar(base[index]);
	return (acc);
}

int			ft_ftoa_base(long double nb, char *base, int acc, int p)
{
	acc = ft_itoa_base((ssize_t)nb, base, acc);
	nb = nb - (ssize_t)nb;
	if (p > 0)
	{
		ft_putchar('.');
		acc++;
	}
	while (p > 0)
	{
		nb = 10 * nb;
		acc = ft_itoa_base((ssize_t)nb, base, acc);
		nb = nb - (ssize_t)nb;
		p--;
	}
	return (acc);
}
