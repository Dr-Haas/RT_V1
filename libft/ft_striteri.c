/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:49:48 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:31:15 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return ;
	ptr = s;
	i = 0;
	while (*ptr && f)
	{
		f(i, ptr);
		ptr++;
		i++;
	}
}
