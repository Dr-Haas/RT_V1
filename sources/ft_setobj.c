/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:40 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:43:28 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** 	ft_putstr("\nrmat =\n");
** 	ft_m3b3print(rmat);
** 	ft_putstr("\ntmat =\n");
** 	ft_m3b3print(tmat);
** 	ft_putstr("\nlinear_otow =\n");
** 	ft_m3b3print(o->linear_otow);
** 	ft_putstr("\nlinear_wtoo =\n");
** 	ft_m3b3print(o->linear_wtoo);
** 	ft_putchar('\n');
*/

void	ft_initobject(t_obj *o)
{
	t_m3b3	rmat;
	t_m3b3	tmat;

	rmat = ft_m3b3rotx(o->rot.x);
	tmat = ft_m3b3roty(o->rot.y);
	rmat = ft_m3b3mul(tmat, rmat);
	tmat = ft_m3b3rotz(o->rot.z);
	rmat = ft_m3b3mul(tmat, rmat);
	if (!ft_strcmp(o->type, "plane") || !ft_strcmp(o->type, "disk"))
		tmat = ft_m3b3setdiag(ft_vset(1, 1, 1));
	else
		tmat = ft_m3b3setdiag(ft_vset(o->scale.x, o->scale.y, o->scale.z));
	o->linear_otow = ft_m3b3mul(tmat, rmat);
	o->linear_wtoo = ft_m3b3inv(o->linear_otow);
	o->otow = ft_m4b4set(o->linear_otow, ft_vset(0, 0, 0),
		ft_vset(o->origin.x, o->origin.y, o->origin.z), 1);
	o->wtoo = ft_m4b4inv(o->otow);
	o->ntow = ft_m3b3set(
		ft_vset(o->wtoo.m[0][0], o->wtoo.m[0][1], o->wtoo.m[0][2]),
		ft_vset(o->wtoo.m[1][0], o->wtoo.m[1][1], o->wtoo.m[1][2]),
		ft_vset(o->wtoo.m[2][0], o->wtoo.m[2][1], o->wtoo.m[2][2]));
	return ;
}

/*
** Set object direction according to line
**
** 	ao->d = ft_vrotxyz(ao->d, ao->rot);
*/

void	ft_setobjvar(char *line, t_obj *ao)
{
	if (!ft_strncmp(line, "type=", 5))
		ao->type = ft_strsub(line, 6, ft_strlen(line) - 8);
	else if (!ft_strncmp(line, "origin={", 8))
		ft_vfill(&ao->origin.x, &ao->origin.y, &ao->origin.z, line);
	else if (!ft_strncmp(line, "scale={", 7))
		ft_vfill(&ao->scale.x, &ao->scale.y, &ao->scale.z, line);
	else if (!ft_strncmp(line, "rotation={", 10))
	{
		ft_vfill(&ao->rot.x, &ao->rot.y, &ao->rot.z, line);
		ao->rot = ft_vmul(ao->rot, PI / 180);
	}
	else if (!ft_strncmp(line, "color={", 7))
		ft_vfill(&ao->rgb.x, &ao->rgb.y, &ao->rgb.z, line);
	return ;
}

/*
** Set object structure according to file copy
*/

int		ft_setobj(char **fc, t_obj *ao)
{
	int		i;

	i = 0;
	ao->scale = ft_vset(1, 1, 1);
	ft_vclr(&ao->origin);
	ft_vclr(&ao->rot);
	ft_vclr(&ao->dir);
	if (ft_strcmp(fc[++i], "{"))
		return (0);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "type=", 5)
			|| !ft_strncmp(fc[i], "origin={", 8)
			|| !ft_strncmp(fc[i], "scale={", 7)
			|| !ft_strncmp(fc[i], "rotation={", 10)
			|| !ft_strncmp(fc[i], "color={", 7))
			ft_setobjvar(fc[i], ao);
		else if (!ft_strcmp(fc[i], "}"))
		{
			ft_initobject(ao);
			return (1);
		}
	return (0);
}
