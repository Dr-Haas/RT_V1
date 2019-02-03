/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:54:16 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/23 18:16:38 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*get_type(uint32_t type)
{
	if (type == 1)
		return ("sphere");
	else if (type == 2)
		return ("cylinder");
	else if (type == 3)
		return ("cone");
	else if (type == 4)
		return ("plane");
	else
		return ("error");
}

static void	print_objects(t_env *setup)
{
	t_list		*cpy;
	t_object	*tmp;

	cpy = setup->obj;
	while (cpy)
	{
		tmp = (t_object*)(cpy->content);
		ft_printf("\nobject\n{\n\ttype:%s\n\tposition:[%hd, %hd, %hd]\n\tnorma"
			, get_type(tmp->type), tmp->pos[0], tmp->pos[1], tmp->pos[2]);
		ft_printf("l:[%hd, %hd, %hd]\n\tcolor:%#010x\n\tradius",
			tmp->norm[0], tmp->norm[1], tmp->norm[2], tmp->rgb);
		ft_printf(":%hhu\n\tspecular:%hhu\n}\n", tmp->radius, tmp->specular);
		cpy = cpy->next;
	}
}

void		print_data(t_env *setup)
{
	t_list		*cpy;
	t_light		*tmp;

	ft_printf("camera\n{\n\tposition:[%hd, %hd, %hd]\n\tvector:[%hd, %hd, %hd]"
		, setup->cam.pos[0], setup->cam.pos[1], setup->cam.pos[2],
			setup->cam.dir[0], setup->cam.dir[1], setup->cam.dir[2]);
	ft_printf("\n}\n");
	cpy = setup->light;
	while (cpy)
	{
		tmp = (t_light*)(cpy->content);
		ft_printf("\nlight\n{\n\tpower:%u\n\tposition:[%hd, %hd, %hd]\n\tnorma"
			, tmp->pow, tmp->pos[0], tmp->pos[1], tmp->pos[2]);
		ft_printf("l:[%hd, %hd, %hd]\n\tcolor:%#010x\n}\n",
			tmp->dir[0], tmp->dir[1], tmp->dir[2], tmp->rgb);
		cpy = cpy->next;
	}
	print_objects(setup);
}
