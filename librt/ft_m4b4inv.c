/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m4b4inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:33:16 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:35:03 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Invert 4b4 matrice
*/

t_m4b4	ft_m4b4inv(t_m4b4 mat)
{
	int		i;
	t_m4b4	tmpmat;
	t_m3b3	submat;
	double	det3b3;
	double	det4b4;

	i = -1;
	det4b4 = 0;
	while (++i < 16)
	{
		submat = ft_m4b4subbloc(mat, i / 4, i % 4);
		det3b3 = ft_m3b3det(submat);
		if (i < 4)
			i % 2 ? (det4b4 -= mat.m[i % 4][i / 4] * det3b3) :
			(det4b4 += mat.m[i % 4][i / 4] * det3b3);
		((i % 4) + (i / 4)) % 2 ? (tmpmat.m[i % 4][i / 4] = -det3b3) :
		(tmpmat.m[i % 4][i / 4] = det3b3);
	}
	mat = ft_m4b4trans(tmpmat);
	if (det4b4 != 0)
		mat = ft_m4b4scale(mat, 1 / det4b4);
	else
		ft_bzero(&mat.m, 16 * sizeof(double));
	return (mat);
}
