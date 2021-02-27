/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:20:50 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/02/27 11:21:20 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_hundle(int keycode, t_mrt *mrt)
{
	if (keycode == ESC_KEY)
	{
		ft_free_mrt(mrt);
		ft_putstr_fd("\033[39m", 1);
		exit(0);
	}
	else if (keycode == N_KEY)
	{
		if (!mrt->mlx.cameras)
			return (0);
		if (mrt->mlx.current->next)
			mrt->mlx.current = mrt->mlx.current->next;
		else
			mrt->mlx.current = mrt->mlx.cameras;
		show_rt(mrt);
	}
	return (0);
}

int	close_win(t_mrt *mrt)
{
	ft_free_mrt(mrt);
	ft_putstr_fd("\033[39m", 1);
	exit(0);
	return (0);
}

#ifdef LINUX

int	loop_hook(t_mrt *mrt)
{
	mlx_key_hook(mrt->mlx.win_ptr, key_hundle, mrt);
	mlx_hook(mrt->mlx.win_ptr, CLIENTMESSAGE, STRUCTURENOTIFYMASK,
				close_win, mrt);
	mlx_hook(mrt->mlx.win_ptr, FOCUSIN, FOCUSCHANGEMASK, show_rt, mrt);
	mlx_loop(mrt->mlx.mlx_ptr);
	return (0);
}

#else

int	loop_hook(t_mrt *mrt)
{
	mlx_key_hook(mrt->mlx.win_ptr, key_hundle, mrt);
	mlx_hook(mrt->mlx.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
				close_win, mrt);
	mlx_hook(mrt->mlx.win_ptr, FOCUSIN, FOCUSCHANGEMASK, show_rt, mrt);
	mlx_loop(mrt->mlx.mlx_ptr);
	return (0);
}

#endif
