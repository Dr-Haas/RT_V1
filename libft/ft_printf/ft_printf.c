/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:28:46 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:48:38 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int			ft_is_arg1(char c)
{
	return (c == '-' || c == '+' || c == '#'
	|| c == '0' || c == ' ');
}

int			ft_is_arg2(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
	|| c == 'd' || c == 'i' || c == 'o' || c == '%'
	|| c == 'x' || c == 'X' || c == 'f' || c == 'u');
}

int			ft_skip_digit(const char *fmt, int i)
{
	while (ft_isdigit(fmt[i + 1]))
		i++;
	return (i);
}

static int	ft_parsing(const char *fmt, va_list ap,
				t_arg flag, int i)
{
	int			ret;

	ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && flag.arg == 0)
		{
			i = ft_process_arg(fmt, &flag, i + 1);
			flag.arg = 1;
		}
		else if (ft_is_arg2(fmt[i]) && flag.arg == 1)
		{
			ret = ret + ft_conversions(fmt[i], &flag, ap);
			flag.arg = 0;
		}
		else
		{
			ft_putchar(fmt[i]);
			ret++;
		}
		if (fmt[i])
			i++;
	}
	return (ret);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			ret;
	t_arg		flag;

	va_start(ap, fmt);
	ft_init_arg(&flag);
	ret = ft_parsing(fmt, ap, flag, 0);
	va_end(ap);
	return (ret);
}
