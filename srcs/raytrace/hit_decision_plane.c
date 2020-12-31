/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_decision_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:36:06 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:33:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ip	*intersect_point_pl(t_shape *shape, t_ray *ray, double t)
{
	t_ip	*intp;

	if (!(intp = ft_calloc(sizeof(t_ip), 1)))
		return (NULL);
	intp->distance = t;
	intp->point = vadd(ray->point, vnproduct(ray->dir, t));
	intp->normal = shape->u_obj.plane.normal;
	if (vdot(intp->normal, vnproduct(ray->dir, -1)) < 0)
		intp->normal = vnproduct(intp->normal, -1);
	vunit(&intp->normal);
	intp->color = shape->color;
	return (intp);
}

t_ip	*intersection_test_pl(t_shape *shape, t_ray *ray)
{
	double	t;
	t_vec3	pc_pp;
	double	dn_dot;

	dn_dot = vdot(shape->u_obj.plane.normal, ray->dir);
	if (fabs(dn_dot) < 1e-6)
		return (NULL);
	pc_pp = vsubtract(shape->u_obj.plane.point, ray->point);
	t = vdot(pc_pp, shape->u_obj.plane.normal) / dn_dot;
	if (t < EPSILON)
		return (NULL);
	return (intersect_point_pl(shape, ray, t));
}
