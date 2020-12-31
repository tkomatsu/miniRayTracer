/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 14:03:18 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/29 13:07:02 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	cam_to_win(t_camera *cam, t_mlx mlx)
{
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, cam->img_ptr, 0, 0);
	return (0);
}

int			show_rt(t_mrt *mrt)
{
	t_list	*cams;

	cams = mrt->mlx.current;
	if (cams)
		cam_to_win(cams->content, mrt->mlx);
	return (0);
}
