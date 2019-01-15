/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3setdiag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:09 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:35:22 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Set diagonal 3b3 matrices
*/

t_m3b3	ft_m3b3setdiag(t_vec vec)
{
	t_m3b3	mat;
	t_vec	vecx;
	t_vec	vecy;
	t_vec	vecz;

	vecx = ft_vset(vec.x, 0, 0);
	vecy = ft_vset(0, vec.y, 0);
	vecz = ft_vset(0, 0, vec.z);
	mat = ft_m3b3set(vecx, vecy, vecz);
	return (mat);
}
