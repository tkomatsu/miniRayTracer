/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:01:20 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:06:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "libvct.h"

typedef struct	s_camera
{
	t_vec3		point;
	t_vec3		normal;
	double		fov;
	void		*img_ptr;
	int			*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
}				t_camera;

#endif
