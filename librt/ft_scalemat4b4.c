/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scalemat4b4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:45 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:32:03 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
**	Scale 4b4 matrice
*/

t_m4b4	ft_scalemat4b4(t_m4b4 mat, double s)
{
	t_m4b4	tmat;

	tmat.m[0][0] = s * mat.m[0][0];
	tmat.m[0][1] = s * mat.m[0][1];
	tmat.m[0][2] = s * mat.m[0][2];
	tmat.m[0][3] = s * mat.m[0][3];
	tmat.m[1][0] = s * mat.m[1][0];
	tmat.m[1][1] = s * mat.m[1][1];
	tmat.m[1][2] = s * mat.m[1][2];
	tmat.m[1][3] = s * mat.m[1][3];
	tmat.m[2][0] = s * mat.m[2][0];
	tmat.m[2][1] = s * mat.m[2][1];
	tmat.m[2][2] = s * mat.m[2][2];
	tmat.m[2][3] = s * mat.m[2][3];
	tmat.m[3][0] = s * mat.m[3][0];
	tmat.m[3][1] = s * mat.m[3][1];
	tmat.m[3][2] = s * mat.m[3][2];
	tmat.m[3][3] = s * mat.m[3][3];
	return (tmat);
}
