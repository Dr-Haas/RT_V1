/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:16 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/28 11:58:18 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Normalize a 3b3 vectors
*/

t_vec	ft_vnorm(t_vec vec)
{
	double	n;
	double	root;

	if ((root = sqrt(ft_vsqrd(vec))) == 0)
		n = 0;
	else
		n = 1.0 / sqrt(ft_vsqrd(vec));
	vec.x *= n;
	vec.y *= n;
	vec.z *= n;
	return (vec);
}
