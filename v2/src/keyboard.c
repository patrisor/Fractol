/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:26:33 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 23:27:33 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_hooks(int key, t_mlx *mlx)
{
	int		doot;

	doot = 0;
	if (key >= KEY_1 && key <= KEY_1 + 3)
		mlx->palette = &get_palettes()[key - KEY_1];
	else if (key == KEY_L)
		mlx->smooth = 1 - mlx->smooth;
	else
		doot = 1;
	if (!doot)
		draw(mlx);
	return (doot);
}

void	move(int key, t_mlx *mlx)
{
	double w;
	double h;

	w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == KEY_UP)
		mlx->viewport.offy -= h * 0.05f;
	if (key == KEY_DOWN)
		mlx->viewport.offy += h * 0.05f;
	if (key == KEY_LEFT)
		mlx->viewport.offx -= w * 0.05f;
	if (key == KEY_RIGHT)
		mlx->viewport.offx += w * 0.05f;
	if (key == KEY_L)
		mlx->mouselock = 1 - mlx->mouselock;
}

int		hook_keydown(int key, t_mlx *mlx)
{
	if (key == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	if (key == KEY_0)
		reset_viewport(mlx);
	if (key == KEY_OPEN_BRACKET)
		mlx->viewport.max *= 2;
	if (key == KEY_CLOSE_BRACKET)
		if (mlx->viewport.max / 2 >= 2)
			mlx->viewport.max /= 2;
	if (key == KEY_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, 1 / ZOOM);
	if (key == KEY_EQUAL)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, ZOOM);
	move(key, mlx);
	if (draw_hooks(key, mlx))
		render(mlx);
	return (0);
}
