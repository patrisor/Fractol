/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:21:31 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 22:46:24 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel		mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	z = screen_to_complex(x, y, v);
	c = screen_to_complex(x, y, v);
	i = -1;
	z = abs_sqr(z);
	while (z.rsqr + z.isqr < (1 << 8) && (++i < v->max))
	{
		calc_z(v, &temp, z, c);
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z = abs_sqr(temp);
	}
	return ((t_pixel){.c = z, .i = i});
}

void		mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
	v->d = 2;
	v->abs = 0;
}

void		bibrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
	v->d = 3;
	v->abs = 0;
}

void		tribrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
	v->d = 4;
	v->abs = 0;
}
