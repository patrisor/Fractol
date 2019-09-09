/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:28:04 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/09 15:37:59 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_mlx *mlx)
{
	int x;
	int y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			image_set_pixel(mlx->image, x, y,
					get_color(*(mlx->data + y * WIN_WIDTH + x), mlx));
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

void		*render_thread(void *m)
{
	t_thread	*t;
	int			x;
	int			y;
	
	t = (t_thread *)m;
	y = (WIN_HEIGHT / THREADS * t->id) - 1;
	while (++y < WIN_HEIGHT / THREADS * (t->id + 1))
	{
		x = -1;
		while (++x < WIN_WIDTH)
			*(t->mlx->data + y * WIN_WIDTH + x) =
				t->mlx->fractal->pixel(x, y, &t->mlx->viewport, t->mlx);
	}
	return (NULL);
}

void		render(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = -1;
	r = &mlx->render;
	while (++i < THREADS)
	{
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		pthread_create(r->threads + i, NULL, render_thread, &(r->args[i]));
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(r->threads[i], NULL);
	draw(mlx);
}
