/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:37:48 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/23 13:26:45 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		parse_object(t_env *setup, uint8_t *ubuf)
{
	t_list		*elem;
	t_object	data;

	data.type = ubuf[1];
	if (data.type > 4 || data.type < 1)
		return ;
	data.pos[0] = ubuf[6] + 256 * ubuf[7];
	data.pos[1] = ubuf[8] + 256 * ubuf[9];
	data.pos[2] = ubuf[10] + 256 * ubuf[11];
	data.norm[0] = ubuf[12] + 256 * ubuf[13];
	data.norm[1] = ubuf[14] + 256 * ubuf[15];
	data.norm[2] = ubuf[16] + 256 * ubuf[17];
	if (data.norm[0] == 0 && data.norm[1] == 0 && data.norm[2] == 0)
		data.norm[0] = 1;
	data.rgb = ubuf[18] + 256 * ubuf[19] + 65536 * ubuf[20]
		+ 16777216 * ubuf[21];
	data.radius = ubuf[22];
	data.specular = ubuf[23];
	if (!(elem = ft_lstnew(&data, sizeof(data))))
		return ;
	if (setup->obj)
		ft_lstadd(&(setup->obj), elem);
	else
		setup->obj = elem;
}

static void		parse_light(t_env *setup, uint8_t *ubuf)
{
	t_list		*elem;
	t_light		data;

	data.pow = ubuf[2] + 256 * ubuf[3] + 65536 * ubuf[4] + 16777216 * ubuf[5];
	data.pos[0] = ubuf[6] + 256 * ubuf[7];
	data.pos[1] = ubuf[8] + 256 * ubuf[9];
	data.pos[2] = ubuf[10] + 256 * ubuf[11];
	data.dir[0] = ubuf[12] + 256 * ubuf[13];
	data.dir[1] = ubuf[14] + 256 * ubuf[15];
	data.dir[2] = ubuf[16] + 256 * ubuf[17];
	if (data.dir[0] == 0 && data.dir[1] == 0 && data.dir[2] == 0)
		data.dir[0] = 1;
	data.rgb = ubuf[18] + 256 * ubuf[19] + 65536 * ubuf[20]
		+ 16777216 * ubuf[21];
	if (!(elem = ft_lstnew(&data, sizeof(data))))
		return ;
	if (setup->light)
		ft_lstadd(&(setup->light), elem);
	else
		setup->light = elem;
}

static void		parse_chunk(t_env *setup, uint8_t *ubuf)
{
	if (ubuf[0] > 3)
		return ;
	else if (ubuf[0] == 3)
		parse_object(setup, ubuf);
	else if (ubuf[0] == 2)
		parse_light(setup, ubuf);
	else
	{
		setup->cam.pos[0] = ubuf[2] + 256 * ubuf[3];
		setup->cam.pos[1] = ubuf[4] + 256 * ubuf[5];
		setup->cam.pos[2] = ubuf[6] + 256 * ubuf[7];
		setup->cam.dir[0] = ubuf[8] + 256 * ubuf[9];
		setup->cam.dir[1] = ubuf[10] + 256 * ubuf[11];
		setup->cam.dir[2] = ubuf[12] + 256 * ubuf[13];
		if (!setup->cam.dir[0] && !setup->cam.dir[1] && !setup->cam.dir[2])
			setup->cam.dir[0] = 1;
	}
}

static void		check_empty(t_env *setup)
{
	if (setup->light == NULL || setup->obj == NULL)
	{
		if (setup->light == NULL)
			ft_putstr("error : no light\n");
		if (setup->obj == NULL)
			ft_putstr("error : no object\n");
		if (setup->light)
			ft_lstdel(&(setup->light), &delelem);
		if (setup->obj)
			ft_lstdel(&(setup->obj), &delelem);
		exit(1);
	}
}

void			parse_bin(t_env *setup, int fd)
{
	int			ret;
	uint8_t		ubuf[64];

	while ((ret = read(fd, ubuf, 64)) > 0)
	{
		if (ret < 64)
		{
			ft_putstr("error : broken line\n");
			break ;
		}
		else if (ubuf[0] == 0 || ubuf[63] != 0)
		{
			ft_putstr("error : byte 63 isn't NULL or byte 0 is NULL\n");
			break ;
		}
		else
			parse_chunk(setup, &(ubuf[0]));
	}
	close(fd);
	check_empty(setup);
}
