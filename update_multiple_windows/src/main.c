/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 08:28:17 by pbondoer          #+#    #+#             */
/*   Updated: 2019/09/06 14:35:09 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

int		die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

t_fractal	**init_fractals(int amount, char **argv)
{
	int			i;
	t_fractal   **ret;
	char		**tmp;
	
	i = -1;
	tmp = ++argv;
	if ((ret = ft_memalloc(sizeof(t_fractal*) * amount)) == NULL)
		return(NULL);
	while(++i < amount)
	{
		if ((ret[i] = ft_memalloc(sizeof(t_fractal))) == NULL)
			return(NULL);
		ret[i] = fractal_match(*tmp);
		if (ret[i]->name == NULL)
			return(NULL);
		tmp++;
	}
	return(ret);
}
#include <stdio.h>


int		main(int argc, char **argv)
{
	t_mlx		**mlx;
	//t_fractal	*f;
	t_fractal	**fractals;

	// CHECKS if there are valid fractals
	if (argc < 2 || argc > 3)
		return (die("usage: ./fractol fractal_name"));
	
	// STORES FIRST FRACTAL
	/*
	f = fractal_match(argv[1]);
	if (f->name == NULL)
		return (die("error: invalid fractal name"));
	if ((mlx = init(f)) == NULL)
		return (die("error: mlx couldn't initialize properly"));
	*/

	// TEST
	if ((fractals = init_fractals(arr_length((void **)argv) - 1, argv)) == NULL)
		return (die("error: unable to initialize fractals"));
	if ((mlx = init(fractals)) == NULL)
		return (die("error: mlx couldn't initialize properly"));

	while (1)
	{}
	/* MLX
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	*/
	return (0);
}
