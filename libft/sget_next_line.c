/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sget_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:15:02 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/28 12:02:59 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static size_t	ft_strlen_ret(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

static char		*ft_strdup_ret(char *src)
{
	char		*dest;
	size_t		i;
	size_t		len;

	len = ft_strlen_ret(src);
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		insert_line(char *file, char **line)
{
	char		*temp;
	char		*str;

	str = ft_strchr(file, '\n');
	if (str)
	{
		if (!(*line = ft_strdup_ret(file)))
			return (-1);
		if (!(temp = ft_strdup(str + 1)))
			return (-1);
		ft_strclr(file);
		ft_strcpy(file, temp);
		if (!(file[0]))
			ft_strclr(file);
		ft_strdel(&temp);
	}
	else
	{
		if (!(*line = ft_strdup(file)))
			return (-1);
		ft_strclr(file);
	}
	return (1);
}

int				sget_next_line(const int fd, char **line)
{
	static char	file[2 * (BUFF_SIZE + 1)] = {0};
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 0;
	if (fd < 0 || read(fd, buf, 0) < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ft_strlen(file) < BUFF_SIZE + 1)
			&& (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (ft_strlen(file) + ret > (2 * BUFF_SIZE))
		{
			ft_strdel(line);
			return (-1);
		}
		ft_strcat(file, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && ft_strlen(file) == 0)
		return (0);
	return (insert_line(file, line));
}
