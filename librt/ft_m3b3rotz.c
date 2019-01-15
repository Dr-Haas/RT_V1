/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3rotz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:32:59 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:35:41 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate 3b3 matrice on z axis
*/

t_m3b3	ft_m3b3rotz(double theta)
{
	double	cost;
	double	sint;
	t_m3b3	mat;

	mat = ft_m3b3set(ft_vset(0, 0, 0), ft_vset(0, 0, 0), ft_vset(0, 0, 0));
	cost = cosf(theta);
	sint = sinf(theta);
	mat = ft_m3b3set(ft_vset(cost, sint, 0), ft_vset(-sint, cost, 0),
		ft_vset(0, 0, 1));
	return (mat);
}
