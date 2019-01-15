/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:24:26 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:38:18 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
# include "librt/librt.h"
# include "../minilibx_macos/mlx.h"

# define WIDTH		1200
# define HEIGHT		1200
# define PI			3.14159265359
# define INV_PI		0.31830988618 
# define EPSILON	0.00001
# define OK			0
# define ERROR		1

/*
** This camera structure contain variables
** used to rotate our polar camera around its anchor
*/

typedef struct	s_cam
{
	double		fov;
	t_vec		anchor;
	double		radius;
	double		lon;
	double		lat;
	t_vec		world;
	t_vec		reltv;
	t_vec		polar;
	t_vec		xaxis;
	t_vec		yaxis;
	t_vec		zaxis;
	t_m4b4		ctow;
	t_m4b4		wtoc;
}				t_cam;

/*
** This light structure contain all variables used to illuminate the scene
*/

typedef struct	s_light
{
	double		lum;
	t_vec		rgb;
	t_vec		origin;
}				t_lig;

/*
** This rgb structure contain all variables used to illuminate the scene
*/
typedef	struct s_rgb
{
	double	red;
	double	green;
	double	blue;
}				t_rgb;

/*
** This object structure contain all variables used to interpret and draw objects
*/

typedef struct	s_obj
{
	char		*type;
	t_vec		scale;
	t_vec		origin;
	t_vec		rot;
	t_vec		dir;
	t_m3b3		linear_otow;
	t_m3b3		linear_wtoo;
	t_m4b4		otow;
	t_m4b4		wtoo;
	t_m3b3		ntow;
	t_rgb       rgb;
}				t_obj;


/*
** This environment structure contain all variables used by the MiniLibX
** and three lists containing cameras, lights and objects
*/

typedef struct	s_env
{
	char		name[5];
	int			w;
	int			h;
	int			precision;
	void		*mlx;
	void		*win;
	void		*pic;
	int			*stp;
	int			pa;
	int			pb;
	int			pc;
	t_cam       cam;
	t_lig		llight[10];
	int			llight_len;
	t_obj		lobj[30];
	int			lobj_len;

}				t_env;

/*
** This ray structure contain origin and direction of a ray
*/

typedef struct	s_ray
{
	t_vec		origin;
	t_vec		dir;
	double 		t;
}				t_ray;

/*
**	This shader structure contain all value for the color calculation
*/

typedef struct s_shader
{
	t_ray	lray;
//	t_vec	hitpos;
//	t_vec	light;
//	double	dist;
	t_vec	iray_ws_dir;
	double	dist_sqrd;
	t_vec	reflect;
	t_vec	normal;
	double	angle;
	t_vec	diff;
	t_vec	spec;
}				t_shader;

/*
** This calculation structure contain all variables used to calculate 
** intersection between rays and objects
*/

typedef struct	s_cal
{
	double		radius;
	t_vec		origin;
	t_vec		dir;
	double		alpha;
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t[2];
}				t_cal;

t_env			*ft_getenv(void);
int				ft_setobj(char **fc, t_obj *ao);
int				ft_setenv(char *file);
void			ft_lfill(t_list **alst, void const *c, size_t cs);
char			**ft_filecopy(char *file, int i, int exp);
int				ft_filecheck(char *file);
void			ft_putenv(void);
double			ft_intersect(t_env *e, t_ray r, t_obj *ao);
void			ft_drawscene(void);
t_vec			ft_getcolor(t_obj obj, t_ray ray_os, t_lig light);

#endif
