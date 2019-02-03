/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:40:20 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/20 04:39:22 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static int	ft_padding_signedp(int nb, char c, t_arg *flag)
{
	int			i;

	i = 0;
	while (i < nb)
	{
		if (flag->zero <= 0)
			ft_putchar(c);
		else
			ft_putchar('0');
		i++;
	}
	return (i);
}

static void	ft_nb_check(ssize_t nb, t_arg *flag)
{
	if (nb < 0)
	{
		flag->plus = 0;
		flag->espace = 0;
	}
	if (flag->precision != -1)
		flag->zero = 0;
	if (flag->precision < 0)
		flag->precision = 0;
}

static int	ft_prefix_check(char *prefix, int ret)
{
	if (*prefix != '\0')
	{
		ft_putchar(*prefix);
		*prefix = '\0';
		ret++;
	}
	return (ret);
}

static int	ft_res_unsigned(t_arg *flag, int ret, size_t nb, char prefix)
{
	int			size;
	int			p_zero;
	int			p_space;

	size = unsigned_size(nb, "0123456789", 0);
	p_zero = flag->precision - size;
	if (flag->width > flag->precision)
		p_space = flag->width - ft_max(flag->precision, size)
			- (prefix != '\0');
	else
		p_space = 0;
	if (p_space > 0 && flag->minus <= 0)
	{
		if (flag->zero > 0)
			ret = ft_prefix_check(&prefix, ret);
		ret = ret + ft_padding_signedp(p_space, ' ', flag);
	}
	if (p_zero > 0)
		ret = ft_prefix_check(&prefix, ret) +
			ft_padding_signedp(p_zero, '0', flag);
	ret = ft_prefix_check(&prefix, ret);
	ret = ft_uitoa_base(nb, "0123456789", ret);
	if (p_space > 0 && flag->minus > 0)
		ret = ret + ft_padding_signedp(p_space, ' ', flag);
	return (ret);
}

int			ft_parse_unsigned(va_list ap, t_arg *flag, int ret)
{
	size_t		nb;
	char		prefix;
	int			size;

	nb = ft_unsigned_lenght(va_arg(ap, size_t), *flag);
	size = unsigned_size(nb, "0123456789", 0);
	if (nb == 0 && (flag->precision == 0 || flag->precision == -5)
			&& flag->espace <= 0)
	{
		flag->zero = 0;
		return (ft_padding_signedp(flag->width, ' ', flag));
	}
	ft_nb_check(nb, flag);
	prefix = '\0';
	return (ft_res_unsigned(flag, ret, nb, prefix));
}
