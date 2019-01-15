/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:38:51 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 18:39:26 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"
#include  <stdio.h>

double	ft_fmax(double nb_1, double nb_2)
{
	return (nb_1 < nb_2 ? nb_2 : nb_1);
}


unsigned int 	color_app_lum(t_vec rgb)
{
	t_u8		red;
	t_u8		green;
	t_u8		blue;

	red = ft_fmax(0., ft_fmin(255., rgb[0]));  //pas de ft_fmin
	green = ft_fmax(0., ft_fmin(255., rgb[1]));
	blue = ft_fmax(0., ft_fmin(255., rgb[2]));

	return (red << 16 | green << 8 | blue);
}

/*
** get the value of effect to the light and the shadow, 
** and fixed it to the object.
*/

t_vec	ft_get_diff_spec(t_obj *obj, t_ray *iray, t_lig *light)
{
	t_shader shader;

	shader.iray_ws_dir = ft_vtom3b3(iray_os.dir, obj.linear_otow);
	shader.lray.dir = ft_vmul(shader.lray.dir, -1);
	shader.reflect = ft_vsub(shader.lray.dir, ft_vmul(shader.normal,
		2 * ft_vdot(shader.lray.dir, shader.normal)));
	shader.spec = ft_vmul(light.rgb,
		ft_fmax(0, -ft_vdot(shader.reflect, shader.lray.dir)) * light.lum);

	return (shader);
}

/*
** get the value of the objetc color and fixed it
*/

t_vec	ft_fixed_obj_color(t_obj *obj, t_lig *light)
{
	t_shader	shader;

	shader.diff = ft_vmul(obj.rgb,
		shader.angle * light.lum * INV_PI / shader.dist_sqrd);
	shader.diff.x *= light.rgb.x;
	shader.diff.y *= light.rgb.y;
	shader.diff.z *= light.rgb.z;

	return (shader);
}

t_vec	ft_get_shader(t_obj *obj, t_ray *iray_os)
{
	t_shader shader;

	shader.lray.origin = ft_vsum(iray_os.origin, ft_vmul(iray_os.dir, iray_os.t));
	if (ft_strcmp(obj.type, "sphere"))
		shader.normal = shader.lray.origin;
	else if (ft_strequ(obj.type, "plane"))
		shader.normal = (t_vec){0, 1, 0};
	else if (ft_strcmp(obj.type, "cylinder")) 
		shader.normal = (t_vec){shader.lray.origin.x, 0, shader.lray.origin.z};
	else if (ft_strcmp(obj.type, "cone"))
		shader.normal = (t_vec){shader.lray.origin.x, 
			-shader.lray.origin.y, shader.lray.origin.z}; 
	else
		shader.normal = (t_vec){0, 0, 0};
	shader.lray.origin = ft_vsum(shader.lray.origin, ft_vmul(shader.normal, EPSILON));
	shader.lray.origin = ft_vtom4b4(shader.lray.origin, obj.otow);
	shader.normal = ft_vtom3b3(shader.normal, obj.ntow);
	shader.normal = ft_vnorm(shader.normal);
	return (shader);
}

t_vec	ft_get_color(t_obj obj, t_ray iray_os, t_lig light)
{
	t_vec		result;
	t_shader	shader;

	shader = ft_get_shader(obj, iray_os);
	shader.lray.dir = ft_vsub(light.origin, shader.lray.origin);
	shader.dist_sqrd = ft_vdot(shader.lray.dir, shader.lray.dir);
	shader.lray.t = sqrt(shader.dist_sqrd);
	shader.lray.dir = ft_vmul(shader.lray.dir, 1. / shader.lray.t);
	shader.angle = ft_fmax(0, ft_vdot(shader.lray.dir, shader.normal));

	//a faire -> plusieur source de lumiere
	t_env		e;
	t_light		cur_light;
	int			i;

	i = -1;
	while(i++ < e->llight_len)   // new
	{
//		ft_vtom3b3(ligh, 0., 0., 0.)
		cur_light = e->llight[i];
		shader.diff = (t_vec){0, 0, 0};
		shader.spec = (t_vec){0, 0, 0};

	}
	if (ft_raytracer(shader.lray, lobj, NULL, NULL))
		return ((t_vec){0. , 0. , 0.});
	ft_fixed_obj_color(obj, light)
	ft_get_diff_spec(obj, iray, light)
	result = ft_vmul(obj.rgb, shader.total_light);
	result.x = shader.spec.x + shader.diff.x;
	result.y = shader.spec.y + shader.diff.y;
	result.z = shader.spec.z + shader.diff.z;
	return(result);
} 
































