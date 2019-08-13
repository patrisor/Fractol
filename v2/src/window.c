/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:55:22 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 15:09:27 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

/*
 * Initializes our mlx environemnt. Links the environemnet with pointers
 * Allocates enoug hmeory for the area of the available pixels we will have
 * Sets struct variables to initial parameters.
 */
t_mlx		*init(t_fractol *f)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, ft_strjoin("Fract'ol - ", f->name))) == NULL ||
		(mlx->image = new_image(mlx)) == NULL ||
		(mlx->data = ft_memalloc(sizeof(t_pixel) * WIN_WIDTH
								* WIN_HEIGHT)) == NULL)
		return (mlxdel(mlx));
	// Sets initial states
	mlx->mouse.isdown = 0;
	mlx->fractal = f;
	// Locks the mouse for the julia set
	mlx->mouselock = 1 - f->mouse;
	// Colors
	mlx->palette = get_palettes();
	// Smooth or not smooth
	mlx->smooth = 0;
	return (mlx);
}
