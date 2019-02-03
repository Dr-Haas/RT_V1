/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:32:21 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/27 06:58:37 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_inter		ft_intersectcylinder(t_ray incid, t_object cur)
{
	t_calc		equ;
	t_vec		norm;
	t_inter		ret;

	equ.c = (t_vec){(double)cur.pos[0], (double)cur.pos[1], (double)cur.pos[2]};
	norm = ft_vnorm(ft_vset((double)cur.norm[0], (double)cur.norm[1],
			(double)cur.norm[2]));
	equ.tmp1 = ft_vsub(incid.origin, equ.c);
	equ.d1 = ft_vdot(incid.dir, incid.dir) - ft_vdot(incid.dir, norm)
		* ft_vdot(incid.dir, norm);
	equ.d2 = 2 * (ft_vdot(incid.dir, equ.tmp1) - ft_vdot(incid.dir, norm)
		* ft_vdot(equ.tmp1, norm));
	equ.d3 = ft_vdot(equ.tmp1, equ.tmp1) - ft_vdot(equ.tmp1, norm)
		* ft_vdot(equ.tmp1, norm) - (cur.radius * cur.radius);
	ret = ft_equation(equ, cur, incid);
	equ.m = ft_vdot(incid.dir, ft_vmul(norm, ret.dist))
		+ ft_vdot(equ.tmp1, norm);
	ret.norm = ft_vnorm(ft_vsub(ft_vsub(ret.p, equ.c), ft_vmul(norm, equ.m)));
	return (ret);
}

t_inter		ft_intersectcone(t_ray incid, t_object cur)
{
	t_calc		equ;
	t_vec		norm;
	t_inter		ret;
	double		tmp;

	tmp = (cur.radius < 180) ? (double)cur.radius : 179.;
	tmp = (tmp < -180.) ? -179. : tmp;
	tmp = tmp * acos(-1) / 180;
	tmp = tan(tmp / 2);
	equ.c = (t_vec){(double)cur.pos[0], (double)cur.pos[1], (double)cur.pos[2]};
	norm = ft_vnorm(ft_vset((double)cur.norm[0], (double)cur.norm[1],
			(double)cur.norm[2]));
	equ.tmp1 = ft_vsub(incid.origin, equ.c);
	equ.d1 = ft_vdot(incid.dir, incid.dir) - (1 + tmp * tmp)
		* ft_vdot(incid.dir, norm) * ft_vdot(incid.dir, norm);
	equ.d2 = 2 * (ft_vdot(incid.dir, equ.tmp1) - (1 + tmp * tmp)
		* ft_vdot(incid.dir, norm) * ft_vdot(equ.tmp1, norm));
	equ.d3 = ft_vdot(equ.tmp1, equ.tmp1) - (1 + tmp * tmp)
		* ft_vdot(equ.tmp1, norm) * ft_vdot(equ.tmp1, norm);
	ret = ft_equation(equ, cur, incid);
	equ.m = ft_vdot(incid.dir, ft_vmul(norm, ret.dist))
		+ ft_vdot(equ.tmp1, norm);
	ret.norm = ft_vnorm(ft_vsub(ft_vsub(ret.p, equ.c),
				ft_vmul(norm, (1 + tmp * tmp) * equ.m)));
	return (ret);
}

t_inter		ft_intersectplane(t_ray incid, t_object cur)
{
	t_inter		inter;
	t_calc		equ;
	t_vec		norm;

	norm = ft_vnorm(ft_vset((double)cur.norm[0], (double)cur.norm[1],
			(double)cur.norm[2]));
	equ.tmp1 = ft_vsub(incid.origin, (t_vec){(double)cur.pos[0],
		(double)cur.pos[1], (double)cur.pos[2]});
	inter.dist = (-1 * ft_vdot(equ.tmp1, norm))
		/ ft_vdot(incid.dir, norm);
	inter.dist = (inter.dist > 0) ? inter.dist : INF;
	inter.color = (inter.dist > 0) ? cur.rgb : 0;
	if (inter.dist < INF)
		inter.p = ft_vsum(incid.origin, ft_vmul(incid.dir, inter.dist));
	else
		inter.p = (t_vec){0, 0, 0};
	if (ft_vdot(incid.dir, norm) >= 0)
		inter.norm = ft_vnorm(ft_vmul(norm, -1));
	else
		inter.norm = norm;
	return (inter);
}

t_inter		ft_intersectsphere(t_ray incid, t_object cur)
{
	t_calc		equ;
	t_inter		ret;

	equ.c = (t_vec){(double)cur.pos[0], (double)cur.pos[1], (double)cur.pos[2]};
	equ.tmp1 = ft_vsub(incid.origin, equ.c);
	equ.d1 = ft_vdot(incid.dir, incid.dir);
	equ.d2 = 2 * ft_vdot(incid.dir, equ.tmp1);
	equ.d3 = ft_vdot(equ.tmp1, equ.tmp1) - (cur.radius * cur.radius);
	ret = ft_equation(equ, cur, incid);
	ret.norm = ft_vnorm(ft_vsub(ret.p, equ.c));
	return (ret);
}

uint32_t	ft_intersect(t_env *setup, t_ray incid)
{
	t_object	cur;
	t_object	ret;
	t_list		*tmpo;
	t_inter		inter;
	t_inter		max;

	max = (t_inter){INF, 0, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}};
	tmpo = setup->obj;
	ret.type = 0;
	while (tmpo)
	{
		cur = *(t_object*)tmpo->content;
		inter = intersect_type(cur, incid, inter);
		if (inter.dist < max.dist)
		{
			ret = cur;
			max = inter;
		}
		tmpo = tmpo->next;
	}
	return (get_color(setup, incid, max, ret));
}
