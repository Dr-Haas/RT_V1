/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:36 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:25:19 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Set env value according to file copy
**
** returns 1 if scene set OK.
*/

int		ft_setscene(char **fc, t_env *e)
{
	int		i;
//	t_env	*e;

	i = 0;
	e = ft_getenv();
	if (ft_strcmp(fc[++i], "{"))
		return (ERROR);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "precision=", 10))
			e->precision = ft_atoi(fc[i] + 10);
		else if (!ft_strcmp(fc[i], "}"))
			return (OK);
	return (ERROR);
}

/*
** Set camera structure according to file copy
*/

int		ft_setcam(char **fc, t_camera *ac)
{
	int		i;

	i = 0;
	ac->fov = 0;
	ft_vclr(&ac->anchor);
	ac->radius = 50;
	ac->lon = 0;
	ac->lat = 0;
	if (ft_strcmp(fc[++i], "{"))
		return (0);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "fov=", 4))
			ac->fov = ft_atoi(fc[i] + 4);
		else if (!ft_strncmp(fc[i], "anchor=", 7))
			ft_vfill(&ac->anchor.x, &ac->anchor.y, &ac->anchor.z, fc[i]);
		else if (!ft_strncmp(fc[i], "radius=", 7))
			ac->radius = ft_atoi(fc[i] + 7);
		else if (!ft_strncmp(fc[i], "longitude=", 10))
			ac->lon = ft_atoi(fc[i] + 10);
		else if (!ft_strncmp(fc[i], "latitude=", 9))
			ac->lat = ft_atoi(fc[i] + 9);
		else if (!ft_strcmp(fc[i], "}"))
			return (1);
	return (0);
}

/*
** Set light structure according to file copy
*/

int		ft_setlig(char **fc, t_light *al)
{
	int		i;

	i = 0;
	al->lum = 0;
	ft_vclr(&al->origin);
	if (ft_strcmp(fc[++i], "{"))
		return (0);
	while (fc[++i] != NULL)
		if (!ft_strncmp(fc[i], "luminosity=", 11))
			al->lum = ft_atoi(fc[i] + 11);
		else if (!ft_strcmp(fc[i], "rgb={"))
			ft_vfill(&al->rgb.x, &al->rgb.y, &al->rgb.z, fc[i]);  //new
		else if (!ft_strncmp(fc[i], "origin={", 8))
			ft_vfill(&al->origin.x, &al->origin.y, &al->origin.z, fc[i]);
		else if (!ft_strcmp(fc[i], "}"))
			return (1);
	return (0);
}

/*
** Free file copy
*/

void	ft_freefcpy(char **fcpy)
{
	int		i;

	i = -1;
	while (fcpy[++i] != NULL)
		free(fcpy[i]);
	free(fcpy);
	return ;
}

/*
** Set and fill env lists according to file copy
*/

int		ft_setenv(char *file)
{
	int		i;
	int		status;
	char	**fcpy;
	t_env	*e;

	i = -1;
	status = OK;
	if (!(fcpy = ft_filecopy(file, 0, 0)))
		return (ERROR);
	e = ft_getenv();
	while (fcpy[++i] != NULL && status == OK)
	{
		if (!ft_strcmp(fcpy[i], "scene") && ft_setscene(fcpy + i, e) == ERROR)
			status = ERROR;
		else if (!ft_strcmp(fcpy[i], "camera") && !ft_setcam(fcpy + i, &(e->cam)))
			status = ERROR;
		else if (!ft_strcmp(fcpy[i], "light") && !ft_setlig(fcpy + i, &(e->llight[e->llight_len++])))
			status = ERROR;
		else if (!ft_strcmp(fcpy[i], "object") && !ft_setobj(fcpy + i, &(e->lobj[e->lobj_len++])))
			status = ERROR;
	}
	ft_freefcpy(fcpy);
	return (status);
}
