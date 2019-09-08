/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:01:33 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/25 22:07:22 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prac.h"

void	fill_screen(void *mlx_ptr, void *win_ptr, int color)
{
	int y = -1;
	while (++y != WIN_HEIGHT)
	{
		int x = -1;
		while (++x != WIN_WIDTH)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
	}
}

void	render(t_game *game)
{
	// CLEAR THE SCREEN, NOT ADD MORE LAYERS OF PIXEL MEMORY
	fill_screen(game->mlx_ptr, game->win_ptr, 0x000000);
	// Draw Character
	for (int i = 1; i < 10; i++)
		circle(game->mlx_ptr, game->win_ptr, game->character->x, game->character->y, i, 0xFF00FF);
}
