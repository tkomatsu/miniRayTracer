/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:14:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 18:36:47 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_bmpheader(t_mlx mlx, t_fileheader *header, t_dibheader *dib)
{
	header->file_type[0] = 0x42;
	header->file_type[1] = 0x4D;
	header->file_size = ((int)mlx.rx * (int)mlx.ry * 4) + 54;
	header->reserved = 0x00000000;
	header->pixel_data_offset = 0x36;
	dib->header_size = 40;
	dib->image_width = (int)mlx.rx;
	dib->image_height = -1 * (int)mlx.ry;
	dib->planes = 1;
	dib->bit_per_pixel = 32;
	dib->compression = 0;
	dib->image_size = (int)mlx.rx * (int)mlx.ry * 4;
	dib->x_pixels_per_meter = 2835;
	dib->y_pixels_per_meter = 2835;
	dib->total_colors = 0;
	dib->important_colors = 0;
}

void	write_bmpheader(int fd, t_fileheader header, t_dibheader dib)
{
	write(fd, &header.file_type, 2);
	write(fd, &header.file_size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.pixel_data_offset, 4);
	write(fd, &dib.header_size, 4);
	write(fd, &dib.image_width, 4);
	write(fd, &dib.image_height, 4);
	write(fd, &dib.planes, 2);
	write(fd, &dib.bit_per_pixel, 2);
	write(fd, &dib.compression, 4);
	write(fd, &dib.image_size, 4);
	write(fd, &dib.x_pixels_per_meter, 4);
	write(fd, &dib.y_pixels_per_meter, 4);
	write(fd, &dib.total_colors, 4);
	write(fd, &dib.important_colors, 4);
}

void	write_bmpdata(int fd, t_mlx mlx, t_camera camera)
{
	unsigned char	*pixel_array;
	int				image_size;
	int				i;
	int				j;

	image_size = (int)mlx.rx * (int)mlx.ry * 4;
	if (!(pixel_array = ft_calloc(sizeof(unsigned char), image_size)))
		return ;
	i = 0;
	j = 0;
	while (j < image_size)
	{
		if (i % (camera.line_length / 4) < (int)mlx.rx)
		{
			pixel_array[j++] = camera.addr[i] & 255;
			pixel_array[j++] = (camera.addr[i] & 255 << 8) >> 8;
			pixel_array[j++] = (camera.addr[i] & 255 << 16) >> 16;
			pixel_array[j++] = 0;
		}
		i++;
	}
	write(fd, pixel_array, image_size);
	ft_free(pixel_array);
}
