/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:04:29 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:46:17 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	diffuse_reflect(t_vec3 vl, t_vec3 vn, double lc, double sc)
{
	double	res;
	double	nl_dot;

	nl_dot = fmax(fmin(vdot(vl, vn), 1.0), 0.0);
	res = nl_dot * lc * sc;
	return (res);
}

int		multiply_diffuse(t_light *light, t_ip *intp, t_color *out_col)
{
	t_vec3	inc;

	inc = vsubtract(light->point, intp->point);
	vunit(&inc);
	out_col->r += diffuse_reflect(inc, intp->normal,
								light->color.r, intp->color.r);
	out_col->g += diffuse_reflect(inc, intp->normal,
								light->color.g, intp->color.g);
	out_col->b += diffuse_reflect(inc, intp->normal,
								light->color.b, intp->color.b);
	out_col->r = fmin(out_col->r, 1.0);
	out_col->g = fmin(out_col->g, 1.0);
	out_col->b = fmin(out_col->b, 1.0);
	return (0);
}
