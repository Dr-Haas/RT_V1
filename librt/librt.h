/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:38:03 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/28 12:00:26 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRT_H
# define LIBRT_H

# include <math.h>
# include "../libft/libft.h"

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

t_vec				ft_vset(double x, double y, double z);
t_vec				ft_vsum(t_vec veca, t_vec vecb);
t_vec				ft_vsub(t_vec veca, t_vec vecb);
t_vec				ft_vmul(t_vec vec, double o);
t_vec				ft_vdiv(t_vec vec, double o);
double				ft_vdot(t_vec veca, t_vec vecb);
double				ft_vsqrd(t_vec vec);
t_vec				ft_vnorm(t_vec vec);
t_vec				ft_vcross(t_vec veca, t_vec vecb);

#endif
