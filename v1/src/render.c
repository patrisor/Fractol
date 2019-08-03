/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 06:25:01 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	This function will draw all the pixels of a fractal for 1 quadrant of the
**	window. This allows multithreading so with 4 threads each can take care of 1
**	quadrant.
*/
static void	*render_quads(void *args)
{
	int			x_ind;
	int			y_ind;
	int			x_end;
	int			y_end;
	t_envars	*env;

	env = ((t_targs *)args)->env;
	x_end = (IS_LEFT(((t_targs *)args)->quad)) ? env->w / 2 : env->w;
	y_end = (IS_TOP(((t_targs *)args)->quad)) ? env->h / 2 : env->h;
	x_ind = (IS_LEFT(((t_targs *)args)->quad)) ? -1 : env->w / 2 - 1;
	while (++x_ind < x_end)
	{
		y_ind = (IS_TOP(((t_targs *)args)->quad)) ? -1 : env->h / 2 - 1;
		while (++y_ind < y_end)
			env->fract_func(env, idx(y_ind, x_ind, env->w));
	}
	return (NULL);
}

/*	
**	This will render our fractal. We do this by creating 4 threads that will
**	work on the 4 quadrants of the window.
**	Then we just wait for the threads to finish and we can put the resulting
**	image to the window!
*/
void		render(t_envars *env)
{
	int		i;
	t_targs	args[4];

	clear_img(env);
	i = -1;
	while (++i < 4)
	{
		args[i].env = env;
		args[i].quad = i;
		pthread_create(&env->tids[i], NULL, render_quads, (void *)&args[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(env->tids[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->image.image, 0, 0);
}
