/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:22:54 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/28 11:09:02 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

uint64_t		ft_max3(uint64_t r, uint64_t g, uint64_t b)
{
	uint64_t	max;

	max = r;
	if (g > max)
		max = g;
	if (b > max)
		max = b;
	return (max);
}

uint64_t		color_clamp(uint64_t c)
{
	return ((c > 255) ? 255 : c);
}

uint32_t		color_mult(uint32_t rgb, double ratio)
{
	uint64_t	r;
	uint64_t	g;
	uint64_t	b;

	rgb = rgb % (256 * 256 * 256);
	b = rgb % 256;
	g = (rgb / 256) % 256;
	r = (rgb / (256 * 256)) % 256;
	b = (b == 0) ? 1 : b;
	g = (g == 0) ? 1 : g;
	r = (r == 0) ? 1 : r;
	r = (uint64_t)(color_clamp((uint64_t)((double)r * ratio)));
	g = (uint64_t)(color_clamp((uint64_t)((double)g * ratio)));
	b = (uint64_t)(color_clamp((uint64_t)((double)b * ratio)));
	return ((uint32_t)(b + 256 * g + 256 * 256 * r));
}
