/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:06 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:35:28 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Set 3b3 matrice acocrding to veca, vecb, vecc vectors
*/

t_m3b3	ft_m3b3set(t_vec veca, t_vec vecb, t_vec vecc)
{
	t_m3b3	mat;

	mat.m[0][0] = veca.x;
	mat.m[1][0] = veca.y;
	mat.m[2][0] = veca.z;
	mat.m[0][1] = vecb.x;
	mat.m[1][1] = vecb.y;
	mat.m[2][1] = vecb.z;
	mat.m[0][2] = vecc.x;
	mat.m[1][2] = vecc.y;
	mat.m[2][2] = vecc.z;
	return (mat);
}
