/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:12 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 14:54:46 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Create or return environment structure
*/

t_env	*ft_getenv(void)
{
	static	t_env	*e = NULL;

	if (e == NULL)
	{
		if (!(e = ft_memalloc(sizeof(t_env))))
			return (NULL);
		ft_strcpy(e->name, "RTV1");
		e->w = WIDTH;
		e->h = HEIGHT;
		if (!(e->mlx = mlx_init()))
			return (NULL);
		if (!(e->win = mlx_new_window(e->mlx, e->w, e->h, e->name)))
			return (NULL);
		if (!(e->pic = mlx_new_image(e->mlx, e->w, e->h)))
			return (NULL);
		e->stp = (int*)mlx_get_data_addr(e->pic, &e->pa, &e->pb, &e->pc);
//		e->cam = (t_cam){};
//		e->llight = NULL;
//		e->lobj = NULL;
		e->lobj_len = 0;
		e->llight_len = 0;
	}
	return (e);
}
