/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:21:24 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 05:35:23 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Sets-up parameters to our color structure under the t_envars structure
 */
void	setup_color(t_envars *env)
{
	env->color_style = 0;
	env->c.cent = 127;
	env->c.wid = 128;
	env->c.r_freq = 0.33;
	env->c.g_freq = 0.33;
	env->c.b_freq = 0.33;
	env->c.r_phase = 0.00;
	env->c.g_phase = (2 * M_PI) / 3;
	env->c.b_phase = (4 * M_PI) / 3;
	env->psychedelic = 0;
}

/*
 * Function changes colors of our fractal
 */
void	toggle_palette(t_envars *env)
{
	env->color_style = (env->color_style + 1) % 4;
	if (env->color_style == 0)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.33;
	}
	if (env->color_style == 1)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.00;
	}
	if (env->color_style == 2)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.00;
		env->c.b_freq = 0.33;
	}
	if (env->color_style == 3)
	{
		env->c.r_freq = 0.00;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.33;
	}
}

/*
 * Grabs a random Colors and fixes it
 */
void	color_surprise(t_envars *env)
{
	env->c.r_freq = rand() % 10;
	env->c.g_freq = rand() % 10;
	env->c.b_freq = rand() % 10;
}

/*
 * Randomly changes the colors
 */
void	psychedelic_surprise(t_envars *env)
{
	env->c.r_phase = rand() % 20;
	env->c.g_phase = rand() % 20;
	env->c.b_phase = rand() % 20;
}

/*
 * Function generates regular repeating color gradients by using a sin wave 
 * and shifting the frequency and phase of r, g, b color components.
 * The center of our color range is 127 (because 255 is max), thus the width 
 * of our color range is 128 (if we want rainbow effects)
 */
int		choose_col(t_envars *env, float iter)
{
	int		r;
	int		g;
	int		b;
	t_color	c;

	c = env->c;
	// Error checker to see if iteration limit is passed the actual limit;
	// Will not put an image on pixel if it is
	if (iter >= env->iter_lim)
		return (0);
	else
	{
		// Grabs a percentage from the 255-color range we want (RED)
		r = sin(fmod(c.r_freq * iter + c.r_phase, 2 * M_PI)) * c.wid + c.cent;
		// Grabs a percentage from the 255-color range we want (GREEN)
		g = sin(fmod(c.g_freq * iter + c.g_phase, 2 * M_PI)) * c.wid + c.cent;
		// Grabs a percentage from the 255-color range we want (BLUE)
		b = sin(fmod(c.b_freq * iter + c.b_phase, 2 * M_PI)) * c.wid + c.cent;
		/* TEST OUTPUT
		 * RED: 8323072, GREEN: 60672, BLUE: 16
		 * RED: 13434880, GREEN: 44800, BLUE: 0
		 * RED: 11010048, GREEN: 54016, BLUE: 1 */
		return (r << 16 | g << 8 | b);
	}
}
