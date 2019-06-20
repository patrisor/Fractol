/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 06:25:01 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	init_img - use mlx functions to initialize our image that we will be
**	drawing our maps on!
**
**	The initial bits per pixel (bpp) that the mlx_get_data_addr function returns
**	is 32 bits.
**
**	We would like to work with bytes though since that's what the rest of our
**	program is working in.
**
**	Example 1: our colors are ints which are in bytes.
**	Example 2: Our ft_bzero and ft_memset functions expect a size in bytes
**
**	Since 8 bits = 1 byte we just take our bpp and divide by 8 to get
**	BYTES per pixel
**
**	LET IT BE DECLARED HERE THAT img->bpp HENCEFORCE STANDS FOR BYTES PER PIXEL!
*/

void		init_img(t_envars *env)
{
	t_image	*img;

	img = &env->image;
	img->image = mlx_new_image(env->mlx, env->w, env->h);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->line_s,
								&img->endian);
	img->bpp /= 8;
}

/*
 * Place a pixel on the window 
 */
void		img_pixel_put(t_envars *env, double x, double y, int color)
{
	t_image *img;

	// Gets the address of the image
	img = &(env->image);
	// If the specified area is in between the window
	if (x >= 0 && x < env->w && y >= 0 && y < env->h)
		// Place a specified color onto the address of the 
		*(int *)(img->ptr + (int)(idx(y, x, env->w) * img->bpp)) = color;
}

/*
 * Clears Image Pointer
 */
void		clear_img(t_envars *env)
{
	t_image *img;

	img = &(env->image);
	ft_bzero(img->ptr, env->size * img->bpp);
}
