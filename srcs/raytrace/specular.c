/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:03:36 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/12 21:23:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SHININESS 20.0
#define SPECULAR 0.2

double	specular_reflect(t_vec3 *ref_l, t_vec3 *rev_r, double lc)
{
	double	res;
	double	vr_dot;

	vr_dot = fmax(fmin(vdot(*ref_l, *rev_r), 1.0), 0.0);
	res = SPECULAR * lc * pow(vr_dot, SHININESS);
	return (res);
}

int		multiply_specular(t_light *light, t_ip *intp, t_ray *ray, t_color *col)
{
	double	ratio;
	double	nl_dot;
	t_vec3	light_dir;
	t_vec3	rev_r;
	t_vec3	ref_l;

	ratio = light->ratio /
		(light->color.r + light->color.g + light->color.b);
	light_dir = vsubtract(light->point, intp->point);
	vunit(&light_dir);
	nl_dot = fmax(fmin(vdot(light_dir, intp->normal), 1.0), 0.0);
	if (nl_dot > 0)
	{
		ref_l = vsubtract(vnproduct(intp->normal, 2 * nl_dot), light_dir);
		vunit(&ref_l);
		rev_r = vnproduct(ray->dir, -1);
		vunit(&rev_r);
		col->r += specular_reflect(&ref_l, &rev_r, light->color.r * ratio);
		col->g += specular_reflect(&ref_l, &rev_r, light->color.g * ratio);
		col->b += specular_reflect(&ref_l, &rev_r, light->color.b * ratio);
	}
	col->r = fmin(col->r, 1.0);
	col->g = fmin(col->g, 1.0);
	col->b = fmin(col->b, 1.0);
	return (0);
}
