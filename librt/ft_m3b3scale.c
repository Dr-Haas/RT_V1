/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:03 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:35:34 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Scale 3b3 matrice
*/

t_m3b3	ft_m3b3scale(t_m3b3 mat, double s)
{
	t_m3b3	tmat;

	tmat.m[0][0] = s * mat.m[0][0];
	tmat.m[0][1] = s * mat.m[0][1];
	tmat.m[0][2] = s * mat.m[0][2];
	tmat.m[1][0] = s * mat.m[1][0];
	tmat.m[1][1] = s * mat.m[1][1];
	tmat.m[1][2] = s * mat.m[1][2];
	tmat.m[2][0] = s * mat.m[2][0];
	tmat.m[2][1] = s * mat.m[2][1];
	tmat.m[2][2] = s * mat.m[2][2];
	return (tmat);
}
