/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:46:11 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 22:12:27 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*create_file_name(char *name)
{
	char		*bmpname;
	int			i;
	int			j;
	static int	n;
	char		*n_str;

	if (!(bmpname = ft_calloc(sizeof(char), ft_strlen(name) + 9 + BMP_MAX)))
		exit_fatal(12, "creating_file_name");
	ft_strcat(bmpname, "images/");
	i = 0;
	while (name[i])
		i++;
	while (i && name[i] != '/')
		i--;
	if (name[i] == '/')
		i++;
	j = 7;
	while (name[i] && name[i] != '.')
		bmpname[j++] = name[i++];
	n += 1;
	n_str = ft_itoa(n);
	ft_strcat(bmpname, n_str);
	ft_strcat(bmpname, ".bmp");
	free(n_str);
	return (bmpname);
}

int		create_file(char *name)
{
	int			fd;
	char		*bmpname;

	bmpname = create_file_name(name);
	ft_putstr_fd("[USAGE] open ", 1);
	ft_putendl_fd(bmpname, 1);
	if ((!((fd = open(bmpname, O_WRONLY | O_CREAT | O_TRUNC,
							S_IRUSR | S_IWUSR)) > 0)))
		exit_fatal(9, "Creating bmp file");
	ft_free(bmpname);
	return (fd);
}

int		bmp_export(t_mlx mlx, t_camera *camera, char *name)
{
	int				fd;
	t_fileheader	header;
	t_dibheader		dib;

	fd = create_file(name);
	set_bmpheader(mlx, &header, &dib);
	write_bmpheader(fd, header, dib);
	write_bmpdata(fd, mlx, *camera);
	close(fd);
	return (0);
}

void	export_bmp(t_mrt *mrt, char *name)
{
	t_list		*cams;

	cams = mrt->mlx.cameras;
	while (cams)
	{
		bmp_export(mrt->mlx, cams->content, name);
		cams = cams->next;
	}
	ft_free_mrt(mrt);
	exit(0);
}
