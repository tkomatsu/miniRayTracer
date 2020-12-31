/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_decision_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:17:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:35:35 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ip	*intersect_point_sq(t_shape *shape, t_ray *ray, double t)
{
	t_ip	*intp;

	if (!(intp = ft_calloc(sizeof(t_ip), 1)))
		return (NULL);
	intp->distance = t;
	intp->point = vadd(ray->point, vnproduct(ray->dir, t));
	intp->normal = shape->u_obj.square.normal;
	if (vdot(intp->normal, vnproduct(ray->dir, -1)) < 0)
		intp->normal = vnproduct(intp->normal, -1);
	vunit(&intp->normal);
	intp->color = shape->color;
	return (intp);
}

int		inside_square(t_shape *shape, t_ray *ray, double t)
{
	t_vec3	u;
	t_vec3	v;
	t_vec3	n;
	t_vec3	op;

	n = shape->u_obj.square.normal;
	vunit(&n);
	u.z = 0;
	u.x = n.y / sqrt(pow(n.x, 2) + pow(n.y, 2));
	u.y = -1 * n.x / sqrt(pow(n.x, 2) + pow(n.y, 2));
	if (n.x == 0 && n.y == 0)
	{
		u.x = 1;
		u.y = 0;
	}
	v = vcross(n, u);
	op = vsubtract(shape->u_obj.square.point, vadd(
				ray->point, vnproduct(ray->dir, t)));
	if (fabs(vdot(op, u)) <= shape->u_obj.square.size &&
			fabs(vdot(op, v)) <= shape->u_obj.square.size)
		return (1);
	return (0);
}

t_ip	*intersection_test_sq(t_shape *shape, t_ray *ray)
{
	double	t;
	t_vec3	pc_pp;
	double	dn_dot;

	dn_dot = vdot(shape->u_obj.square.normal, ray->dir);
	if (fabs(dn_dot) < 1e-6)
		return (NULL);
	pc_pp = vsubtract(shape->u_obj.square.point, ray->point);
	t = vdot(pc_pp, shape->u_obj.square.normal) / dn_dot;
	if (t > EPSILON && inside_square(shape, ray, t))
		return (intersect_point_sq(shape, ray, t));
	return (NULL);
}
