/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 05:33:42 by pbondoer          #+#    #+#             */
/*   Updated: 2019/09/06 14:35:07 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		**mlxdel(t_mlx ***mlx)
{
	if ((*(*mlx))->window != NULL)
		mlx_destroy_window((*(*mlx))->mlx, (*(*mlx))->window);
	if ((*(*mlx))->image != NULL)
		del_image((*(*mlx)), (*(*mlx))->image);
	ft_memdel((void **)(*mlx));
	return (*mlx);
}

t_mlx		**init(t_fractal **f)
{
	int				i;
	static t_mlx	**mlx;
	char			*title;

	i = -1;
	if ((mlx = ft_memalloc(sizeof(t_mlx*) * arr_length((void **)f))) == NULL)
		return (NULL);
	while(++i < arr_length((void **)f))
	{
		if ((mlx[i] = ft_memalloc(sizeof(t_mlx))) == NULL)
			return (NULL);
		title = ft_strjoin("Fract'ol - ", f[i]->name);
		if ((mlx[i]->mlx = mlx_init()) == NULL ||
			(mlx[i]->window = mlx_new_window(mlx[i]->mlx, WIN_WIDTH,
				WIN_HEIGHT, title)) == NULL ||
			(mlx[i]->image = new_image(mlx[i])) == NULL ||
			(mlx[i]->data = ft_memalloc(sizeof(t_pixel) * WIN_WIDTH
									* WIN_HEIGHT)) == NULL)
			return (mlxdel(&mlx));
		mlx[i]->fractal = f[i];
		mlx[i]->mouse.isdown = 0;
		mlx[i]->mouselock = 1 - f[i]->mouse;
		mlx[i]->palette = get_palettes();
		mlx[i]->smooth = 0;
	}
	return (mlx);
}
