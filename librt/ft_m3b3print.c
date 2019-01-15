/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:32:36 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:36:19 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"
#include "../libft/ft_printf/ft_printf.h"

/*
** Print 3b3 matrice
*/

/*
** 	ft_putchar('[');
** 	ft_putnbr(mat.m[0][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[0][2]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[1][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[1][2]);
** 	ft_putstr("]\n[");
** 	ft_putnbr(mat.m[2][0]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][1]);
** 	ft_putstr(", ");
** 	ft_putnbr(mat.m[2][2]);
** 	ft_putstr("]\n");
*/

void	ft_m3b3print(t_m3b3 mat)
{
	ft_printf("[%f, %f, %f]\n", mat.m[0][0], mat.m[0][1], mat.m[0][2]);
	ft_printf("[%f, %f, %f]\n", mat.m[1][0], mat.m[1][1], mat.m[1][2]);
	ft_printf("[%f, %f, %f]\n", mat.m[2][0], mat.m[2][1], mat.m[2][2]);
	return ;
}
