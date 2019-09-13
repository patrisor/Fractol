/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:49:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/13 02:09:42 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

char	*print_usage(void)
{
	return ("usage: ./fractol [option] [option]\n\n \
	OPTIONS:\n\t- mandelbrot\n\t- bibrot\n\t- tribrot\n\t- julia \
	\n\t- trijulia\n\t- quadjulia\n\t- burningship\n\t- excalibur \
	\n\t- enigma\n");
}

int		main(int ac, char **av)
{
	int			c;
	t_mlx		*mlx;

	if (ac < 2 || ac > 3)
		return (die(print_usage()));
	c = (ac == 3) ? fork() : 0;
	if ((mlx = init_mlx(init_fractol(((c == 0) ? av[1] : av[2])))) == NULL)
		return (die("error: first mlx couldn't initialize properly"));
	put_instructions(c);
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
