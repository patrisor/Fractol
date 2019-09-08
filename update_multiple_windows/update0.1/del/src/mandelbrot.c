/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:16:29 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 12:57:28 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prac.h"
#include <math.h>
#include <stdio.h>

int			*get_colors()
{
	// NOTE: You cannot return an array from function, unless it's declared static
	static int 	colors[500] = {BLACK, WHITE, RED, ORANGE, LIME, BLUE, YELLOW, CYAN, MAGENTA, SILVER, GRAY ,MAROON, OLIVE, GREEN, PURPLE, TEAL, NAVY, CRIMSON, CORAL,
	INDIAN_RED, SALMON, ORANGE_RED, GOLD, GOLDEN_ROD, SADDLEBROWN, LAWN_GREEN,
	DARK_GREEN, FOREST_GREEN, PALE_GREEN, SPRING_GREEN, SEA_GREEN, LIGHT_SEA_GREEN,
	DARK_SLATE_GRAY, POWDER_BLUE, AQUA_MARINE, STEEL_BLUE, SKY_BLUE, MIDNIGHT_BLUE,
	INDIGO, DARK_MAGENTA, DEEP_PINK, HOT_PINK, ORCHID, BEIGE, ANTIQUE_WHITE, WHEAT,
	CORN_SILK, LAVENDER, FLORAL_WHITE, ALICE_BLUE, GHOST_WHITE, HONEYDEW, IVORY,
	AZURE, SNOW, MISTY_ROSE, DARK_GRAY, GAINSBORO, WHITE_SMOKE, DISCO, BRICK_RED,
	FLAMINGO, JAFFA, SAFFRON};
	return (colors);
}

/* Linear Interpolation (Returns Percentage between two points) */
double		ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

// OPTIMIZED VERSION: the number of multiplications can be reduced to three instead of five, making the calculations quicker per pixel
/*
 * Special Thanks to http://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/ for
 * teaching me how to construct a mandelbrot using escape-time algorithm
 *
 */
void		mandelbrot(t_game *game)
{
	// Iterate through each pixel of the screen from top left to bottom right
	int row = -1;
	while (++row != WIN_HEIGHT)
	{
		int col = -1;
		while (++col != WIN_WIDTH)
		{
			// The real number iterates from -2 to 2 (incrementally per column) per row
			//  NOTE: there are 1080 rows
			double c_re = (col - (WIN_WIDTH / 2.0)) * (4.0 / WIN_WIDTH);
			// Throughout the whole program, the imaginary goes from -1.25 to 1.25
			double c_im = (row - (WIN_HEIGHT / 2.0)) * (4.0 / WIN_WIDTH);
			double rsquare = 0;
			double isquare = 0;
			double zsquare = 0;
			double x = 0;
			double y = 0;
			// Main meat of the program
			int i = -1;
			// The more steps we have, the more we can zoom in to our program
			// Once we get far enough from the origin, we escape
			while (((rsquare + isquare) <= 4) && (++i < MAX_ITERATIONS))
			{
				x = rsquare - isquare + c_re;
				y = zsquare - rsquare - isquare + c_im;
				rsquare = x * x;
				isquare = y * y;
				zsquare = (x + y) * (x + y);
			}
			// Pick the color of the pixel based on the iteration (the level of instability)
			int color;
			int	*colors = get_colors();
			if (i < MAX_ITERATIONS)
				// colors come from a list of colors taken from a function
				color = colors[i];
			else
				// Color is black if it is stable
				color = 0x000000;
			// place a color of pixel based on the current row and column
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, col, row, color);
		}
	}
}
