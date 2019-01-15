/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:46 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:42:07 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Substract two 3b3 vectors
*/

t_vec	ft_vsub(t_vec veca, t_vec vecb)
{
	veca.x -= vecb.x;
	veca.y -= vecb.y;
	veca.z -= vecb.z;
	return (veca);
}
