/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 08:47:22 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/12 21:19:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	amb_init(t_amb ambient, t_ip *intp)
{
	t_color	col;

	col.r = ambient.color.r * ambient.ratio * intp->color.r;
	col.g = ambient.color.g * ambient.ratio * intp->color.g;
	col.b = ambient.color.b * ambient.ratio * intp->color.b;
	return (col);
}

t_ray	get_sray(t_ip *intp, void *light)
{
	t_light	*l;
	t_ray	ray;
	t_vec3	vl;

	l = (t_light*)light;
	vl = vsubtract(l->point, intp->point);
	vunit(&vl);
	ray.point = vadd(vnproduct(vl, EPSILON), intp->point);
	ray.dir = vl;
	return (ray);
}

int		distance_comp(t_vec3 intp, t_ip *shadowp, void *light)
{
	t_light	*l;
	t_vec3	i_l;
	t_vec3	i_s;

	l = (t_light*)light;
	i_l = vsubtract(l->point, intp);
	i_s = vsubtract(shadowp->point, intp);
	if (vlength(i_l) - vlength(i_s) > EPSILON)
		return (0);
	return (1);
}

int		calc_ray(t_ray *ray, t_mrt *mrt, t_color *col)
{
	t_ip	*intp;
	t_list	*lights;
	t_ray	shadow_ray;
	t_ip	*sp;

	lights = mrt->scene.lights;
	intp = get_nearest_point(mrt->scene.shapes, ray);
	if (intp)
	{
		*col = amb_init(mrt->scene.ambient, intp);
		while (lights)
		{
			shadow_ray = get_sray(intp, lights->content);
			sp = get_nearest_point(mrt->scene.shapes, &shadow_ray);
			if (!sp || distance_comp(shadow_ray.point, sp, lights->content))
			{
				multiply_diffuse(lights->content, intp, col);
				multiply_specular(lights->content, intp, ray, col);
			}
			ft_free(sp);
			lights = lights->next;
		}
	}
	ft_free(intp);
	return (0);
}
