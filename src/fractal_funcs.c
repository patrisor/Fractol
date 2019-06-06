/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/04 21:07:37 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *
 */

/*
 * 
 * Similar to the mandelbrot set, the only difference is that the c value is 
 * determined by the position of the mouse cursor.
 */
 void		julia(void *environ, int pix_ind)
 {
     t_fractal       f;
     t_envars        *env;

     // Cast the pointer address to our main environment struct type
     env = (t_envars *)environ;
     // Point our empty t_fractal type to one which exists inside of our adress
     f = env->f;
     // Assign our fractal's x pos to the pixel's position passed in parameter
     // modulo of our WIN_WIDTH (so that we can see our creation centered)
     f.x = pix_ind % env->w;
     // Assign our fractal's y pos to the pixel's position passed in parameter
     // divided by our WIN_WIDTH (so that we can see our creation centered)
     f.y = pix_ind / env->w;
     // if our psychedelic setting is set to zero, it will not create our fractal
     if (env->psychedelic == 0)
     {
	 // Calculate the minimum and maximum extents of our fractal. 
	 // At the end of the day, this function will keep our fractal centered
	 f = calc_fract_min_max(env, f);
	 // Return new value of our fractal and assign it back to the pointer to our env
	 env->f = f;
	 // These extents are used to interpolate the (real, image) coords for 
	 // each of the pixels in our window
	 // These settings adjust how our fractol is positioned
	 f.c.r = ft_lint(-f.x_wid / 2, f.x_wid / 2, env->mouse.x / env->w);
	 // creates a mirror effect if turned off
	 f.c.i = ft_lint(-f.y_wid / 2, f.y_wid / 2, env->mouse.y / env->h);
	 // creates a reverse mirror effect when turned off
	 f.z.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
	 // Creates the same effect when turned off, but going down the y-axis
	 f.z.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
	 // TODO:

     }
     // TODO:

 }
