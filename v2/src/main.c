/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:49:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 23:06:48 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractol	*f;

	if (argc != 2)
		return (die("usage: ./fractol [fractol option]"));
	// Match what was passed as parameter and compare it to given fractol definitions
	f = fractol_match(argv[1]);
	if (f->name == NULL)
		return (die("error: invalid fractal name"));
	// Initializes our environment and sets the initial state of everything
	if ((mlx = init(f)) == NULL)
		return (die("error: mlx couldn't initialize properly"));
	reset_viewport(mlx);
	// First set a thread for each part of the screen (1/8th of the screen per thread),
	// then set color for each pixel (based on fractal formula)
	render(mlx);
	// CONTROLS
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	// 1L << 2 = 8
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	// 1L << 3 = 16
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	// 1L << 6 = 64
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	// LOOP FOR CONTROL INPUT
	mlx_loop(mlx->mlx);
	return (0);
}
