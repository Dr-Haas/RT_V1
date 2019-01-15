/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vclr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:34:03 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:17:33 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Reset each dimensions of a 3b3 vector
*/

void	ft_vclr(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	return ;
}