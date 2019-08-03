/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:49:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/24 12:32:49 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

int		main(int argc, char **argv)
{
	//t_mlx		*mlx;
	//t_fractol	*f;

	if (argc != 2)
		return (die("usage: ./fractol [fractol option]"));

	// TODO: Delete
	// Initialize library
	void *mlx_ptr = mlx_init();

	// Match what was passed as parameter and compare it to given fractol definitions
	//f = fractol_match(argv[1]);
	return (0);
}
