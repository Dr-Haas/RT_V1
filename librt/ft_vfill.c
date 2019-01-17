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


#include <stdio.h> //a enlever


/*
** Fill each dimensions of a 3b3 vector according to na, nb, bc
*/

t_vec	ft_vfill(char *line)
{
	int		i;
	t_vec	res;

	i = 0;
	while (line[i] != '\0' && line[i] != '{')
		i++;
	i++;
	res.x = ft_atoi(line + i);
//	printf("\033[34m res.x --> \033[35m%f\n\033[0m", res.x);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;
	i++;
	res.y = ft_atoi(line + i);
//	printf("\033[36m res.y --> \033[35m%f\n\033[0m", res.y);
	while (ft_isdigit(line[i]) || line[i] == '-')
		i++;
	i++;
	res.z = ft_atoi(line + i);
//	printf("\033[38m res.z --> \033[35m%f\n\033[0m", res.z);
	return (res);
}
