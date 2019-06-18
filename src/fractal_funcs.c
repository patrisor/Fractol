/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 05:37:02 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Function represents the iterative mathematical formula fc(z) = (z * z) + c
 */
void			mandelbrot(void *environ, int pix_ind)
{
	t_fractal	f;
	t_envars	*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	if (env->psychedelic == 0)
	{
		f = calc_fract_min_max(env, f);
		env->f = f;
		f.c.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
		f.c.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
		f.z.r = 0;
		f.z.i = 0;
		env->iter_buf[pix_ind] = escape_time(env, f);
	}
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}

/*
 * We have a canvas, and our canvas will have an x (f.x) and y-axis (f.y) 
 * We use this canvas to visualize a complex plane, or a complex number (f.c),
 * written as a + bi (a, real number, represents f.x and bi, imaginary number, 
 * represents f.y). Similar to the mandelbrot set, the only difference is that 
 * the c value is the value of your mouse x and y position.
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
		 // Updates the image based on the iteration value
		 env->iter_buf[pix_ind] = escape_time(env, f);
     }
     // Places pixel onto the screen
	 // choose_col() Function generates regular repeating color gradients by 
	 // using a sin wave and shifting the frequency and phase of r, g, b color 
	 // components.
	 img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
 }
