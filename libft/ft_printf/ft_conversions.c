/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:24:59 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 17:13:22 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_conversions(char c, t_arg *flag, va_list ap)
{
	int		ret;

	ret = 0;
	ft_flag_priority(flag);
	if (c == 's')
		ret = ft_parse_string(ap, flag, 0, 0);
	else if (c == 'c')
		ret = ft_parse_char(ap, flag, 0, 0);
	else if (c == 'p')
		ret = ft_parse_pointer(ap, flag, 0, 0);
	else if (c == '%')
		ret = ft_parse_percent(flag, 0, 0, 0);
	else if (c == 'd' || c == 'i')
		ret = ft_parse_signed(ap, flag, 0);
	else if (c == 'u')
		ret = ft_parse_unsigned(ap, flag, 0);
	else if (c == 'o')
		ret = ft_parse_octal(ap, flag, 0);
	else if (c == 'x' || c == 'X')
		ret = ft_parse_hex(ap, flag, 0, c);
	else if (c == 'f')
		ret = ft_parse_double(ap, flag, 0);
	ft_init_arg(flag);
	return (ret);
}
