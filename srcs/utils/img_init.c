/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:58:04 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/29 17:42:56 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	cam_init(t_camera *cam, void *mlx_ptr, int x, int y)
{
	cam->img_ptr = mlx_new_image(mlx_ptr, x, y);
	cam->addr = (int*)mlx_get_data_addr(cam->img_ptr, &cam->bit_per_pixel,
			&cam->line_length, &cam->endian);
	return (0);
}

static int	cams_init(t_list *cams, void *mlx_ptr, int x, int y)
{
	while (cams)
	{
		cam_init(cams->content, mlx_ptr, x, y);
		cams = cams->next;
	}
	return (0);
}

int			img_init(t_mlx *mlx, _Bool bmp)
{
	int		x;
	int		y;

	ft_putstr_fd("images initializing...\n", 1);
	mlx->mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx->mlx_ptr, &x, &y);
	if (x < (int)mlx->rx)
		mlx->rx = x;
	else
		x = (int)mlx->rx;
	if (y < (int)mlx->ry)
		mlx->ry = y;
	else
		y = (int)mlx->ry;
	if (!bmp)
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, x, y, "miniRT");
	cams_init(mlx->cameras, mlx->mlx_ptr, x, y);
	return (0);
}
