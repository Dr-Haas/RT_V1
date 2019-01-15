/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setmat3b3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:51 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:30:20 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Set 3b3 matrice acocrding to va, vb, vc vectors
*/

t_m3b3	ft_setmat3b3(t_vec va, t_vec vb, t_vec vc)
{
	t_m3b3	mat;

	mat.m[0][0] = va.x;
	mat.m[1][0] = va.y;
	mat.m[2][0] = va.z;
	mat.m[0][1] = vb.x;
	mat.m[1][1] = vb.y;
	mat.m[2][1] = vb.z;
	mat.m[0][2] = vc.x;
	mat.m[1][2] = vc.y;
	mat.m[2][2] = vc.z;
	return (mat);
}
