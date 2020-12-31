/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:53:38 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/23 16:07:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "libvct.h"
# include "color.h"

typedef struct	s_light
{
	t_vec3		point;
	double		ratio;
	t_color		color;
}				t_light;

typedef struct	s_amb
{
	t_color		color;
	double		ratio;
}				t_amb;

#endif
