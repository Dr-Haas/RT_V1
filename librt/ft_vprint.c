/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:34:58 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:42:57 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"
#include "../libft/ft_printf/ft_printf.h"

/*
** Print vector
*/

/*
** 	ft_putchar('[');
** 	ft_putnbr(vec.x);
** 	ft_putstr(", ");
** 	ft_putnbr(vec.y);
** 	ft_putstr(", ");
** 	ft_putnbr(vec.z);
** 	ft_putstr("]\n");
*/

void	ft_vprint(t_vec vec)
{
	ft_printf("[%f, %f, %f]\n", vec.x, vec.y, vec.z);
	return ;
}
