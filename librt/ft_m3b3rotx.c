/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m3b3rotx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:32:52 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:36:04 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate 3b3 matrice on x axis
*/

t_m3b3	ft_m3b3rotx(double theta)
{
	double	cost;
	double	sint;
	t_m3b3	mat;

	mat = ft_m3b3set(ft_vset(0, 0, 0), ft_vset(0, 0, 0), ft_vset(0, 0, 0));
	cost = cosf(theta);
	sint = sinf(theta);
	mat = ft_m3b3set(ft_vset(1, 0, 0), ft_vset(0, cost, sint),
		ft_vset(0, -sint, cost));
	return (mat);
}
