/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:18:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/12 22:13:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	iterate_space(char **line)
{
	while (ft_isspace(**line))
		*line += 1;
}

t_color	read_col(char **line)
{
	t_color	col;
	char	*s;

	s = *line;
	iterate_space(&s);
	col.r = ft_atof(s) / 255.0;
	while (*s != ',')
		s++;
	if (*s != ',')
		exit_fatal(8, *line);
	s++;
	col.g = ft_atof(s) / 255.0;
	while (*s != ',')
		s++;
	if (*s != ',')
		exit_fatal(8, *line);
	s++;
	if (!ft_isdigit(*s))
		exit_fatal(8, *line);
	col.b = ft_atof(s) / 255.0;
	while (ft_isdigit(*s) || *s == '.' || *s == '-')
		s++;
	iterate_space(&s);
	*line = s;
	return (col);
}

t_vec3	read_vec(char **line)
{
	t_vec3	v;
	char	*s;

	s = *line;
	iterate_space(line);
	v.x = ft_atof(s);
	while (*s != ',')
		s++;
	if (*s != ',')
		exit_fatal(8, *line);
	s++;
	v.y = ft_atof(s);
	while (*s != ',')
		s++;
	if (*s != ',')
		exit_fatal(8, *line);
	s++;
	if (!ft_isdigit(*s) && !(*s == '-'))
		exit_fatal(8, *line);
	v.z = ft_atof(s);
	while (ft_isdigit(*s) || *s == '.' || *s == '-')
		s++;
	iterate_space(&s);
	*line = s;
	return (v);
}

int		read_lights(char *line, t_mrt *mrt)
{
	t_light	*light;
	char	*tmp;

	tmp = line;
	light = safe_calloc(sizeof(t_light), 1);
	if (*line == 'l')
		line++;
	light->point = read_vec(&line);
	iterate_space(&line);
	light->ratio = ft_atof(line);
	in_range(light->ratio, 0.0, 1.0, tmp);
	while (ft_isdigit(*line) || *line == '.' || *line == '-')
		line++;
	iterate_space(&line);
	light->color = read_col(&line);
	color_in_range(light->color, tmp);
	if (*line)
		exit_fatal(8, line);
	ft_lstadd_back(&(mrt->scene.lights), ft_lstnew(light));
	return (0);
}

int		read_cameras(char *line, t_mrt *mrt)
{
	t_camera	*cam;
	char		*tmp;

	tmp = line;
	cam = safe_calloc(sizeof(t_camera), 1);
	if (*line == 'c')
		line++;
	iterate_space(&line);
	cam->point = read_vec(&line);
	iterate_space(&line);
	cam->normal = read_vec(&line);
	vec_in_range(cam->normal, tmp);
	iterate_space(&line);
	cam->fov = ft_atof(line);
	in_range(cam->fov, 0, 180, tmp);
	while (ft_isdigit(*line) || *line == '.' || *line == '-')
		line++;
	iterate_space(&line);
	if (*line)
		exit_fatal(8, line);
	cam->img_ptr = NULL;
	ft_lstadd_back(&(mrt->mlx.cameras), ft_lstnew(cam));
	if (!mrt->mlx.current)
		mrt->mlx.current = mrt->mlx.cameras;
	return (0);
}
