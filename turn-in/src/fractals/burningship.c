/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:30:33 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 23:00:33 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel		burningship_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
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

void		burningship_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
	v->d = 2;
	v->abs = 1;
}

void		excalibur_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
	v->d = 3;
	v->abs = 1;
}

void		enigma_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
	v->d = 4;
	v->abs = 1;
}
