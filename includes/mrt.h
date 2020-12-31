/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:40:23 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 21:25:23 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H

# include "light.h"
# include "libft.h"
# include <stdbool.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		rx;
	double		ry;
	t_list		*cameras;
	t_list		*current;
}				t_mlx;

typedef struct	s_scene
{
	t_list		*shapes;
	t_list		*lights;
	t_amb		ambient;
}				t_scene;

typedef struct	s_mrt
{
	t_mlx		mlx;
	t_scene		scene;
	_Bool		bmp;
}				t_mrt;

#endif
