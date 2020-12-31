/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:59:06 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/31 10:35:15 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvct.h"

t_vec3	vadd(t_vec3 u, t_vec3 v)
{
	t_vec3	ans;

	ans.x = u.x + v.x;
	ans.y = u.y + v.y;
	ans.z = u.z + v.z;
	return (ans);
}

t_vec3	vsubtract(t_vec3 u, t_vec3 v)
{
	t_vec3	ans;

	ans.x = u.x - v.x;
	ans.y = u.y - v.y;
	ans.z = u.z - v.z;
	return (ans);
}

t_vec3	vproduct(t_vec3 u, t_vec3 v)
{
	t_vec3	ans;

	ans.x = u.x * v.x;
	ans.y = u.y * v.y;
	ans.z = u.z * v.z;
	return (ans);
}

t_vec3	vnproduct(t_vec3 v, double t)
{
	t_vec3	ans;

	ans.x = t * v.x;
	ans.y = t * v.y;
	ans.z = t * v.z;
	return (ans);
}

t_vec3	vdivision(t_vec3 v, double t)
{
	return (vnproduct(v, 1.0 / t));
}
