/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4b4trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:37 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:34:20 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Transpose matrices
*/

t_m4b4	ft_m4b4trans(t_m4b4 mat)
{
	t_m4b4	tmat;

	tmat.m[0][0] = mat.m[0][0];
	tmat.m[1][1] = mat.m[1][1];
	tmat.m[2][2] = mat.m[2][2];
	tmat.m[3][3] = mat.m[3][3];
	tmat.m[0][1] = mat.m[1][0];
	tmat.m[0][2] = mat.m[2][0];
	tmat.m[0][3] = mat.m[3][0];
	tmat.m[1][2] = mat.m[2][1];
	tmat.m[1][3] = mat.m[3][1];
	tmat.m[2][3] = mat.m[3][2];
	tmat.m[1][0] = mat.m[0][1];
	tmat.m[2][0] = mat.m[0][2];
	tmat.m[3][0] = mat.m[0][3];
	tmat.m[2][1] = mat.m[1][2];
	tmat.m[3][1] = mat.m[1][3];
	tmat.m[3][2] = mat.m[2][3];
	return (tmat);
}
