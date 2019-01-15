/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:34:34 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:17:05 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Dot product two 3b3 vectors
*/

double	ft_vdot(t_vec veca, t_vec vecb)
{
	veca.x *= vecb.x;
	veca.y *= vecb.y;
	veca.z *= vecb.z;
	return (veca.x + veca.y + veca.z);
}
