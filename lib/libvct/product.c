/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:16:04 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/31 10:35:03 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvct.h"

double	vdot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	vcross(t_vec3 u, t_vec3 v)
{
	t_vec3	ans;

	ans.x = u.y * v.z - u.z * v.y;
	ans.y = u.z * v.x - u.x * v.z;
	ans.z = u.x * v.y - u.y * v.x;
	return (ans);
}
