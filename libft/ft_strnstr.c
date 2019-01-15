/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:39:22 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:39:47 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;
	int		i;
	int		j;

	i = 0;
	if (!to_find[i] || ft_strcmp(str, to_find) == 0)
		return ((char*)str);
	len = ft_strlen(to_find);
	while (str[i] && n >= len)
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char*)(str + i));
			j++;
		}
		i++;
		n--;
	}
	return (0);
}
