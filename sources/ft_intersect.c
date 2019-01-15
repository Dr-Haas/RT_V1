/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:39:18 by ghaas             #+#    #+#             */
/*   Updated: 2019/01/06 14:54:54 by rmarracc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Calcul sphere intersection
**
** Sphere definition:
** C is the center of the sphere
** r is the radius of the sphere
**
** To hit a sphere we notice that:
** len(P-C) = r
** This means that the distance between the sphere center and the hit point
** equals r, which is true when P lies on the surface of the sphere.
**
** Solution:
** len(D*t+X) = r
** dot(D*t+X) = r^2
** D|D*(t^2) + 2*D|X*t + X|X - r^2 = 0
**
** Hence we have a quadratic equation that we have to solve.
** To simplify, we have the following trinomial coefficients:
** a = D|D
** b/2 = D|X
** c = X|X - r*r
** Surface normal is N=nrm(P-C).
*/

double	ft_intersectsphere(t_ray r)
{
	t_cal	c;

	c.radius = 0.5;
	c.a = ft_vsqrd(r.dir);
	c.b = 2 * ft_vdot(r.dir, r.origin);
	c.c = ft_vsqrd(r.origin) - pow(c.radius, 2);
	if ((c.delta = pow(c.b, 2) - 4 * c.a * c.c) > EPSILON)
	{
		c.t[0] = (-c.b - sqrt(c.delta)) / (2 * c.a);
		c.t[1] = (-c.b + sqrt(c.delta)) / (2 * c.a);
		if (c.t[1] > 0 && c.t[1] < c.t[0])
			return (c.t[1]);
		else if (c.t[0] >= 0)
			return (c.t[0]);
	}
	return (-1);
}

/*
** Calcul plane intersection
**
** Plane definition:
** C is a point that lies on the plane
** V is the plane normal (unit length)
**
** To hit a plane we notice that:
** (P-C)|V = 0
** This means that the P-C vector is perpendicular to the normal,
** which is true when the point P lies on the plane.
**
** Solution:
** (D*t+X)|V = 0
** D|V*t = -X|V
** t = -X|V / D|V
**
** Before the division we should check whether D|V is nonzero.
** We can also check if the signs of D|V and X|V are different
** (if not, resulting t will be negative).
** Surface normal vector at point P equals to the plane normal,
** unless D|V is negative, in which case N=-V.
*/

double	ft_intersectplane(t_ray r)
{
	t_cal	c;
	t_vec	dir;

	dir = ft_vset(0, 1, 0);
	if ((c.t[0] = -ft_vdot(r.origin, dir) / ft_vdot(r.dir, dir)) > EPSILON)
	{
		if (c.t[0] >= 0)
			return (c.t[0]);
	}
	return (-1);
}

/*
** Calcul disk intersection
**
** First we can test if the ray intersects the plane in which lies the disk.
** For the ray-plane intersection step, we can simply use the code
** we have developed for the ray-plane intersection test.
** If the ray intersects this plane, all we have to do is to compute
** the intersection point, then compute the distance from this point
** to this disk's center. If this distance is lower or equal to the disk radius,
** then the ray intersects the disk.
*/

/*
** double	ft_intersectdisk(t_ray r, t_obj o)
** {
** 	t_cal	c;
**
** 	if ((c.t[0] = ft_intersectplane(r, o)) >= 0)
** 	{
** 		c.o = ft_vsum(r.o, ft_vmul(r.d, c.t[0]));
** 		c.d = ft_vsub(c.o, o.o);
** 		if (sqrtf(ft_vdot(c.d, c.d)) <= o.w / 2)
** 			return (c.t[0]);
** 	}
** 	return (-1);
** }
*/

/*
** Calcul cylinder intersection
**
** Cylinder definition:
** C is the start cap point of the cylinder
** V is a unit length vector that determines cylinder's axis
** r is the cylinder's radius
** maxm determines cylinder's end cap point
**
** To hit a cylinder we notice that:
** A = C + V*m
** ( P-A )|V = 0
** len( P-A ) = r
**
** where m is a scalar that determines the closest point on the axis
** to the hit point. The P-A vector is perpendicular to V, what guarantees
** the closest distance to the axis. P-A is the cylinder's radius.
**
** Solution:
** (P-C-V*m)|V = 0
** (P-C)|V = m*(V|V) = m   (len(V)=1)
** m = (D*t+X)|V
** m = D|V*t + X|V
**
** len(P-C-V*m) = r
** dot( D*t+X - V*(D|V*t + X|V) ) = r^2
** dot( (D-V*(D|V))*t + (X-V*(X|V)) ) = r^2
** 		dot( A-V*(A|V) ) = A|A - 2*(A|V)^2 + V|V * (A|V)^2 =
** 			= A|A - (A|V)^2
** a*t^2 + b*t + c = 0
** a = D|D - (D|V)^2
** c = X|X - (X|V)^2 - r^2
** b = 2 * (D-V*(D|V))|(X-V*(X|V)) =
** 		= 2 * (D|X - D|V*(X|V) - X|V*(D|V) + (D|V)*(X|V)) =
** 		= 2 * (D|X - (D|V)*(X|V))
**
** Finally:
** a = D|D - (D|V)^2
** b/2 = D|X - (D|V)*(X|V)
** c = X|X - (X|V)^2 - r*r
**
** Surface normal is:
** m = D|V*t + X|V
** N = nrm( P-C-V*m )
**
** There are two points on the cylinder that we hit (it can be the same
** point twice). We have to calculate two m values and test whether they fall
** in the range of [0,maxm]. If any falls out, we can either throw the point
** that corresponds to it away (the cylinder will have a hole)
** or we can cap the cylinder with planes. One of the planes is defined
** by a pair (C,-V) and the other by (C+V*maxm,V). We hit the planes
** like a typical plane; the dot products we have already calculated,
** we only need to do the division(s)
**
** https://github.com/spinatelli/raytracer/blob/master/Cylinder.cpp
*/

