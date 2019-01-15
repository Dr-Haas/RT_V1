/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:23:08 by rmarracc          #+#    #+#             */
/*   Updated: 2018/11/05 17:23:23 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	if (n < 0)
		ft_putchar_fd('-', fd);
	i = ((n < 0) ? -n : n);
	if (n / 10 != 0)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((i % 10) + 48, fd);
}
