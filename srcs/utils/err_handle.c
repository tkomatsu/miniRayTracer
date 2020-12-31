/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:20:04 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 20:34:59 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_fatal(int num, char *message)
{
	errno = num;
	ft_putstr_fd("\033[031mError\n", 2);
	perror(message);
	exit(EXIT_FAILURE);
}

void	*safe_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		exit_fatal(12, "FATAL ERROR");
	return (ptr);
}

void	in_range(double num, double min, double max, char *str)
{
	if (num < min || max < num)
		exit_fatal(33, str);
}

void	vec_in_range(t_vec3 v, char *str)
{
	in_range(v.x, -1.0, 1.0, str);
	in_range(v.y, -1.0, 1.0, str);
	in_range(v.z, -1.0, 1.0, str);
}

void	color_in_range(t_color c, char *str)
{
	in_range(c.r, 0.0, 1.0, str);
	in_range(c.g, 0.0, 1.0, str);
	in_range(c.b, 0.0, 1.0, str);
}
