/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:14:21 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/17 22:51:52 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Hard code the given fractols into an array of fractol functions and given names
 */
t_fractol		*get_fractols(void)
{
	static t_fractol array[8] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0},
		{"julia", julia_viewport, julia_pixel, 1},
		{"burningship", burningship_viewport, burningship_pixel, 0},
		{NULL, NULL, NULL, 0}
	};
	return (array);
}

/*
 * Match what was passed as parameter and compare it to given fractol definitions
 */
t_fractol		*fractol_match(char *str)
{
	t_fractol		*f;
	int				i;

	// An array of fractol functions and given names
	f = get_fractols();
	// Iterate through the array of fractol data structures
	i = -1;
	while (f[++i].name != NULL)
		// If there is a fractol match, based on what was passed in parameter,
		// and the available ones, then return that one
		if (ft_strcmp(f[i].name, str) == 0)
			return(&f[i]);
	return(&f[i]);
}
