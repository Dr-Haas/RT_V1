/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_signed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:40:20 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/20 04:39:03 by rmarracc         ###   ########.fr       */
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

static int	ft_res_signed(t_arg *flag, int ret, ssize_t nb, char prefix)
{
	int			size;
	int			p_zero;
	int			p_space;

	size = signed_size(nb, "0123456789", 0);
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
	ret = ft_itoa_base(nb, "0123456789", ret);
	if (p_space > 0 && flag->minus > 0)
		ret = ret + ft_padding_signedp(p_space, ' ', flag);
	return (ret);
}

int			ft_parse_signed(va_list ap, t_arg *flag, int ret)
{
	ssize_t		nb;
	char		prefix;
	int			size;

	nb = ft_signed_lenght(va_arg(ap, ssize_t), *flag);
	size = signed_size(nb, "0123456789", 0);
	if (nb == 0 && (flag->precision == 0 || flag->precision == -5)
			&& flag->espace <= 0)
	{
		flag->zero = 0;
		return (ft_padding_signedp(flag->width, ' ', flag));
	}
	ft_nb_check(nb, flag);
	if (nb < 0)
		prefix = '-';
	else if (flag->plus == 1)
		prefix = '+';
	else if (flag->espace == 1)
		prefix = ' ';
	else
		prefix = '\0';
	return (ft_res_signed(flag, ret, nb, prefix));
}
