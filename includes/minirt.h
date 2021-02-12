/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:12:26 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/12 21:20:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>

# include "mlx.h"
# include "libft.h"
# include "libvct.h"
# include "keycode.h"
# include "color.h"
# include "shape.h"
# include "light.h"
# include "camera.h"
# include "ray.h"
# include "mrt.h"
# include "bmp.h"

# define INF	5000.0
# define EPSILON 0.000001

/*
** *****************************************************************************
** read rt files
** *****************************************************************************
*/

int		read_rt(char *filepath, t_mrt *mrt);

void	iterate_space(char **line);
t_vec3	read_vec(char **line);
t_color	read_col(char **line);

int		read_cameras(char *line, t_mrt *mrt);
int		read_lights(char *line, t_mrt *mrt);

t_shape	*read_sphere(char *line);
t_shape	*read_plane(char *line);
t_shape	*read_square(char *line);
t_shape	*read_cylinder(char *line);
t_shape	*read_triangle(char *line);

/*
** *****************************************************************************
** management
** *****************************************************************************
*/

int		img_init(t_mlx *mlx, _Bool bmp);
int		show_rt(t_mrt *mrt);
int		loop_hook(t_mrt *mrt);
void	export_bmp(t_mrt *mrt, char *name);

/*
** *****************************************************************************
** raytracing functions
** *****************************************************************************
*/

int		raytrace(t_mrt *mrt);

t_color	amb_init(t_amb ambient, t_ip *intp);
t_ray	*ray_init(t_camera *cam, int i, int j, t_mlx mlx);

int		raytrace_cam(t_camera *cam, t_mrt *mrt);
t_vec3	vertical_unitvec(t_vec3 *n);

int		calc_ray(t_ray *eye_ray, t_mrt *mrt, t_color *col);
t_ip	*get_nearest_point(t_list *shapes, t_ray *ray);

t_ip	*intersection_test_sp(t_shape *shape, t_ray *ray);
t_ip	*intersection_test_pl(t_shape *shape, t_ray *ray);
t_ip	*intersection_test_sq(t_shape *shape, t_ray *ray);
t_ip	*intersection_test_tr(t_shape *shape, t_ray *ray);
t_ip	*intersection_test_cy(t_shape *shape, t_ray *ray);

int		multiply_specular(t_light *light, t_ip *intp, t_ray *ray, t_color *col);
int		multiply_diffuse(t_light *light, t_ip *intp, t_color *out_col);

/*
** *****************************************************************************
** utility functions
** *****************************************************************************
*/

void	ft_mlx_pixel_put(t_camera *data, int x, int y, int color);

void	in_range(double num, double min, double max, char *str);
void	vec_in_range(t_vec3 v, char *str);
void	color_in_range(t_color c, char *str);

t_color	create_color(double r, double g, double b);
int		colortoi(t_color *col);

void	exit_fatal(int num, char *message);
void	*safe_calloc(size_t count, size_t size);
void	ft_free_mrt(t_mrt *mrt);

int		bmp_export(t_mlx mlx, t_camera *camera, char *name);
void	set_bmpheader(t_mlx mlx, t_fileheader *header, t_dibheader *dib);
void	write_bmpheader(int fd, t_fileheader header, t_dibheader dib);
void	write_bmpdata(int fd, t_mlx mlx, t_camera camera);

#endif
