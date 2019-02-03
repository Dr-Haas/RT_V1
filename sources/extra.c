/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 06:44:17 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/28 11:03:39 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_inter		intersect_type(t_object cur, t_ray incid, t_inter inter)
{
	if (cur.type == 1)
		inter = ft_intersectsphere(incid, cur);
	else if (cur.type == 2)
		inter = ft_intersectcylinder(incid, cur);
	else if (cur.type == 3)
		inter = ft_intersectcone(incid, cur);
	else
		inter = ft_intersectplane(incid, cur);
	return (inter);
}

t_vec		pos_to_vec(t_light cur)
{
	return ((t_vec){(double)cur.pos[0],
			(double)cur.pos[1], (double)cur.pos[2]});
}

uint8_t		bool_s(t_object o)
{
	return (o.specular % 2 == 0 && o.specular != 0);
}
