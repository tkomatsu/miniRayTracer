/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:42:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 22:13:36 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_cameras(t_list *cameras, void *mlx_ptr)
{
	t_camera	*cam;
	t_list		*tmp;

	while (cameras)
	{
		cam = (t_camera*)cameras->content;
		mlx_destroy_image(mlx_ptr, cam->img_ptr);
		ft_free(cameras->content);
		tmp = cameras->next;
		ft_free(cameras);
		cameras = tmp;
	}
}

#ifdef LINUX

void	ft_free_mrt(t_mrt *mrt)
{
	ft_lstclear(&mrt->scene.shapes, ft_free);
	ft_lstclear(&mrt->scene.lights, ft_free);
	if (!mrt->bmp)
		mlx_destroy_window(mrt->mlx.mlx_ptr, mrt->mlx.win_ptr);
	ft_free_cameras(mrt->mlx.cameras, mrt->mlx.mlx_ptr);
	mlx_destroy_display(mrt->mlx.mlx_ptr);
	ft_free(mrt->mlx.mlx_ptr);
	ft_free(mrt);
}

#else

void	ft_free_mrt(t_mrt *mrt)
{
	ft_lstclear(&mrt->scene.shapes, ft_free);
	ft_lstclear(&mrt->scene.lights, ft_free);
	if (!mrt->bmp)
		mlx_destroy_window(mrt->mlx.mlx_ptr, mrt->mlx.win_ptr);
	ft_free_cameras(mrt->mlx.cameras, mrt->mlx.mlx_ptr);
	ft_free(mrt);
}

#endif
