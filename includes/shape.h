/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:36:35 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:09:00 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "libvct.h"
# include "color.h"

typedef struct			s_spparam
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;
	double	t1;
	double	t2;
}						t_spparam;

typedef struct			s_sphere
{
	t_vec3	point;
	double	radius;
}						t_sphere;

typedef struct			s_plane
{
	t_vec3	point;
	t_vec3	normal;
}						t_plane;

typedef struct			s_square
{
	t_vec3	point;
	t_vec3	normal;
	double	size;
}						t_square;

typedef struct			s_cylinder
{
	t_vec3	point;
	t_vec3	normal;
	double	radius;
	double	height;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec3	first;
	t_vec3	second;
	t_vec3	third;
}						t_triangle;

enum					e_shapetype
{ SP, PL, SQ, CY, TR };

typedef struct			s_shape
{
	enum e_shapetype	type;
	union
	{
		t_sphere		sphere;
		t_plane			plane;
		t_square		square;
		t_cylinder		cylinder;
		t_triangle		triangle;
	}					u_obj;
	t_color				color;
}						t_shape;

#endif
