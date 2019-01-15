/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:32:31 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:36:42 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Multiply two 3b3 matrices
*/

t_m3b3	ft_m3b3mul(t_m3b3 mata, t_m3b3 matb)
{
	t_m3b3	tmat;
	t_vec	vecx;
	t_vec	vecy;
	t_vec	vecz;

	vecx = ft_vset(matb.m[0][0], matb.m[1][0], matb.m[2][0]);
	vecy = ft_vset(matb.m[0][1], matb.m[1][1], matb.m[2][1]);
	vecz = ft_vset(matb.m[0][2], matb.m[1][2], matb.m[2][2]);
	tmat = ft_m3b3set(ft_vtom3b3(vecx, mata), ft_vtom3b3(vecy, mata),
			ft_vtom3b3(vecz, mata));
	return (tmat);
}
