/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:48:40 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/29 17:41:46 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	arg_check(int ac, char **av, t_mrt *mrt)
{
	if (ac < 2 || 3 < ac)
		exit_fatal(22, av[0]);
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save"))
			exit_fatal(22, av[0]);
		else
			mrt->bmp = true;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mrt	*mrt;

	ft_putstr_fd("\033[36m", 1);
	if (!(mrt = ft_calloc(sizeof(t_mrt), 1)))
		exit(0);
	arg_check(ac, av, mrt);
	read_rt(av[1], mrt);
	img_init(&mrt->mlx, mrt->bmp);
	raytrace(mrt);
	if (mrt->bmp)
		export_bmp(mrt, av[1]);
	ft_putendl_fd("showing camera images ...", 1);
	show_rt(mrt);
	ft_putendl_fd("press 'N' key to switch images\033[39m", 1);
	loop_hook(mrt);
	ft_free_mrt(mrt);
	return (0);
}
