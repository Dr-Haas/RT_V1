/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:11:37 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/26 16:34:44 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vec	ft_vsum3(t_vec a, t_vec b, t_vec c)
{
	t_vec		new;

	new = (t_vec){a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z};
	return (new);
}

static t_vec	ft_vscale(t_vec vect, double nb)
{
	t_vec	new;

	new = (t_vec){vect.x * nb, vect.y * nb, vect.z * nb};
	return (new);
}

static t_vec	get_ray(t_env *setup, int x, int y, double half)
{
	t_vec		origin;
	t_vec		tmp1;
	t_vec		tmp2;
	t_vec		rx;
	t_vec		ry;

	origin.x = setup->cam.dir[0];
	origin.y = setup->cam.dir[1];
	origin.z = setup->cam.dir[2];
	origin = ft_vnorm(origin);
	tmp1 = ft_vcross(origin, (t_vec){0, 1, 0});
	tmp1 = ft_vnorm(tmp1);
	tmp2 = ft_vcross(tmp1, origin);
	tmp2 = ft_vnorm(tmp2);
	rx = ft_vscale(tmp1, (x * (half / (1200 - 1) * 2)) - half);
	ry = ft_vscale(tmp2, (y * (half / (1200 - 1) * 2)) - half);
	return (ft_vnorm(ft_vsum3(origin, rx, ry)));
}

void			raytrace(t_env *setup, int i, int j)
{
	t_ray		incid;
	double		tanfov;

	tanfov = tan(acos(-1) * (FOV / 2) / 180);
	while (j < YSIZE)
	{
		i = 0;
		while (i < XSIZE)
		{
			incid.dir = get_ray(setup, i, j, tanfov);
			incid.origin.x = (double)setup->cam.pos[0];
			incid.origin.y = (double)setup->cam.pos[1];
			incid.origin.z = (double)setup->cam.pos[2];
			setup->addr[j * XSIZE + i] = ft_intersect(setup, incid);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(setup, setup->win, setup->img, 0, 0);
}
