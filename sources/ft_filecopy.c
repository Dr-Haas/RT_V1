/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:07 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 14:54:39 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"
#include <fcntl.h>
#include <unistd.h>

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
** Check if file's brackets are well open and closed
*/

int			ft_checkbrack(char **fcopy)
{
	int		i;
	int		j;
	int		k;
	char	str[4096];

	i = -1;
	j = -1;
	k = -1;
	while (fcopy[++i] != NULL)
	{
		while (fcopy[i][++j] != '\0')
		{
			fcopy[i][j] == '{' ? str[++k] = '{' : 0;
			if (fcopy[i][j] == '}' && str[k] != '{')
				return (0);
			else if (fcopy[i][j] == '}' && str[k] == '{')
				str[k--] = '\0';
		}
		if ((!ft_strcmp(fcopy[i], "scene") || !ft_strcmp(fcopy[i], "camera")
			|| !ft_strcmp(fcopy[i], "light") || !ft_strcmp(fcopy[i], "object"))
			&& str[k] != '\0')
			return (0);
		j = -1;
	}
	return (str[k] ? 0 : 1);
}

static char	**filecopy_error(void)
{
	ft_putstr("error: bad file\n");
	return (NULL);
}

/*
** Copy file into a char** table
*/

char		**ft_filecopy(char *file, int i, int exp)
{
	int		fd;
	char	b[1];
	int		len;
	char	**fcopy;
	char	*line;

	fcopy = NULL;
	len = 0;
	if ((fd = open(file, O_RDONLY)) < 0 || read(fd, b, 0) < 0)
		return (filecopy_error());
	if ((exp = ft_filecheck(file)) > 0)
	{
		if (!(fcopy = ft_memalloc((exp + 1) * sizeof(char*))))
			return (NULL);
		while ((i = sget_next_line(fd, &line)) == 1)
		{
			if (i < 0)
				return (NULL);
			if (!(fcopy[len] = ft_strdup(ft_strcln(line))))
				return (NULL);
			ft_strdel(&line);
			len++;
		}
	}
	return ((len == exp) ? fcopy : NULL);
}
