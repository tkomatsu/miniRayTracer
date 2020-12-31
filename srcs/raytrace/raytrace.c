/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:44:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/31 10:30:34 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	cam_up(t_vec3 cam_right, t_vec3 vup)
{
	t_vec3	result;

	if (cam_right.x == 0 && cam_right.y == 0)
		if (cam_right.z == 1)
			result = vinit(1, 0, 0);
		else
			result = vinit(-1, 0, 0);
	else
		result = vcross(cam_right, vup);
	return (result);
}

t_ray	*set_ray(t_camera *cam, int i, int j, t_mlx mlx)
{
	const t_vec3	vup = {0, 0, 1};
	t_vec3			cam_base[3];
	t_vec3			uvw[3];
	double			wh[2];
	t_ray			*ray;

	cam_base[1] = cam->normal;
	vunit(cam_base + 1);
	cam_base[0] = cam_up(cam_base[1], vup);
	cam_base[2] = vcross(cam_base[0], cam_base[1]);
	wh[0] = tan(cam->fov * (M_PI / 180) / 2.0);
	wh[1] = mlx.ry / mlx.rx * wh[0];
	uvw[0] = vnproduct(vnproduct(cam_base[0], 2 * wh[0]), i / mlx.rx);
	uvw[1] = vnproduct(vnproduct(cam_base[2], -2 * wh[1]), j / mlx.ry);
	cam_base[0] = vnproduct(cam_base[0], wh[0]);
	cam_base[2] = vnproduct(cam_base[2], -1 * wh[1]);
	uvw[2] = vsubtract(vsubtract(
				vadd(cam->point, cam->normal), cam_base[0]), cam_base[2]);
	if (!(ray = ft_calloc(sizeof(t_ray), 1)))
		return (NULL);
	ray->point = cam->point;
	ray->dir = vsubtract(vadd(vadd(uvw[0], uvw[1]), uvw[2]), ray->point);
	vunit(&ray->dir);
	return (ray);
}

int		raytrace_cam(t_camera *cam, t_mrt *mrt)
{
	int		x;
	int		y;
	t_color	color;
	t_ray	*ray;

	x = 0;
	y = 0;
	if (!cam)
		return (EXIT_FAILURE);
	while (x < mrt->mlx.rx)
	{
		while (y < mrt->mlx.ry)
		{
			color = create_color(0.1, 0.1, 0.1);
			ray = set_ray(cam, x, y, mrt->mlx);
			calc_ray(ray, mrt, &color);
			ft_mlx_pixel_put(cam, x, y, colortoi(&color));
			ft_free(ray);
			y++;
		}
		y = 0;
		x++;
	}
	return (EXIT_SUCCESS);
}

int		raytrace(t_mrt *mrt)
{
	t_list	*cams;

	ft_putstr_fd("ray tracing....\n", 1);
	cams = mrt->mlx.cameras;
	if (!cams)
		return (EXIT_FAILURE);
	while (cams)
	{
		raytrace_cam(cams->content, mrt);
		cams = cams->next;
	}
	return (EXIT_SUCCESS);
}
