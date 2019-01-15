/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detmat3b3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:20:42 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:39:35 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Calcul 3b3 matrice determinant
*/

double	ft_detmat3b3(t_m3b3 mat)
{
	double	det;

	det = mat.m[0][0] * mat.m[1][1] * mat.m[2][2]
		+ mat.m[1][0] * mat.m[2][1] * mat.m[0][2]
			+ mat.m[2][0] * mat.m[0][1] * mat.m[1][2]
				- mat.m[2][0] * mat.m[1][1] * mat.m[0][2]
					- mat.m[1][0] * mat.m[0][1] * mat.m[2][2]
						- mat.m[0][0] * mat.m[2][1] * mat.m[1][2];
	return (det);
}
