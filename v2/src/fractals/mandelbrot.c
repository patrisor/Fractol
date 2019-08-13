/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:21:31 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 14:08:39 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	calc_z() and escape_time()
**	Classic escape time algorithm for determining fractal color
**	For Mandelbrot and Multibrot series, a given point will escape to infinity
**	if the absolute value of the complex number is greater than 2.0
**
**	Z(n+1) = Z(n)^d + c where d = 2 for the simplest case Mandelbrot
**
**	Thus to find if a given point is in the mandelbrot set we repeat:
**	Z(n+1) = Z(n)^2 + c
**	(Where n is the current iteration and n+1 is the next iteration)
**	and continue until we've found |Z(n+1)| > 2.0
**
**	To simplify for the computer we can check if |Z(n+1)|^2 <= 4.0
**
**	We also want to avoid too many multiplications since they are very expensive
**	at high precisions. To get Z(n+1) we would need to evaluate
**
**	'Z(n)^2 + c' where 'Z(n) = a + bi' which would give us:
**	'a^2 - b^2 + 2abi + c'
**
**	To isolate the imaginary component we subtract a^2 and b^2 this will leave
**	us with '2abi' which we would then just add the imaginary component of c.
**
**	To isolate the real component we just use the a^2 - b^2 we had previously
**	calculated and then just add the real component of c
**
**	These tricks are detailed in:
** 	https://randomascii.wordpress.com/2011/08/13/faster-fractals-through-algebra
**
**	Another trick we can play is to check if our real and imaginary components
**	after squaring are equal to a previous iteration. If so, we've hit a cycle
**	and our point is in the Mandelbrot set saving us previous iteration
**	time!!
**
**	To get smooth coloring we can apply a log log transformation to Z(n)
**	The idea is that because each iteration of Z goes like:
**	Z^2 -> Z^4 -> Z^8 -> Z^16 -> Z^32
**	Applying 1 log transformation allows us to bring the exponent in front:
**	2*log(Z) -> 4*log(Z) -> 8*log(Z) -> 16*log(Z) -> 32*log(Z)
**	Applying a 2nd log transformation with **change of base** will then give:
**	0 -> 1 -> 2 -> 3 -> 4
**
**	A more in depth explanation can be found:
**	http://linas.org/art-gallery/escape/escape.html
*/

/*
**	mandelbrot()
**	Basic mandelbrot set where 'c' is determined based on a pixel's location
**	in a bounded area (see: fractal_setup_?.c functions to derive bounds)
*/

// TODO: OPTIMIZE by having less multiplications
t_pixel		mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx)
{
	// Initialize complex numbers
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	// Sets up the current position of our pixel, accounting for the window's zoom and offset
	z = screen_to_complex(x, y, v);
	c = screen_to_complex(x, y, v);
	i = 0;
	// Iterate to find y
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		// Already reached a blowout, so break and make the pixel black
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}

void		mandelbrot_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -1.0f;
	v->ymax = 1.0f;
	v->offx = -0.5f;
}
