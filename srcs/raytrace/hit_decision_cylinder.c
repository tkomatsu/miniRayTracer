/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_decision_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:12:11 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/29 18:37:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ip	*intersect_point_cy(t_shape *shape, t_ray *ray, double t, _Bool face)
{
	t_ip	*intp;
	t_vec3	pc;
	double	h;
	t_vec3	normal;

	if (!(intp = ft_calloc(sizeof(t_ip), 1)))
		return (NULL);
	intp->distance = t;
	intp->point = vadd(ray->point, vnproduct(ray->dir, t));
	pc = vsubtract(intp->point, shape->u_obj.cylinder.point);
	h = vdot(pc, shape->u_obj.cylinder.normal);
	normal = vsubtract(pc, vnproduct(shape->u_obj.cylinder.normal, h));
	intp->normal = normal;
	if (!face)
		intp->normal = vnproduct(normal, -1);
	vunit(&intp->normal);
	intp->color = shape->color;
	return (intp);
}

int		inside_cy(t_shape *shape, t_ray *ray, double t)
{
	t_vec3	p;
	double	h;

	p = vadd(ray->point, vnproduct(ray->dir, t));
	h = vdot(shape->u_obj.cylinder.normal,
			vsubtract(p, shape->u_obj.cylinder.point));
	return (EPSILON <= h && h <= shape->u_obj.cylinder.height);
}

t_ip	*result_cylinder(t_shape *shape, t_ray *ray, t_spparam var)
{
	if (EPSILON <= var.t1 && inside_cy(shape, ray, var.t1))
	{
		var.t = var.t1;
		return (intersect_point_cy(shape, ray, var.t, true));
	}
	if (EPSILON <= var.t2 && inside_cy(shape, ray, var.t2))
	{
		var.t = var.t2;
		return (intersect_point_cy(shape, ray, var.t, false));
	}
	return (NULL);
}

t_ip	*intersection_test_cy(t_shape *shape, t_ray *ray)
{
	t_spparam	var;
	t_vec3		j;
	t_vec3		k;
	t_vec3		n;

	vunit(&shape->u_obj.cylinder.normal);
	n = shape->u_obj.cylinder.normal;
	j = vsubtract(ray->point, shape->u_obj.cylinder.point);
	k = vcross(ray->dir, n);
	var.a = vdot(k, k);
	var.b = 2 * vdot(k, vcross(j, n));
	var.c = vdot(vcross(j, n), vcross(j, n))
		- pow(shape->u_obj.cylinder.radius, 2);
	if ((var.d = pow(var.b, 2) - 4 * var.a * var.c) < 0)
		return (NULL);
	var.t1 = (-var.b - sqrt(var.d)) / (2 * var.a);
	var.t2 = (-var.b + sqrt(var.d)) / (2 * var.a);
	return (result_cylinder(shape, ray, var));
}
