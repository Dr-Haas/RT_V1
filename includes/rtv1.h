/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarracc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 08:11:00 by rmarracc          #+#    #+#             */
/*   Updated: 2019/01/28 11:46:45 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../librt/librt.h"
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define XSIZE		1200
# define YSIZE		1200
# define FOV		90
# define INF		1000000

typedef struct		s_camera
{
	int16_t			pos[3];
	int16_t			dir[3];
}					t_camera;

typedef struct		s_light
{
	uint32_t		pow;
	int16_t			pos[3];
	int16_t			dir[3];
	uint32_t		rgb;
}					t_light;

typedef struct		s_object
{
	uint8_t			type;
	int16_t			pos[3];
	int16_t			norm[3];
	uint32_t		rgb;
	uint8_t			radius;
	uint8_t			specular;
}					t_object;

typedef struct		s_inter
{
	double			dist;
	uint32_t		color;
	t_vec			p;
	t_vec			norm;
}					t_inter;

typedef struct		s_disp
{
	double			ret;
	double			d;
	double			df;
	double			sp;
}					t_disp;

typedef struct		s_calc
{
	t_vec			tmp1;
	t_vec			tmp2;
	t_vec			tmp3;
	double			d1;
	double			d2;
	double			d3;
	double			delta;
	double			r1;
	double			r2;
	double			res;
	double			m;
	t_vec			c;
}					t_calc;

typedef struct		s_ray
{
	t_vec			origin;
	t_vec			dir;
}					t_ray;

typedef struct		s_env
{
	t_list			*light;
	t_list			*obj;
	t_camera		cam;
	void			*mlx;
	void			*win;
	void			*img;
	uint32_t		*addr;
}					t_env;

void				parse_bin(t_env *setup, int fd);
void				delelem(void *data, size_t size);
void				print_data(t_env *setup);
void				rt_mlx_init(t_env *setup);
void				rt_mlx_loop(t_env *setup);
void				raytrace(t_env *setup, int i, int j);
uint32_t			ft_intersect(t_env *setup, t_ray incid);
uint32_t			color_mult(uint32_t rgb, double ratio);
t_inter				ft_equation(t_calc equ, t_object cur, t_ray incid);
uint32_t			get_color(t_env *setup, t_ray incid, t_inter it,
		t_object o);
t_inter				ft_intersectsphere(t_ray incid, t_object cur);
t_inter				ft_intersectplane(t_ray incid, t_object cur);
t_inter				ft_intersectcone(t_ray incid, t_object cur);
t_inter				ft_intersectcylinder(t_ray incid, t_object cur);
t_inter				intersect_type(t_object cur, t_ray incid, t_inter inter);
t_vec				pos_to_vec(t_light cur);
uint8_t				bool_s(t_object o);

#endif
