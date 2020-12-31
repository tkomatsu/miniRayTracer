/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:21:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/22 22:43:12 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvct.h"

t_vec3	vinit(double elem0, double elem1, double elem2)
{
	t_vec3	vec;

	vec.x = elem0;
	vec.y = elem1;
	vec.z = elem2;
	return (vec);
}

t_vec3	*vdup(t_vec3 src)
{
	t_vec3	*vec;

	if (!(vec = (t_vec3*)malloc(sizeof(t_vec3))))
		return (NULL);
	vec->x = src.x;
	vec->y = src.y;
	vec->z = src.z;
	return (vec);
}
