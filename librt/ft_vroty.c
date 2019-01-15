/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vroty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:32 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:42:36 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector on y-axis according to r
*/

t_vec	ft_vroty(t_vec vec, double r)
{
	t_vec	vecrot;

	vecrot.x = vec.x * cos(r) + vec.z * sin(r);
	vecrot.y = vec.y;
	vecrot.z = vec.z * cos(r) - vec.x * sin(r);
	return (vecrot);
}
