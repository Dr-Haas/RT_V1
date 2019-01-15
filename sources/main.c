/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:44 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:36:49 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Reset scene to black
*/

void	ft_fillscene(void)
{
	int		i;
	int		j;
	t_env	*e;

	i = -1;
	e = ft_getenv();
	while (++i < e->h)
	{
		j = -1;
		while (++j < e->w)
			e->stp[i * e->w + j] = 0x0;
	}
	return ;
}

/*
** Change environment variables according to key pressed
*/

int		ft_hook(int key, t_env *e)
{
	(void)e;
	if (key == 53)
		exit(0);
	return (0);
}

int		ft_exit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

/*
** "Ray tracing is not slow - computers are"
** 	James Kajiya
*/

void	ft_render(void)
{
	t_env	*e;

	e = ft_getenv();
	ft_fillscene();
	ft_drawscene();
	mlx_hook(e->win, 2, 0, ft_hook, e);
	mlx_hook(e->win, 17, 0, ft_exit, e);
	mlx_loop(e->mlx);
	return ;
}

/*
** Check file, set environment and draw scene
*/

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./rtv1 scene_file\n");
		return (0);
	}
	else
	{
		if (!ft_setenv(argv[1]))
			exit(1);
		ft_putenv();
		ft_render();
	}
	return (0);
}
