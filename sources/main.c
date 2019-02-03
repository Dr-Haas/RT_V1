/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 09:35:42 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/23 17:53:02 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_error(int8_t msg)
{
	if (msg == 0)
		ft_putstr("error : open() failure\n");
	else if (msg == 1)
		ft_putstr("error : file is a folder\n");
	return (-1);
}

static int	ft_usage(int8_t msg)
{
	if (msg == 0)
		ft_putstr("usage : ./rtv1 [scene]\n");
	return (0);
}

static int	ft_open(char *file)
{
	int		ret;
	char	sbuf[1];

	if ((ret = open(file, O_RDONLY)) < 0)
		return (ft_error(0));
	if (read(ret, sbuf, 0) < 0)
	{
		close(ret);
		return (ft_error(1));
	}
	return (ret);
}

static void	init_env(t_env *setup)
{
	setup->light = NULL;
	setup->obj = NULL;
	setup->cam.pos[0] = 0;
	setup->cam.pos[1] = 0;
	setup->cam.pos[2] = 0;
	setup->cam.dir[0] = 1;
	setup->cam.dir[1] = 0;
	setup->cam.dir[2] = 0;
}

int			main(int argc, char **argv)
{
	int		fd;
	t_env	setup;

	if (argc != 2)
		return (ft_usage(0));
	if ((fd = ft_open(argv[1])) < 0)
		return (1);
	init_env(&setup);
	parse_bin(&setup, fd);
	print_data(&setup);
	rt_mlx_init(&setup);
	rt_mlx_loop(&setup);
	return (0);
}
