/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:28:04 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 22:46:18 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Iterate through every pixel of image pointer, setting the color for each one
 */
void		draw(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	// Iterate through every pixel, setting the color for each one
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			// For that particular pointer to image in memory 
			image_set_pixel(mlx->image, x, y,
					get_color(*(mlx->data + y * WIN_WIDTH + x), mlx));
		y++;
	}
	// Once you are done with the image, you paste it onto the window (indirect)
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}

/*
 * Make each part of the screen run on it's own specified thread 
 * WIN_HEIGHT -> 8 threads 
 * 1st thread) 0 - 90 pixels going down
 * 2nd thread) 90 - 180 pixels going down
 * 3rd thread) 180 - 270 pixels going down
 * 4th thread) 270 - 360 pixels going down
 * 5th thread) 360 - 450 pixels going down
 * 6th thread) 450 - 540 pixels going down
 * 7th thread) 540 - 630 pixels going down
 * 8th thread) 630 - 720 pixels going down
 */
void		*render_thread(void *m)
{
	t_thread	*t;
	int			x;
	int			y;

	// Casts argument to thread pointer
	t = (t_thread *)m;
	// y = 0..720
	y = WIN_HEIGHT / THREADS * t->id;
	// y < 90..810
	while (y < WIN_HEIGHT / THREADS * (t->id + 1))
	{
		x = -1;
		// Each pixel on the particular thread will run on it's own thread
		while (++x < WIN_WIDTH)
			*(t->mlx->data + y * WIN_WIDTH + x) =
				t->mlx->fractal->pixel(x, y, &t->mlx->viewport, t->mlx);
		y++;
	}
	return (NULL);
}

/*
 * First set a thread for each part of the screen (1/8th of the screen per thread),
 * then set each color individually
 */
void		render(t_mlx *mlx)
{
	int			i;
	t_render	*r;

	i = 0;
	r = &mlx->render;
	// We create a structure to store the addresses for our new threads
	while (i < THREADS)
	{
		// We iterate the ids for our new threads amd set each one to the address 
		// of our current process
		r->args[i].id = i;
		r->args[i].mlx = mlx;
		// Firts multi-threading function which makes a thread run a certain functon:
		// Make each pixel run on it's own specified thread
		pthread_create(r->threads + i, NULL, render_thread, &(r->args[i]));
		i++;
	}
	// Second multi-threading function which allows us to join other threads by:
	// suspending execution of the calling thread until the target thread terminates
	i = -1;
	while (++i < THREADS)
		pthread_join(r->threads[i], NULL);
	// Iterate through every pixel of image pointer, setting the color for each one
	draw(mlx);
}
