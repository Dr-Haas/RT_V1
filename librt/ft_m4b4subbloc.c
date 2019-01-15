/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4b4subbloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:34 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:34:25 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Subbloc 4b4 matrice
*/

t_m3b3	ft_m4b4subbloc(t_m4b4 mat, int i, int j)
{
	int		k;
	int		found;
	t_m3b3	subbloc;

	k = -1;
	found = -1;
	if (0 > i || i >= 4 || 0 > j || j >= 4)
	{
		ft_bzero(&subbloc.m, 9 * sizeof(double));
		return (subbloc);
	}
	while (++k < 16)
	{
		if (k / 4 == i)
			k += 3;
		else if (k % 4 != j)
		{
			found++;
			subbloc.m[found % 3][found / 3] = mat.m[k % 4][k / 4];
		}
	}
	return (subbloc);
}
