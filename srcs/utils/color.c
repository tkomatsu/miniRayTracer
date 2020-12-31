/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:05:23 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 18:37:30 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	create_color(double r, double g, double b)
{
	t_color col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

int		colortoi(t_color *col)
{
	int	ir;
	int	ig;
	int	ib;

	ir = (int)(255.999 * col->r);
	ig = (int)(255.999 * col->g);
	ib = (int)(255.999 * col->b);
	return (ir << 16 | ig << 8 | ib);
}
