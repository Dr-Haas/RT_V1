/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invmat4b4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:31:35 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 16:42:02 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"

/*
** Invert 4b4 matrice
*/

static double	getdet4b4(double det3b3, t_m4b4 mat, int i)
{
	double	det4b4;

	det4b4 = 0;
	if (i % 2)
		det4b4 -= mat.m[i % 4][i / 4] * det3b3;
	else
		det4b4 += mat.m[i % 4][i / 4] * det3b3;
	return (det4b4);
}

t_m4b4			ft_invmat4b4(t_m4b4 mat)
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
		submat = ft_subblocmat4b4(mat, i / 4, i % 4);
		det3b3 = ft_detmat3b3(submat);
		if (i < 4)
			det4b4 = getdet4b4(det3b3, mat, i);
		if (((i % 4) + (i / 4)) % 2)
			tmpmat.m[i % 4][i / 4] = -det3b3;
		else
			tmpmat.m[i % 4][i / 4] = det3b3;
	}
	mat = ft_transmat4b4(tmpmat);
	if (det4b4 != 0)
		mat = ft_scalemat4b4(mat, 1 / det4b4);
	else
		ft_bzero(&mat.m, 16 * sizeof(double));
	return (mat);
}
