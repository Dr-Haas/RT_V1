/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:29:36 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:50:43 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

static int		ft_free_n_ret(char **s, int ret)
{
	ret = ret + ft_strlen(*s);
	free(*s);
	return (ret);
}

int				ft_parse_string(va_list ap, t_arg *flag, int ret, int pad)
{
	char	*s[2];
	int		gap;

	s[0] = va_arg(ap, char *);
	if (!(s[1] = (s[0]) ? ft_strdup(s[0]) : ft_strdup("(null)")))
		return (0);
	flag->precision = (flag->precision == -5) ? 0 : flag->precision;
	if (flag->precision >= 0 && flag->precision < (int)ft_strlen(s[1]))
		s[1][flag->precision] = '\0';
	if (flag->width > 0)
		if (flag->width > (int)ft_strlen(s[1]))
		{
			gap = flag->width - (int)ft_strlen(s[1]);
			if (flag->minus == 1)
				ft_putstr(s[1]);
			while (pad < gap)
			{
				ft_putchar(' ');
				ret++;
				pad++;
			}
		}
	if (flag->minus == 0 || flag->width <= (int)ft_strlen(s[1]))
		ft_putstr(s[1]);
	return (ft_free_n_ret(&s[1], ret));
}
