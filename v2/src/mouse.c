/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:07:00 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 23:26:28 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Logic for left mouse down or scroll wheel triggered
 */
int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	// Middle scroll wheel (zooms out)
	if (button == 4)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
		render(mlx);
	}
	// Middle scroll wheel (zooms in)
	else if (button == 5)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
		render(mlx);
	}
	if (y < 0)
		return (0);
	mlx->mouse.isdown |= 1 << button;
	return (0);
}

/*
 * (mlx->mouse.isdown |= 1 << button) is the opposite of (mlx->mouse.isdown &= ~(1 << button))
 */
int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.isdown &= ~(1 << button);
	return (0);
}

/*
 * Once the mouse is down and you move
 */
int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	double w;
	double h;

	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	// if mouse is not locked 
	if (!mlx->mouselock)
		mlx->viewport.mouse = screen_to_complex(x, y, &mlx->viewport);
	if (mlx->mouse.isdown & (1 << 1))
	{
		// Adjusts each time based on how far you have zoomed; if zoom was not 
		// accounted for, you would move too much if zoomed in all the way
		w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
		h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
		// Moves
		mlx->viewport.offx += (double)(mlx->mouse.lastx - mlx->mouse.x)
			/ WIN_WIDTH * w;
		mlx->viewport.offy += (double)(mlx->mouse.lasty - mlx->mouse.y)
			/ WIN_HEIGHT * h;
	}
	if (mlx->mouse.isdown || (mlx->fractal->mouse && !mlx->mouselock))
		render(mlx);
	return (0);
}
