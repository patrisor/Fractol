/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:49:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 19:09:11 by patrisor         ###   ########.fr       */
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

#include <stdio.h>
int		main(int argc, char **argv)
{
	int			code;
	t_mlx		*mlx;
	
	if (argc < 2 || argc > 3)
		return (die("usage: ./fractol [fractal] [fractal]"));
	code = (argc == 3) ? fork() : 0;
	if ((mlx = init_mlx(init_fractol(((code == 0) ? argv[1] : argv[2])))) == NULL)
		return (die("error: first mlx couldn't initialize properly"));	
	put_instructions(code);
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
