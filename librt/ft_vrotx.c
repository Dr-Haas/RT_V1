/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:24 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:42:48 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector on x-axis according to r
*/

t_vec	ft_vrotx(t_vec vec, double r)
{
	t_vec	vecrot;

	vecrot.x = vec.x;
	vecrot.y = vec.y * cos(r) - vec.z * sin(r);
	vecrot.z = vec.z * cos(r) + vec.y * sin(r);
	return (vecrot);
}
