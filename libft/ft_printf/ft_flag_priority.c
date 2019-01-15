/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_priority.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:17:58 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 15:08:58 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_priority(t_arg *flag)
{
	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->plus == 1)
		flag->espace = 0;
}

ssize_t		ft_signed_lenght(ssize_t val, t_arg flag)
{
	if (flag.lenght == -2)
		val = (char)val;
	else if (flag.lenght == -1)
		val = (short int)val;
	else if (flag.lenght == 0)
		val = (int)val;
	else if (flag.lenght == 1)
		val = (long int)val;
	else if (flag.lenght == 2)
		val = (long long int)val;
	return (val);
}

size_t		ft_unsigned_lenght(size_t val, t_arg flag)
{
	if (flag.lenght == -2)
		val = (unsigned char)val;
	else if (flag.lenght == -1)
		val = (unsigned short int)val;
	else if (flag.lenght == 0)
		val = (unsigned int)val;
	else if (flag.lenght == 1)
		val = (unsigned long int)val;
	else if (flag.lenght == 2)
		val = (unsigned long long int)val;
	return (val);
}

long double	ft_double_lenght(long double val, t_arg flag)
{
	if (flag.lenght == 0)
		val = (float)val;
	else if (flag.lenght == 1)
		val = (double)val;
	else if (flag.lenght == 3)
		val = (long double)val;
	return (val);
}
