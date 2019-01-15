/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vtom4b4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:58 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:41:44 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Pass vector though 4b4 matrice
*/

t_vec	ft_vtom4b4(t_vec vec, t_m4b4 mat)
{
	t_vec	tvec;

	tvec.x = vec.x * mat.m[0][0] + vec.y * mat.m[0][1]
	+ vec.z * mat.m[0][2] + mat.m[0][3];
	tvec.y = vec.x * mat.m[1][0] + vec.y * mat.m[1][1]
	+ vec.z * mat.m[1][2] + mat.m[1][3];
	tvec.z = vec.x * mat.m[2][0] + vec.y * mat.m[2][1]
	+ vec.z * mat.m[2][2] + mat.m[2][3];
	return (tvec);
}
