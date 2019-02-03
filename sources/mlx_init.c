/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:13:41 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/24 15:47:22 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_error_malloc(t_env *setup)
{
	ft_putstr("error : malloc failed, like your existence\n");
	ft_lstdel(&(setup->light), &delelem);
	ft_lstdel(&(setup->obj), &delelem);
	exit(1);
}

void		rt_mlx_init(t_env *setup)
{
	int		g;

	if (!(setup->mlx = mlx_init()))
		ft_error_malloc(setup);
	if (!(setup->win = mlx_new_window(setup->mlx, XSIZE, YSIZE, "RTv1")))
		ft_error_malloc(setup);
	if (!(setup->img = mlx_new_image(setup->mlx, XSIZE, YSIZE)))
	{
		mlx_destroy_window(setup->mlx, setup->win);
		ft_error_malloc(setup);
	}
	setup->addr = (uint32_t*)mlx_get_data_addr(setup->img, &(g), &(g), &(g));
	raytrace(setup, 0, 0);
}

int			ft_quit_cross(t_env *setup)
{
	ft_lstdel(&(setup->light), &delelem);
	ft_lstdel(&(setup->obj), &delelem);
	mlx_destroy_image(setup->mlx, setup->img);
	mlx_destroy_window(setup->mlx, setup->win);
	exit(0);
	return (0);
}

int			ft_quit(int key, t_env *setup)
{
	if (key == 53)
	{
		ft_lstdel(&(setup->light), &delelem);
		ft_lstdel(&(setup->obj), &delelem);
		mlx_destroy_image(setup->mlx, setup->img);
		mlx_destroy_window(setup->mlx, setup->win);
		exit(0);
	}
	return (0);
}

void		rt_mlx_loop(t_env *setup)
{
	mlx_hook(setup->win, 17, 0, &ft_quit_cross, setup);
	mlx_hook(setup->win, 2, 0, &ft_quit, setup);
	mlx_loop(setup->mlx);
}
