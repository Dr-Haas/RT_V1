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
# include "stdio.h"

# define WIDTH		300
# define HEIGHT		300
# define PI			3.14159265359
# define INV_PI		0.31830988618 
# define EPSILON	0.00001
# define OK			0
# define ERROR		1

/*
** This camera structure contain variables
** used to rotate our polar camera around its anchor
*/

typedef struct	s_camera
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
}				t_camera;

/*
** This light structure contain all variables used to illuminate the scene
*/

typedef struct	s_light
{
	double		lum;
	t_vec		rgb;
	t_vec		origin;
}				t_light;

/*
** This rgb structure contain all variables used to illuminate the scene
*/
/*typedef	struct s_rgb
{
	double	red;
	double	green;
	double	blue;
}				t_rgb;
*/
/*
** This object structure contain all variables used to interpret and draw objects
*/

typedef struct	s_object
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
	t_vec       rgb;
}				t_object;


/*
** This environment structure contain all variables used by the MiniLibX
** and three lists containing cameras, lights and objects
*/

typedef struct	s_env
{
	char		name[5];
	int			w;
	int			h;
	void		*mlx;
	void		*win;
	void		*pic;
	int			*stp;
	int			pa;
	int			pb;
	int			pc;
	t_camera       cam;
	t_light		llight[10];
	int			llight_len;
	t_object		lobj[30];
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

/*
** main.c functions
*/
int				main(int argc, char **argv);
void			ft_render(void);
int				ft_hook(int key, t_env *e);
void			ft_fill_scene(void);

/*
** ft_get_env.c function
*/
t_env			*ft_get_env(void);

/*
** ft-set_obj.c functions
*/
int				ft_set_obj(char **fc, t_object *ao);
void			ft_set_objvar(char *line, t_object *ao);
void			ft_init_object(t_object *o);

/*
** ft_set_env(.c function
*/
int				ft_set_env(char *file);
void			ft_free_fcpy(char **fcpy);
int				ft_set_lig(char **fc, t_light *al);
int				ft_set_cam(char **fc, t_camera *ac);

/*
** ft_lfill.c functions
*/
void			ft_lfill(t_list **alst, void const *c, size_t cs);


/*
** ft_file_copy.c functions
*/
char			**ft_file_copy(char *file, int i, int exp);
int				ft_checkbrack(char **fcopy);


/*
** main.c functions
*/
int				ft_filecheck(char *file);
int				ft_str_check(char *line);
int				ft_val_check(char *line);
int				ft_tab_check(char *line);
int				ft_file_check(char *file);


/*
** ft_put_env.c functions
*/
void			ft_put_env(void);
void			ft_put_object(t_object o);
void			ft_put_light(t_light l);
void			ft_put_camera(t_camera c);
void			ft_putcoor(char *str, t_vec v);


/*
** ft_intersect.c functions
*/
int				ft_intersect(t_env *e, t_ray ray_ws, t_object *ahit_obj, t_ray *res_os);

/*
** ft_draw_scene.c functions
*/
void			ft_draw_scene(void);
t_vec			ft_raytrace(t_env *e, t_ray incident_ray);
void			ft_initcamera(t_camera *c);


/*
** ft_get_color.c function
*/
t_vec			ft_get_color(t_object obj, t_ray ray_os, t_light light);
void			ft_get_shader(t_shader *shader, t_object obj, t_ray iray_os);
void			ft_get_spec(t_shader *shader, t_object obj, t_ray iray_os, t_light light);
void			ft_get_diff(t_shader *shader, t_object obj, t_light light);
unsigned int 	color_app_lum(t_vec rgb);
double			ft_fmax(double nb_1, double nb_2);
double			ft_fmin(double nb_1, double nb_2);

#endif
