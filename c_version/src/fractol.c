/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 22:14:21 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/13 00:37:27 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*get_fractols(void)
{
	static t_fractol array[10] = {
		{"mandelbrot", mandelbrot_viewport, escape_time, 0},
		{"bibrot", bibrot_viewport, escape_time, 0},
		{"tribrot", tribrot_viewport, escape_time, 0},
		{"julia", julia_viewport, escape_time, 1},
		{"trijulia", trijulia_viewport, escape_time, 1},
		{"quadjulia", quadjulia_viewport, escape_time, 1},
		{"burningship", burningship_viewport, escape_time, 0},
		{"excalibur", excalibur_viewport, escape_time, 0},
		{"enigma", enigma_viewport, escape_time, 0},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractol	*fractol_match(char *str)
{
	int				i;
	t_fractol		*f;

	i = -1;
	f = get_fractols();
	while (f[++i].name != NULL)
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
	return (&f[i]);
}

t_fractol	*init_fractol(char *name)
{
	t_fractol	*ret;

	ret = fractol_match(name);
	if (ret->name == NULL)
		return (NULL);
	return (ret);
}
