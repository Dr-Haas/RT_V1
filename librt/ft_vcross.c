/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:34:25 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:17:19 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Cross product two 3b3 vectors
*/

t_vec	ft_vcross(t_vec veca, t_vec vecb)
{
	t_vec	tvec;

	tvec.x = veca.y * vecb.z - veca.z * vecb.y;
	tvec.y = veca.z * vecb.x - veca.x * vecb.z;
	tvec.z = veca.x * vecb.y - veca.y * vecb.x;
	return (tvec);
}
