/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:14:21 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/09 18:39:46 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_fractol		*fractol_match(char *str)
{
	t_fractol		*f;
	int				i;
	
	f = get_fractols();
	i = -1;
	while (f[++i].name != NULL)
		if (ft_strcmp(f[i].name, str) == 0)
			return(&f[i]);
	return(&f[i]);
}

t_fractol	*init_fractol(char *name)
{
	t_fractol	*ret;

	ret = fractol_match(name);
	if (ret->name == NULL)
		return (NULL);
	return (ret);
}
