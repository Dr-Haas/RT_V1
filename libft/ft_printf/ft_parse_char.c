/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:02:12 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:50:21 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int			ft_parse_char(va_list ap, t_arg *flag, int ret, int pad)
{
	char	c;
	int		gap;

	c = (char)va_arg(ap, int);
	if (flag->width >= 1)
	{
		gap = flag->width - 1;
		if (flag->minus == 1)
			ft_putchar(c);
		while (pad < gap)
		{
			ft_putchar(' ');
			ret++;
			pad++;
		}
	}
	if (flag->minus == 0 || flag->width <= 0)
		ft_putchar(c);
	ret++;
	return (ret);
}
