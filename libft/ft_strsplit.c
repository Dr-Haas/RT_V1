/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:41:04 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:43:03 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_len(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i + 1);
}

static int		word_count(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char		*get_line(char *ptr, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * word_len(ptr, c));
	if (!str)
		return (NULL);
	while (ptr[i] != c && ptr[i])
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		**freenull(char **array)
{
	int k;

	k = 0;
	while (array[k])
	{
		free(array[k]);
		k++;
	}
	free(array);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*ptr;
	char	**array;
	int		k;

	if (!s)
		return (NULL);
	ptr = (char*)s;
	k = 0;
	array = (char**)malloc(sizeof(char*) * (word_count(s, c) + 1));
	if (!array)
		return (NULL);
	while (*ptr)
	{
		while (*ptr == c && *ptr)
			ptr++;
		if (!(*ptr))
			break ;
		if (!(array[k] = get_line(ptr, c)))
			return (freenull(array));
		while (*ptr != c && *ptr)
			ptr++;
		k++;
	}
	array[k] = NULL;
	return (array);
}
