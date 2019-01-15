/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:46:40 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/29 22:23:39 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;

	res = 0;
	while ((*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	sign = (*str == 45 || *str == 43) ? -(*str++) + 44 : 1;
	while (*str > 47 && *str < 58)
	{
		res = (res * 10) + *str++ - 48;
		if (res > 9223372036854775807)
			return ((sign == 1) ? -1 : 0);
	}
	return ((int)(res * sign));
}
