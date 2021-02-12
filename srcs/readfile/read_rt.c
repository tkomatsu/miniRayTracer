/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:40:08 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/12 18:23:57 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	read_amb(char *line, t_mrt *mrt)
{
	char		*tmp;
	static int	flag;

	tmp = line;
	if (flag)
		exit_fatal(8, tmp);
	if (*line == 'A')
		line++;
	iterate_space(&line);
	mrt->scene.ambient.ratio = ft_atof(line);
	in_range(mrt->scene.ambient.ratio, 0.0, 1.0, tmp);
	while (ft_isdigit(*line) || *line == '.')
		line++;
	iterate_space(&line);
	if (!ft_isdigit(*line))
		exit_fatal(8, tmp);
	mrt->scene.ambient.color = read_col(&line);
	color_in_range(mrt->scene.ambient.color, tmp);
	flag = 1;
	return (0);
}

static int	read_res(char *line, t_mrt *mrt)
{
	char		*tmp;
	static int	flag;

	tmp = line;
	if (flag)
		exit_fatal(8, tmp);
	if (*line == 'R')
		line++;
	iterate_space(&line);
	mrt->mlx.rx = ft_atof(line);
	while (ft_isdigit(*line))
		line++;
	iterate_space(&line);
	mrt->mlx.ry = ft_atoi(line);
	if (!mrt->mlx.rx || !mrt->mlx.ry)
		exit_fatal(8, tmp);
	flag = 1;
	return (0);
}

static int	read_shapes(char *line, t_mrt *mrt)
{
	t_shape	*shape;

	shape = NULL;
	if (!ft_strncmp(line, "sp", 2))
		shape = read_sphere(line);
	else if (!(ft_strncmp(line, "pl", 2)))
		shape = read_plane(line);
	else if (!(ft_strncmp(line, "sq", 2)))
		shape = read_square(line);
	else if (!(ft_strncmp(line, "cy", 2)))
		shape = read_cylinder(line);
	else if (!(ft_strncmp(line, "tr", 2)))
		shape = read_triangle(line);
	if (!shape)
		return (-1);
	ft_lstadd_back(&(mrt->scene.shapes), ft_lstnew(shape));
	return (0);
}

static int	read_elem(char *line, t_mrt *mrt)
{
	iterate_space(&line);
	if (*line == 'R')
		return (read_res(line, mrt));
	else if (*line == 'A')
		return (read_amb(line, mrt));
	else if (*line == 'c' && *(line + 1) != 'y')
		return (read_cameras(line, mrt));
	else if (*line == 'l')
		return (read_lights(line, mrt));
	else if (!ft_strncmp(line, "sp", 2) || !ft_strncmp(line, "pl", 2) ||
			!ft_strncmp(line, "sq", 2) || !ft_strncmp(line, "cy", 2) ||
			!ft_strncmp(line, "tr", 2))
		return (read_shapes(line, mrt));
	return (0);
}

int			read_rt(char *filepath, t_mrt *mrt)
{
	int		fd;
	char	*line;
	int		ret;

	line = filepath;
	while (*line)
		line++;
	if (*line == 't' || *(line - 1) == 'r' || *(line - 2) == '.')
		exit_fatal(8, filepath);
	line = NULL;
	if ((fd = open(filepath, O_RDONLY)) < 0)
		exit_fatal(9, filepath);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		read_elem(line, mrt);
		ft_free(line);
	}
	if (ret == 0)
		read_elem(line, mrt);
	ft_free(line);
	close(fd);
	return (0);
}
