/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:32 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 14:55:07 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Print coordinates
*/

void	ft_putcoor(char *str, t_vec v)
{
	int	i;

	i = -1;
	ft_putstr("\t");
	ft_putstr(str);
	if (ft_strlen(str) < 8)
		ft_putstr("\t");
	ft_putstr("\t= {");
	ft_putnbr(v.x);
	ft_putstr(", ");
	ft_putnbr(v.y);
	ft_putstr(", ");
	ft_putnbr(v.z);
	ft_putstr("};\n");
	return ;
}

/*
** Print camera
*/

void	ft_put_camera(t_camera c)
{
	ft_putstr("\033[31;1mcamera\033[0m\n{\n\tfov\t\t= ");
	ft_putnbr(c.fov);
	ft_putstr(";\n");
	ft_putcoor("anchor", c.anchor);
	ft_putstr("\tradius\t\t= ");
	ft_putnbr(c.radius);
	ft_putstr(";\n\tlongitude\t= ");
	ft_putnbr(c.lon);
	ft_putstr(";\n\tlatitude\t= ");
	ft_putnbr(c.lat);
	ft_putstr(";\n");
	ft_putstr("}\n\n");
	return ;
}

/*
** Print light
*/

void	ft_put_light(t_light l)
{
	ft_putstr("\033[33;1mlight\033[0m\n{\n\tluminosity\t= ");
	ft_putnbr(l.lum);
	ft_putstr(";\n");
	ft_putcoor("origin", l.origin);
	ft_putcoor("color", l.rgb);  //new
	ft_putstr("}\n\n");
	return ;
}

/*
** Print object
*/

void	ft_put_object(t_object o)
{
	t_vec rgb;

	rgb.x = o.rgb.x;
	rgb.y = o.rgb.y;
	rgb.z = o.rgb.z;
	ft_putstr("\033[32;1mobject\033[0m\n{\n\ttype\t\t= \"");
	ft_putstr(o.type);
	ft_putstr(";\n");
	ft_putcoor("origin", o.origin);
	ft_putcoor("scale", o.scale);
	ft_putcoor("rotation", ft_vmul(o.rot, 180 / PI));
	ft_putcoor("color", rgb);
	ft_putstr("}\n\n");
	return ;
}

/*
** Render environment
*/

void	ft_put_env(void)
{
	t_env		*e;
	int			i;

	i = -1;
	e = ft_get_env();
	ft_put_camera(e->cam);
	while (++i < e->llight_len)
		ft_put_light(e->llight[i]);
	i = -1;
	while (++i < e->lobj_len)
		ft_put_object(e->lobj[i]);
	return ;
}
