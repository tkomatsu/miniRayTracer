/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:35:23 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/14 18:38:03 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvct.h"

double	vlength_squared(t_vec3 vec)
{
	return (vdot(vec, vec));
}

double	vlength(t_vec3 vec)
{
	return (sqrt(vdot(vec, vec)));
}

int		vunit(t_vec3 *v)
{
	double mod;

	mod = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x = v->x / mod;
	v->y = v->y / mod;
	v->z = v->z / mod;
	return (0);
}
