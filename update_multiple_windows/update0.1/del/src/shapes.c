/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:52:10 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/25 20:58:37 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prac.h"

// PARALLELOGRAM
void	rect(void *mlx_ptr, void *win_ptr, int init_x, int init_y, int height, int width, int color)
{
	int		x;
	int		y;

	int left_corner[] = {init_x, init_y};
	mlx_pixel_put(mlx_ptr, win_ptr, left_corner[0], left_corner[1], color);
	y = init_y - 1;
	while (++y != left_corner[1] + height)
	{
		x = init_x;
		if (y == init_y)
			while (++x != (left_corner[0] + width) + 1)
				mlx_pixel_put(mlx_ptr, win_ptr, x, left_corner[1], color);
		if (y > init_y && y < left_corner[1] + height)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, left_corner[0], y, color);
			mlx_pixel_put(mlx_ptr, win_ptr, left_corner[0] + width, y, color);
		}
	}
	x = init_x;
	while (++x != left_corner[0] + width)
		mlx_pixel_put(mlx_ptr, win_ptr, x, (left_corner[1] + height) - 1, color);
}

void	hypnotic_1(void *mlx_ptr, void *win_ptr, int init_x, int init_y, int width, int height)
{
	for (int i = 1; i < ((WIN_WIDTH / 2) / ((width + height) / 2) + 1); i+=2)
	{
		rect(mlx_ptr, win_ptr, init_x, init_y, height * i, width * i, 0xFFFFFF);
		init_x -= width;
		init_y -= height;
	}
}

// CIRCLE
void	drawCircle(void *mlx_ptr, void *win_ptr, int xc, int yc, int x, int y, int color)
{
	mlx_pixel_put(mlx_ptr, win_ptr, xc + x, yc + y, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc - x, yc + y, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc + x, yc - y, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc - x, yc - y, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc + y, yc + x, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc - y, yc + x, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc + y, yc - x, color);
	mlx_pixel_put(mlx_ptr, win_ptr, xc - y, yc - x, color);
}

void	circle(void *mlx_ptr, void *win_ptr, int xc, int yc, int radius, int color)
{
	int 	x;
	int 	y;
	int 	d;

	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	drawCircle(mlx_ptr, win_ptr, xc, yc, x, y, color);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(mlx_ptr, win_ptr, xc, yc, x, y, color);
	}
}
