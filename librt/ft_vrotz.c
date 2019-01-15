/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:36 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:42:30 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector on z-axis according to r
*/

t_vec	ft_vrotz(t_vec vec, double r)
{
	t_vec	vecrot;

	vecrot.x = vec.x * cos(r) - vec.y * sin(r);
	vecrot.y = vec.y * cos(r) + vec.x * sin(r);
	vecrot.z = vec.z;
	return (vecrot);
}
