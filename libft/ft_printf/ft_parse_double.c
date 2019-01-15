/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:15:17 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:51:08 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static int	ft_padding_signedf(int nb, char c, t_arg *flag)
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

static int	ft_prefixd_check(char *prefix, int ret)
{
	if (*prefix != '\0')
	{
		ft_putchar(*prefix);
		*prefix = '\0';
		ret++;
	}
	return (ret);
}

static int	ft_res_double(t_arg *flag, int ret,
				long double nb, char prefix)
{
	int			size;
	int			p_space;

	size = signed_size((ssize_t)nb, "0123456789", 0) + flag->precision;
	p_space = flag->width - size - (flag->precision != 0) - (prefix != '\0');
	if (p_space > 0 && flag->minus <= 0)
	{
		if (flag->zero > 0)
			ret = ft_prefixd_check(&prefix, ret);
		ret = ret + ft_padding_signedf(p_space, ' ', flag);
	}
	ret = ft_prefixd_check(&prefix, ret);
	ret = ft_ftoa_base(nb, "0123456789", ret, flag->precision);
	if (p_space > 0 && flag->minus > 0)
		ret = ret + ft_padding_signedf(p_space, ' ', flag);
	return (ret);
}

static void	ft_fl_check(long double nb, t_arg *flag)
{
	if (nb < 0)
	{
		flag->plus = 0;
		flag->espace = 0;
	}
}

int			ft_parse_double(va_list ap, t_arg *flag, int ret)
{
	long double		nb;
	char			prefix;

	if (flag->precision == -5)
		flag->precision = 0;
	if (flag->precision < 0)
		flag->precision = 6;
	if (flag->lenght < 2)
		nb = ft_double_lenght(va_arg(ap, double), *flag);
	else
		nb = ft_double_lenght(va_arg(ap, long double), *flag);
	ft_fl_check(nb, flag);
	if (nb < 0)
		prefix = '-';
	else if (flag->plus == 1)
		prefix = '+';
	else if (flag->espace == 1)
		prefix = ' ';
	else
		prefix = '\0';
	return (ft_res_double(flag, ret, nb, prefix));
}
