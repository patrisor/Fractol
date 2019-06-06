/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/04 21:07:37 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Linear INTerpolation between two points given a decimal percent
 */
double		ft_lint(double start, double end, double decimal_percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - decimal_percent) + (end * decimal_percent));
}

/*
 * Calculate the minimum and maximum extents of our fractal. These extents can be
 * then used to interpolate the (real, image) coords for each of the pixels in 
 * our window
 */
t_fractal	calc_fract_min_max(t_envars *env, t_fractal f)
{
    double	x_wid;
    double	y_wid;

    // To get zooming to work correctly (like in Google maps):
    // We scale our x and y widths by our desired zoom factor
    x_wid = f.x_wid / env->f.z_factor;
    y_wid = f.y_wid / env->f.z_factor;
    // We set our x_min as the center point of our fractal + any offsets and 
    // subtract by the width multiplied by the 'x_ratio' of our mouse cursor
    f.x_min = f.x_cent + env->x_t - x_wid * (env->mouse.x_ratio);
    // Our x_max is similar except we multiply by '1 - x_ratio'
    f.x_max = f.x_cent + env->x_t + x_wid * (1 - env->mouse.x_ratio);
    // Repeat the same process but for y_min and y_max
    f.y_min = f.y_cent + env->y_t - y_wid * (env->mouse.y_ratio);
    f.y_max = f.y_cent + env->y_t + y_wid * (1 - env->mouse.y_ratio);
    return (f);
}
