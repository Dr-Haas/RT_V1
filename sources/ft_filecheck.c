/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:38:58 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:30:53 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"
#include <unistd.h>
#include <fcntl.h>

/*
** Return string after removing spaces
*/

static char	*ft_strcln(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		{
			while (str[++i] != '\0')
				str[i - 1] = str[i];
			str[i - 1] = '\0';
			i = -1;
		}
	}
	return (str);
}

/*
** Check if string arguments are well formatted
*/

int			ft_strcheck(char *line)
{
	int	i;

	if (!ft_strncmp(line, "name=\"", 6))
	{
		i = 6;
		if (!ft_isalnum(line[++i]))
			return (0);
		while (ft_isalnum(line[i]))
			i++;
		return (!ft_strcmp(line + i, "\";") ? 1 : 0);
	}
	if (!ft_strncmp(line, "type=\"", 6))
	{
		i = 6;
		return (!ft_strcmp(line + i, "sphere\";")
				|| !ft_strcmp(line + i, "plane\";")
				|| !ft_strcmp(line + i, "disk\";")
				|| !ft_strcmp(line + i, "cylinder\";")
				|| !ft_strcmp(line + i, "cone\";") ? 1 : 0);
	}
	return (!ft_strcmp(line, "scene") || !ft_strcmp(line, "camera")
			|| !ft_strcmp(line, "light") || !ft_strcmp(line, "object")
			|| !ft_strcmp(line, "{") || !ft_strcmp(line, "}")
			|| !ft_strncmp(line, "#", 1) || !ft_strcmp(line, "") ? 1 : 0);
}

/*
** Check if value arguments are well formatted
*/

int			ft_valcheck(char *line)
{
	int	i;

	i = -1;
	if (!ft_strncmp(line, "fov=", 4) || !ft_strncmp(line, "radius=", 7)
		|| !ft_strncmp(line, "longitude=", 10)
		|| !ft_strncmp(line, "latitude=", 9)
		|| !ft_strncmp(line, "luminosity=", 11)
		|| !ft_strncmp(line, "width=", 6)
		|| !ft_strncmp(line, "height=", 7)
		|| !ft_strncmp(line, "precision=", 10))
	{
		while (line[i] != '=')
			i++;
		i++;
		line[i] == '-' ? i++ : 0;
		if (!ft_isdigit(line[i]))
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		return (!ft_strcmp(line + i, ";") ? 1 : 0);
	}
	return (0);
}

/*
** Check if table arguments are well formatted
*/

int			ft_tabcheck(char *line)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!ft_strncmp(line, "origin={", 8) || !ft_strncmp(line, "scale={", 7)
		|| !ft_strncmp(line, "rotation={", 10)
		|| !ft_strncmp(line, "color={", 7) || !ft_strncmp(line, "anchor={", 8)
		|| !ft_strcmp(line, "rgb={"))
	{
		while (line[i] != '{')
			i++;
		i++;
		while (++j < 3)
		{
			line[i] == '-' ? i++ : 0;
			if (!ft_isdigit(line[i]))
				return (0);
			while (ft_isdigit(line[i]))
				i++;
			if (!ft_strncmp(line + i, ",", 1))
				i++;
		}
		return (!ft_strcmp(line + i, "};") ? 1 : 0);
	}
	return (0);
}

/*
** Check file format and return file length
*/

int			ft_filecheck(char *file)
{
	int		len;
	int		fd;
	char	*line;
	int		ret;

	len = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while ((ret = sget_next_line(fd, &line)) == 1)
	{
		if (ret < 0)
			return (0);
		line = ft_strcln(line);
		if (!ft_strcheck(line) && !ft_valcheck(line) && !ft_tabcheck(line))
		{
			ft_putstr("error (line ");
			ft_putnbr(len);
			ft_putstr("): bad argument\n");
			free(line);
			return (0);
		}
		free(line);
		len++;
	}
	return (close(fd) == -1 ? 0 : len);
}
