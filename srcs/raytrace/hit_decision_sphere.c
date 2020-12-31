/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_decision_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 13:29:06 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:31:39 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ip	*intersection_point(t_shape *shape, t_ray *ray, double t)
{
	t_ip	*out;

	if (!(out = ft_calloc(sizeof(t_ip), 1)))
		return (NULL);
	out->distance = t;
	out->point = vadd(ray->point, vnproduct(ray->dir, t));
	out->normal = vsubtract(out->point, shape->u_obj.sphere.point);
	vunit(&out->normal);
	out->color = shape->color;
	return (out);
}

int		calc_t_param(t_spparam *param)
{
	if (param->d == 0)
		param->t = -1 * param->b / (2 * param->a);
	else if (param->d > 0)
	{
		param->t1 = (-1 * param->b + sqrt(param->d)) / (2 * param->a);
		param->t2 = (-1 * param->b - sqrt(param->d)) / (2 * param->a);
		if (param->t1 > 0)
			param->t = param->t1;
		if (param->t2 > 0 && param->t2 < param->t)
			param->t = param->t2;
	}
	return (0);
}

t_ip	*intersection_test_sp(t_shape *shape, t_ray *ray)
{
	t_spparam		param;
	t_vec3			pe_pc;

	pe_pc = vsubtract(ray->point, shape->u_obj.sphere.point);
	param.a = vdot(ray->dir, ray->dir);
	param.b = 2 * vdot(ray->dir, pe_pc);
	param.c = vdot(pe_pc, pe_pc) - pow(shape->u_obj.sphere.radius, 2);
	param.d = pow(param.b, 2) - 4 * param.a * param.c;
	param.t = -1.0;
	param.t1 = 0.0;
	param.t2 = 0.0;
	calc_t_param(&param);
	if (param.t > 0)
		return (intersection_point(shape, ray, param.t));
	return (NULL);
}
