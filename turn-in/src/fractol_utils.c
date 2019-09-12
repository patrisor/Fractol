/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:21:00 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 23:35:09 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	abs_sqr(t_complex z)
{
	z.rsqr = (z.r * z.r);
	z.isqr = (z.i * z.i);
	return (z);
}

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}

void	calc_z(t_viewport *env, t_complex *tmp_z, t_complex z, t_complex c)
{
	if (env->d == 2)
	{
		tmp_z->i = (z.r + z.i) * (z.r + z.i) - z.rsqr - z.isqr + c.i;
		tmp_z->r = z.rsqr - z.isqr + c.r;
	}
	else if (env->d == 3)
	{
		tmp_z->i = z.i * (3 * z.rsqr - z.isqr) + c.i;
		tmp_z->r = z.r * (z.rsqr - 3 * z.isqr) + c.r;
	}
	else if (env->d == 4)
	{
		tmp_z->i = (4 * z.r * z.i) * (z.rsqr - z.isqr) + c.i;
		tmp_z->r = (z.rsqr * z.rsqr) + z.isqr * (z.isqr - 6 * z.rsqr) + c.r;
	}
	if (env->abs == 1)
	{
		tmp_z->i = fabs(tmp_z->i);
		tmp_z->r = fabs(tmp_z->r);
	}
}

t_pixel		escape_time(int x, int y, t_viewport *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	i = -1;
	c = (v->interactive == 0) ? screen_to_complex(x, y, v) : v->mouse;
	z = abs_sqr(screen_to_complex(x, y, v));
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
