/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 16:17:52 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 22:33:17 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# define HEADERSIZE 54
# define PALLETSIZE 1024
# define BMP_MAX 3

typedef struct	s_fileheader
{
	unsigned char	file_type[2];
	unsigned int	file_size;
	unsigned int	reserved;
	unsigned int	pixel_data_offset;
}				t_fileheader;

typedef struct	s_dibheader
{
	unsigned int	header_size;
	int				image_width;
	int				image_height;
	unsigned short	planes;
	unsigned short	bit_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	x_pixels_per_meter;
	unsigned int	y_pixels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}				t_dibheader;

#endif
