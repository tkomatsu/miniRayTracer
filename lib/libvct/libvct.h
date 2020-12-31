/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 17:30:19 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/18 22:34:58 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVCT_H
# define LIBVCT_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_vec3 {
	double	x;
	double	y;
	double	z;
}				t_vec3;

t_vec3			vinit(double x, double y, double z);
t_vec3			*vdup(t_vec3 src);

t_vec3			vadd(t_vec3 u, t_vec3 v);
t_vec3			vsubtract(t_vec3 u, t_vec3 v);
t_vec3			vproduct(t_vec3 u, t_vec3 v);

t_vec3			vnproduct(t_vec3 v, double t);
t_vec3			vdivision(t_vec3 v, double t);

double			vlength_squared(t_vec3 vec);
double			vlength(t_vec3 vec);

double			vdot(t_vec3 u, t_vec3 v);
t_vec3			vcross(t_vec3 u, t_vec3 v);
int				vunit(t_vec3 *v);

#endif
