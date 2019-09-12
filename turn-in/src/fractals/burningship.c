/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:30:33 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/09 15:40:26 by patrisor         ###   ########.fr       */
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
	while (z.r * z.r + z.i * z.i < (1 << 8) && (++i < v->max))
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
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
}