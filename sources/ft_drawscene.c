/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawscene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:38:51 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:39:26 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"
#include <stdio.h>

/*
** Put a pixel on the screen occording to light luminosity and object color
*/
/*
void	ft_putpixel(t_vec rgb, double l, int i, int j)
{
	t_env	*e;
	int		x;
	int		y;

	y = -1;
	e = ft_getenv();
	l >= 255 ? l = 255 : 0;
	l <= 0 ? l = 0 : 0;
	while (++y < e->precision)
	{
		x = -1;
		while (++x < e->precision)
			e->stp[((e->h - 1) - i - y) * e->w + j + x] =
			(int)((rgb.x / 255) * l) * 0x10000
			+ (int)((rgb.y / 255) * l) * 0x100
			+ (int)((rgb.z / 255) * l) * 0x1;
	}
	return ;
}*/

/*
** Camera initialisation
**
** printf("c->anchor = [%f, %f, %f];\n", c->anchor.x, c->anchor.y, c->anchor.z);
** printf("c->polar = [%f, %f, %f];\n", c->polar.x, c->polar.y, c->polar.z);
** printf("c->reltv = [%f, %f, %f];\n", c->reltv.x, c->reltv.y, c->reltv.z);
** printf("c->world = [%f, %f, %f];\n", c->world.x, c->world.y, c->world.z);
** printf("c->xaxis = [%f, %f, %f];\n", c->xaxis.x, c->xaxis.y, c->xaxis.z);
** printf("c->yaxis = [%f, %f, %f];\n", c->yaxis.x, c->yaxis.y, c->yaxis.z);
** printf("c->zaxis = [%f, %f, %f];\n", c->zaxis.x, c->zaxis.y, c->zaxis.z);
*/

void	ft_initcamera(t_camera *c)
{
	t_vec	taxis;

	c->polar = ft_vset(c->radius, c->lon * (PI / 180), c->lat * (PI / 180));
	c->reltv = ft_vpolartocartesian(c->polar);
	c->world = ft_vsum(c->reltv, c->anchor);
	c->zaxis = ft_vnorm(c->reltv);
	taxis = ft_vset(0, 1, 0);
	c->xaxis = ft_vnorm(ft_vcross(taxis, c->zaxis));
	c->yaxis = ft_vcross(c->xaxis, c->zaxis);
	c->ctow = ft_m4b4set(ft_m3b3set(c->xaxis, c->yaxis, c->zaxis),
	ft_vset(0, 0, 0), c->world, 1);
	c->wtoc = ft_m4b4inv(c->ctow);
	return ;
}

/*
** Cast all rays from world to object and illuminate scene
*/

t_vec		ft_raytrace(t_env *e, t_ray incident_ray)
{
	t_ray		incid_os;
	t_object	hit_obj;
	t_vec		result;
	int			i;
	
	result = (t_vec){0., 0., 0.};
	if (ft_intersect(e, incident_ray, &hit_obj, &incid_os))
	{
		i = 0;
		while(i < e->llight_len)
		{
			result = ft_vsum(result, 
							ft_get_color(hit_obj, incid_os, e->llight[i]));
			++i;
		}
	}
	return (result);
}

/*
** Light and shadow the 3D scene using raytracing
**
** 	ft_putmat4b4(e.c.ctow);
** 	ft_putmat4b4(e.c.wtoc);
**
** 	i < e->h && j < e->w ? ft_lightscene(r, e, i, j) : 0;
*/

void	ft_drawscene(void)
{
	int		i;
	int		j;
	t_ray	ray;
	t_env	*e;

	e = ft_getenv();

for (int i = 0; i < e->w * e->h; ++i) e->stp[i] = 0x880088;

	ft_initcamera(&e->cam);
	ray.origin = ft_vset(e->cam.world.x, e->cam.world.y, e->cam.world.z);
	i = -1;
	while (++i < e->h)
	{
		j = -1;
		while (++j < e->w)
		{
			ray.dir = ft_vset(j - e->w / 2, i - e->h / 2,
				-e->w / (2 * tan(e->cam.fov / 2)));
			ray.dir = ft_vnorm(ft_vtom4b4(ray.dir, e->cam.ctow));
			e->stp[i * e->w + j] = color_app_lum(ft_raytrace(e, ray));
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->pic, 0, 0);
}
