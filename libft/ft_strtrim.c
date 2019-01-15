/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:44:37 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 18:44:54 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	ancr;
	size_t	diff;
	char	*out;

	if (!s)
		return (NULL);
	beg = 0;
	while ((s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t'))
		beg++;
	if (!s[beg])
	{
		out = ft_strnew(1);
		if (!out)
			return (NULL);
		return (out);
	}
	ancr = ft_strlen(s) - 1;
	while (ancr && (s[ancr] == ' ' || s[ancr] == '\t' || s[ancr] == '\n'))
		ancr--;
	diff = ancr - beg;
	out = ft_strsub(s, beg, diff + 1);
	if (!out)
		return (NULL);
	return (out);
}
