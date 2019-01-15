/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:16:11 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 17:24:14 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_res_hex_norme(char c, int ret, size_t nb)
{
	if (c == 'x')
		ret = ft_uitoa_base(nb, "0123456789abcdef", ret);
	else
		ret = ft_uitoa_base(nb, "0123456789ABCDEF", ret);
	return (ret);
}

int			ft_ip(int p)
{
	return (p == -5 || p == 0);
}
