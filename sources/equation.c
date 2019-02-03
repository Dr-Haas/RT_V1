/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:29:52 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/26 19:04:15 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_inter	ft_equation(t_calc equ, t_object cur, t_ray incid)
{
	t_inter		inter;

	equ.delta = (equ.d2 * equ.d2) - (4 * equ.d1 * equ.d3);
	if (equ.delta < 0 || equ.d1 == 0)
		return ((t_inter){INF, 0, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}});
	else if (equ.delta == 0)
		equ.res = (-1 * equ.d2) / (2 * equ.d1);
	else
	{
		equ.r1 = ((-1 * equ.d2) + sqrt(equ.delta)) / (2 * equ.d1);
		equ.r2 = ((-1 * equ.d2) - sqrt(equ.delta)) / (2 * equ.d1);
		equ.res = ((equ.r1 < equ.r2) ? equ.r1 : equ.r2);
	}
	inter.dist = (equ.res > 0) ? equ.res : INF;
	inter.color = (equ.res > 0) ? cur.rgb : 0;
	if (inter.dist < INF)
		inter.p = ft_vsum(incid.origin, ft_vmul(incid.dir, inter.dist));
	else
		inter.p = (t_vec){0, 0, 0};
	return (inter);
}
