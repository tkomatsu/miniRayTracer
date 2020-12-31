/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 08:48:34 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:29:24 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ip	*intersection_test(t_shape *shape, t_ray *ray)
{
	if (shape->type == SP)
		return (intersection_test_sp(shape, ray));
	else if (shape->type == PL)
		return (intersection_test_pl(shape, ray));
	else if (shape->type == SQ)
		return (intersection_test_sq(shape, ray));
	else if (shape->type == TR)
		return (intersection_test_tr(shape, ray));
	else if (shape->type == CY)
		return (intersection_test_cy(shape, ray));
	return (NULL);
}

t_ip	*get_nearest_point(t_list *shapes, t_ray *ray)
{
	t_ip	*nearest;
	t_ip	*intp;

	if (!(nearest = ft_calloc(sizeof(t_ip), 1)))
		return (NULL);
	nearest->distance = INF;
	while (shapes)
	{
		intp = intersection_test(shapes->content, ray);
		if (intp && EPSILON < nearest->distance - intp->distance)
		{
			ft_free(nearest);
			nearest = intp;
		}
		else
			ft_free(intp);
		shapes = shapes->next;
	}
	if (nearest->distance < INF)
		return (nearest);
	ft_free(nearest);
	return (NULL);
}