/*
t_vec	ft_get_color(t_obj obj, t_ray iray_os, t_lig light)
{
	t_vec		result;
	t_shader	shader;
//	shader.lray.origin = ft_vsum(iray_os.origin, ft_vmul(iray_os.dir, iray_os.t));
//	if (ft_strcmp(obj.type, "sphere"))
//		shader.normal = shader.lray.origin;
//	else if (ft_strequ(obj.type, "plane"))
//		shader.normal = (t_vec){0, 1, 0};
//	else if (ft_strcmp(obj.type, "cylinder")) 
//		shader.normal = (t_vec){shader.lray.origin.x, 0, shader.lray.origin.z};
//	else if (ft_strcmp(obj.type, "cone"))
//		shader.normal = (t_vec){shader.lray.origin.x, 
//			-shader.lray.origin.y, shader.lray.origin.z}; 
//	else
//		shader.normal = (t_vec){0, 0, 0};
//	shader.lray.origin = ft_vsum(shader.lray.origin, ft_vmul(shader.normal, EPSILON));
//	shader.lray.origin = ft_vtom4b4(shader.lray.origin, obj.otow);
//	shader.normal = ft_vtom3b3(shader.normal, obj.ntow);
//	shader.normal = ft_vnorm(shader.normal);
	shader = ft_get_shader(obj, iray_os);
//	printf("%f    -shader.lray.origin\n", shader.lray.origin);

	shader.lray.dir = ft_vsub(light.origin, shader.lray.origin);
	shader.dist_sqrd = ft_vdot(shader.lray.dir, shader.lray.dir);
//	ft_vnorm(shader.lray.dir);
	shader.lray.t = sqrt(shader.dist_sqrd);
	shader.lray.dir = ft_vmul(shader.lray.dir, 1. / shader.lray.t);
	shader.angle = ft_fmax(0, ft_vdot(shader.lray.dir, shader.normal));
//	printf("%f     -shader.angle\n", shader.angle);

	//a faire -> plusieur source de lumiere
	t_env e;
	int i;

	i = -1;
	while(i++ < e->lligth)   // new
	{
//		ft_vtom3b3(ligh, 0., 0., 0.)
//		cur_llight = e->lligth[i];
		shader.diff = (t_vec){0, 0, 0};
		shader.spec = (t_vec){0, 0, 0};

	}
	//a faire: ombres "if (trace_ray_to_objs(shdr.lray, objlst, NULL, NULL)) return 0 0 0"
	if (ft_raytracer(shader.lray, lobj, NULL, NULL))
		return ((t_vec){0. , 0. , 0.});

	ft_fixed_obj_color(obj, light)
//	shader.diff = ft_vmul(obj.rgb,
//		shader.angle * light.lum * INV_PI / shader.dist_sqrd);
//	shader.diff.x *= light.rgb.x;
//	shader.diff.y *= light.rgb.y;
//	shader.diff.z *= light.rgb.z;
//	printf("%f    --shader.total_light\n", shader.total_light);
	ft_get_shadow(obj, iray, light)
//	shader.iray_ws_dir = ft_vtom3b3(iray_os.dir, obj.linear_otow);
//	shader.lray.dir = ft_vmul(shader.lray.dir, -1);
//	shader.reflect = ft_vsub(shader.lray.dir, ft_vmul(shader.normal,
//		2 * ft_vdot(shader.lray.dir, shader.normal)));
//	shader.spec = ft_vmul(light.rgb,
//		ft_fmax(0, -ft_vdot(shader.reflect, shader.lray.dir)) * light.lum);
//	printf("%f         --total_light\n", shader.total_light);
//	printf("%f  --specular\n", shader.specular);
//	printf("%f                --light.lum\n", light.lum);
	result = ft_vmul(obj.rgb, shader.total_light);
	result.x = shader.spec.x + shader.diff.x;
	result.y = shader.spec.y + shader.diff.y;
	result.z = shader.spec.z + shader.diff.z;
//	printf("%f  --result.x\n", result.x);
//	printf("%f  --result.y\n", result.y);
//	printf("%f  --result.z\n", result.z);
	return(result);
} 
*/

