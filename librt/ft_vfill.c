/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:34:45 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 15:43:28 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librt.h"
#include "../libft/libft.h"

/*
** Fill each dimensions of a 3b3 vector according to na, nb, bc
*/

void	ft_vfill(double *na, double *nb, double *nc, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '{')
		i++;
	i++;
	*na = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;
	i++;
	*nb = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;
	i++;
	*nc = ft_atoi(line + i);
	return ;
}
