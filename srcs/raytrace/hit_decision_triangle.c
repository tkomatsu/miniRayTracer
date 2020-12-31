/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_decision_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:36:06 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:37:04 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ip	*intersect_point_tr(t_shape *shape, t_ray *ray, double t, t_vec3 *n)
{
	t_ip	*intp;

	if (!(intp = ft_calloc(sizeof(t_ip), 1)))
		return (NULL);
	intp->distance = t;
	intp->point = vadd(ray->point, vnproduct(ray->dir, t));
	intp->normal = vcross(vsubtract(n[1], n[0]), vsubtract(n[2], n[0]));
	if (vdot(intp->normal, vnproduct(ray->dir, -1)) < 0)
		intp->normal = vnproduct(intp->normal, -1);
	vunit(&intp->normal);
	intp->color = shape->color;
	return (intp);
}

t_ip	*intersection_test_tr(t_shape *shape, t_ray *ray)
{
	double	t;
	t_vec3	tr[3];
	t_vec3	v[5];
	double	n[4];

	tr[0] = shape->u_obj.triangle.first;
	tr[1] = shape->u_obj.triangle.second;
	tr[2] = shape->u_obj.triangle.third;
	v[0] = vsubtract(tr[1], tr[0]);
	v[1] = vsubtract(tr[2], tr[0]);
	v[2] = vcross(ray->dir, v[1]);
	if (fabs(n[0] = vdot(v[0], v[2])) < EPSILON)
		return (NULL);
	n[1] = 1.0 / n[0];
	v[3] = vsubtract(ray->point, tr[0]);
	n[2] = vdot(v[3], v[2]) * n[1];
	if (n[2] < EPSILON || n[2] > 1 + EPSILON)
		return (NULL);
	v[4] = vcross(v[3], v[0]);
	n[3] = vdot(ray->dir, v[4]) * n[1];
	if (n[3] < EPSILON || n[2] + n[3] > 1 + EPSILON)
		return (NULL);
	if ((t = vdot(v[1], v[4]) * n[1]) < EPSILON)
		return (NULL);
	return (intersect_point_tr(shape, ray, t, tr));
}
