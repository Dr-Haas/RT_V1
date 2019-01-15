/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpolartocartesian.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:35:01 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:43:06 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Convert a 3b3 polar vectors containing radius, longitude & latitude
** into a vector containing cartsian coordinates
*/

t_vec	ft_vpolartocartesian(t_vec vec)
{
	t_vec	vecpol;

	vecpol.x = vec.x * sin(vec.y) * cos(vec.z);
	vecpol.y = vec.x * cos(vec.y);
	vecpol.z = vec.x * sin(vec.y) * sin(vec.z);
	return (vecpol);
}
