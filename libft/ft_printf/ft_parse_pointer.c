/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:13:33 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:50:54 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static int	alloc_size(size_t nb, char *base, int acc)
{
	size_t	index;
	size_t	len;

	acc++;
	len = ft_strlen(base);
	index = nb % len;
	nb = nb / len;
	if (nb > 0)
		acc = alloc_size(nb, base, acc);
	return (acc);
}

static int	ft_putst_base(size_t nb, char *base, int acc)
{
	size_t	index;
	size_t	len;

	acc++;
	len = ft_strlen(base);
	index = nb % len;
	nb = nb / len;
	if (nb > 0)
		acc = ft_putst_base(nb, base, acc);
	ft_putchar(base[index]);
	return (acc);
}

static int	ft_putaddr(void *addr)
{
	ft_putchar('0');
	ft_putchar('x');
	return (ft_putst_base((size_t)addr, "0123456789abcdef", 2));
}

int			ft_parse_pointer(va_list ap, t_arg *flag, int ret, int pad)
{
	void	*addr;
	int		size;
	int		gap;

	addr = va_arg(ap, void *);
	size = alloc_size((size_t)addr, "0123456789abcdef", 2);
	if (flag->width > size)
	{
		gap = flag->width - size;
		if (flag->minus == 1)
			ft_putaddr(addr);
		while (pad < gap)
		{
			ft_putchar(' ');
			ret++;
			pad++;
		}
	}
	if (flag->minus == 0 || flag->width <= size)
		ft_putaddr(addr);
	ret = ret + size;
	return (ret);
}
