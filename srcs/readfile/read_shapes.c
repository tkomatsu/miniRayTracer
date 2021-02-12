/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:23:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/12 22:03:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shape	*read_sphere(char *line)
{
	t_shape	*shape;
	char	*tmp;

	tmp = line;
	shape = safe_calloc(sizeof(t_shape), 1);
	line += 2;
	shape->type = SP;
	iterate_space(&line);
	shape->u_obj.sphere.point = read_vec(&line);
	iterate_space(&line);
	shape->u_obj.sphere.radius = ft_atof(line) / 2.0;
	while (ft_isdigit(*line) || *line == '-' || *line == '.')
		line++;
	iterate_space(&line);
	shape->color = read_col(&line);
	color_in_range(shape->color, tmp);
	if (*line)
		exit_fatal(8, line);
	return (shape);
}

t_shape	*read_plane(char *line)
{
	t_shape	*shape;
	char	*tmp;

	tmp = line;
	shape = safe_calloc(sizeof(t_shape), 1);
	line += 2;
	shape->type = PL;
	iterate_space(&line);
	shape->u_obj.plane.point = read_vec(&line);
	while (ft_isspace(*line))
		line++;
	shape->u_obj.plane.normal = read_vec(&line);
	vec_in_range(shape->u_obj.plane.normal, tmp);
	iterate_space(&line);
	shape->color = read_col(&line);
	color_in_range(shape->color, tmp);
	if (*line)
		exit_fatal(8, line);
	return (shape);
}

t_shape	*read_square(char *line)
{
	t_shape	*shape;
	char	*tmp;

	tmp = line;
	shape = safe_calloc(sizeof(t_shape), 1);
	line += 2;
	shape->type = SQ;
	while (ft_isspace(*line))
		line++;
	shape->u_obj.square.point = read_vec(&line);
	iterate_space(&line);
	shape->u_obj.square.normal = read_vec(&line);
	vec_in_range(shape->u_obj.square.normal, tmp);
	while (ft_isspace(*line))
		line++;
	shape->u_obj.square.size = ft_atof(line) / 2.0;
	while (ft_isdigit(*line) || *line == '.' || *line == '-')
		line++;
	iterate_space(&line);
	shape->color = read_col(&line);
	color_in_range(shape->color, tmp);
	if (*line)
		exit_fatal(8, line);
	return (shape);
}

t_shape	*read_cylinder(char *line)
{
	t_shape	*shape;
	char	*tmp;

	tmp = line;
	shape = safe_calloc(sizeof(t_shape), 1);
	line += 2;
	shape->type = CY;
	iterate_space(&line);
	shape->u_obj.cylinder.point = read_vec(&line);
	iterate_space(&line);
	shape->u_obj.cylinder.normal = read_vec(&line);
	vec_in_range(shape->u_obj.cylinder.normal, tmp);
	iterate_space(&line);
	shape->u_obj.cylinder.radius = ft_atof(line) / 2.0;
	while (ft_isdigit(*line) || *line == '.' || *line == '-')
		line++;
	iterate_space(&line);
	shape->u_obj.cylinder.height = ft_atof(line);
	while (ft_isdigit(*line) || *line == '.' || *line == '-')
		line++;
	shape->color = read_col(&line);
	color_in_range(shape->color, tmp);
	if (*line)
		exit_fatal(8, line);
	return (shape);
}

t_shape	*read_triangle(char *line)
{
	t_shape	*shape;
	char	*tmp;

	tmp = line;
	shape = safe_calloc(sizeof(t_shape), 1);
	line += 2;
	shape->type = TR;
	iterate_space(&line);
	shape->u_obj.triangle.first = read_vec(&line);
	iterate_space(&line);
	shape->u_obj.triangle.second = read_vec(&line);
	iterate_space(&line);
	shape->u_obj.triangle.third = read_vec(&line);
	iterate_space(&line);
	shape->color = read_col(&line);
	color_in_range(shape->color, tmp);
	if (*line)
		exit_fatal(8, line);
	return (shape);
}
