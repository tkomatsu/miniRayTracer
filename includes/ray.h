/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:30:33 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:26:19 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "libvct.h"
# include "color.h"

typedef struct	s_ip
{
	double	distance;
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}				t_ip;

typedef struct	s_ray
{
	t_vec3	point;
	t_vec3	dir;
}				t_ray;

#endif