double	ft_intersectcylinder(t_ray r)
{
	t_cal	c;
	t_vec	dir;

	c.radius = 0.5;
	dir = ft_vset(0, 1, 0);
	c.a = ft_vsqrd(r.dir) - pow(ft_vdot(r.dir, dir), 2);
	c.b = 2 * (ft_vdot(r.dir, r.origin) - ft_vdot(r.dir, dir)
		* ft_vdot(r.origin, dir));
	c.c = ft_vsqrd(r.origin) - pow(ft_vdot(r.origin, dir), 2)
		- pow(c.radius, 2);
	if ((c.delta = pow(c.b, 2) - 4 * c.a * c.c) > EPSILON)
	{
		c.t[0] = (-c.b - sqrt(c.delta)) / (2 * c.a);
		c.t[1] = (-c.b + sqrt(c.delta)) / (2 * c.a);
		if (c.t[1] > 0 && c.t[1] < c.t[0])
			return (c.t[1]);
		else if (c.t[0] >= 0)
			return (c.t[0]);
	}
	return (-1);
}

/*
** Calcul cone intersection
**
** Cone definition:
** C is the vertex of the cone
** V is the axis vector
** k is the tangent of half angle of the cone
** minm, maxm define cap points
**
** To hit a cone we notice that:
** A = C + V*m
** ( P-A )|V = 0
** len( P-A )/m = k
** The (P-A)|V=0 equation is identical to the equation we know from cylinder,
** since cylinder is a special case of a cone.
**
** Solution:
** m = D|V*t + X|V (like for cylinder)
** len( P-C-V*m ) = m*k
** dot( D*t+X - V*(D|V*t + X|V) ) = k^2 * ( D|V*t + X|V )^2
** dot( (D-V*(D|V))*t + X-V*(X|V) ) = k^2 * ( D|V*t + X|V )^2
**
** Now coefficients of the left-side trinomial are similar like for cylinder:
** a = D|D - (D|V)^2
** b/2 = D|X - (D|V)*(X|V)
** c = X|X - (X|V)^2
**
** And the right-side coefficients:
** k^2 * ( D|V*t + X|V )^2 =
** 		= k^2 * ( (D|V)^2 * t^2 + 2*(D|V)*(X|V)*t + (X|V)^2 )
** a = k*k*(D|V)^2
** b/2 = k*k*(D|V)*(X|V)
** c = k*k*(X|V)^2
**
** Finally:
** a = D|D - (1+k*k)*(D|V)^2
** b/2 = D|X - (1+k*k)*(D|V)*(X|V)
** c = X|X - (1+k*k)*(X|V)^2
**
** To calculate surface normal it is enough to notice that we have
** to normalize vector (P-C-V*m) - V*a. How to calculate a ? The angle between
** the normal and P-C-V*m must be the same as half angle of the cone. Hence:
** a/r = k
** r/m = k
** a = m*k*k
** N = nrm( P-C-V*m - V*m*k*k )
** N = nrm( P-C - (1+k*k)*V*m )
** We cap the cone like a cylinder (except that the start cap point does
** not have to be at 0).
*/

double	ft_intersectcone(t_ray r)
{
	t_cal	c;
	double	k;
	t_vec	dir;

	k = PI / 3;
	dir = ft_vset(0, 1, 0);
	c.a = ft_vsqrd(r.dir) - (1 + pow(k, 2)) * pow(ft_vdot(r.dir, dir), 2);
	c.b = 2 * (ft_vdot(r.dir, r.origin)
	- (1 + pow(k, 2)) * ft_vdot(r.dir, dir) * ft_vdot(r.origin, dir));
	c.c = ft_vsqrd(r.origin) - (1 + pow(k, 2)) * pow(ft_vdot(r.origin, dir), 2);
	if ((c.delta = pow(c.b, 2) - 4 * c.a * c.c) > EPSILON)
	{
		c.t[0] = (-c.b - sqrt(c.delta)) / (2 * c.a);
		c.t[1] = (-c.b + sqrt(c.delta)) / (2 * c.a);
		if (c.t[1] > 0 && c.t[1] < c.t[0])
			return (c.t[1]);
		else if (c.t[0] >= 0)
			return (c.t[0]);
	}
	return (-1);
}

/*
** Calcul intersection and return intersection distance
** http://hugi.scene.org/online/hugi24/index%20coding%20&%20maths.htm
** 		Raytracing Shapes
**
** if (!ft_strcmp(o.type, "disk"))
** 		t = ft_intersectdisk(r, o);
*/

double	ft_intersect(t_env *e, t_ray ray, t_obj *ahit_obj)
{
	double	t[2];
	t_obj	o;
	t_ray	oray;

	t[1] = INFINITY;
	while (i )//lobj)
	{
//		o = *((t_obj*)lobj->content);
		oray.origin = ft_vtom4b4(ray.origin, o.wtoo);
		oray.dir = ft_vtom3b3(ray.dir, o.linear_wtoo);
		!ft_strcmp(o.type, "sphere") ? t[0] = ft_intersectsphere(oray) : 1;
		!ft_strcmp(o.type, "plane") ? t[0] = ft_intersectplane(oray) : 1;
		!ft_strcmp(o.type, "cylinder") ? t[0] = ft_intersectcylinder(oray) : 1;
		!ft_strcmp(o.type, "cone") ? t[0] = ft_intersectcone(oray) : 1;
		if (EPSILON < t[0] && t[0] < t[1])
		{
			t[1] = t[0];
			*ao = o;
		}
//		lobj = lobj->next;
	}
	return (t[1]);
}
