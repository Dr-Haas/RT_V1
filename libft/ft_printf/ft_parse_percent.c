/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:51:23 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:51:47 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int			ft_parse_percent(t_arg *flag, int ret, int pad, int spaces)
{
	int		gap;

	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->precision >= 0 && flag->zero == 1)
		spaces = flag->width - flag->precision;
	if (flag->width > 1)
	{
		gap = flag->width - 1;
		if (flag->minus == 1)
			ft_putchar('%');
		while (pad < gap)
		{
			if (flag->zero == 0 || ret < spaces)
				ft_putchar(' ');
			else
				ft_putchar('0');
			ret++;
			pad++;
		}
	}
	if (flag->minus == 0 || flag->width <= 0)
		ft_putchar('%');
	return (ret + 1);
}
