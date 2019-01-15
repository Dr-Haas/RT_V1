/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotxyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:37:28 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:42:43 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Rotate a 3b3 vector according to r.x, r.y and r.z
*/

t_vec	ft_vrotxyz(t_vec vec, t_vec r)
{
	vec = ft_vrotx(vec, r.x);
	vec = ft_vroty(vec, r.y);
	vec = ft_vrotz(vec, r.z);
	return (vec);
}
