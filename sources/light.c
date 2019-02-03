/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:27:22 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/28 11:04:51 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			ft_vdist(t_vec a, t_vec b)
{
	return (sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)
		+ (b.z - a.z) * (b.z - a.z)));
}

double			ft_maxd(double a, double b)
{
	return ((a > b) ? a : b);
}

uint8_t			get_shadow(t_env *setup, t_ray incid, double dist, t_inter it)
{
	t_object	cur;
	t_list		*tmpo;
	t_inter		inter;
	t_inter		max;

	max = it;
	tmpo = setup->obj;
	while (tmpo)
	{
		cur = *(t_object*)tmpo->content;
		if (cur.type == 1)
			inter = ft_intersectsphere(incid, cur);
		else if (cur.type == 2)
			inter = ft_intersectcylinder(incid, cur);
		else if (cur.type == 3)
			inter = ft_intersectcone(incid, cur);
		else
			inter = ft_intersectplane(incid, cur);
		if ((int)inter.dist < (int)dist)
			return (0);
		tmpo = tmpo->next;
	}
	return (1);
}

double			get_light(t_env *setup, t_ray ref, t_inter it, t_object o)
{
	t_light		cur;
	t_list		*tmpl;
	t_ray		lray;
	t_disp		l;

	tmpl = setup->light;
	l.ret = 0;
	while (tmpl)
	{
		cur = *(t_light*)tmpl->content;
		lray.origin = pos_to_vec(cur);
		lray.dir = ft_vnorm(ft_vsub(it.p, lray.origin));
		l.d = ft_vdist(it.p, lray.origin);
		if (l.d > 0 && cur.pow > 0)
		{
			l.df = ((double)cur.pow / (l.d * l.d))
				* ft_maxd(0, ft_vdot(ft_vmul(it.norm, -1), lray.dir));
			o.specular = (bool_s(o)) ? o.specular + 1 : o.specular;
			l.sp = ((double)cur.pow / (l.d * l.d))
				* ft_maxd(0, -(pow(ft_vdot(ref.dir, lray.dir), o.specular)));
			l.ret += (l.sp + l.df) * get_shadow(setup, lray, l.d, it);
		}
		tmpl = tmpl->next;
	}
	return (l.ret);
}

uint32_t		get_color(t_env *setup, t_ray incid, t_inter it, t_object o)
{
	double		coef;
	t_ray		ref;

	if (o.type == 0 || it.dist == INF)
		return (0);
	ref.origin = it.p;
	ref.dir = ft_vnorm(ft_vsub(incid.dir, ft_vmul(it.norm, 2
				* ft_vdot(it.norm, incid.dir))));
	coef = get_light(setup, ref, it, o);
	(void)setup;
	(void)incid;
	return (color_mult(it.color, coef));
}
