/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:32:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/25 22:07:20 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prac.h"

void	move(int key, t_game *game)
{
	if (key == KEY_A)
		game->character->x -= 10;
	else if (key == KEY_D)
		game->character->x += 10;
	else if (key == KEY_W)
		game->character->y -= 10;
	else if (key == KEY_S)
		game->character->y += 10;
	render(game);
}

/*
 * Mlx loop hook which defines functions within key code presses
 */
int		hook_keydown(int key, t_game *game)
{
	(void)game;
	// Key code for ESC
	if (key == KEY_ESCAPE)
	{
		free(game);
		exit(EXIT_SUCCESS);
	}
	// Key code for W, A, S, D
	else if (key == KEY_W || key == KEY_A || key == KEY_S ||
			key == KEY_D)
		move(key, game);
	// TODO: key code for color change
	/*
	else if (key == KEY_LEFT || key == KEY_RIGHT ||
			key == KEY_UP || key == KEY_DOWN)
		change_color(key, mlx);
	*/
	return (0);
}

void	setup_controls(t_game *game)
{
	// Key-pressed user event
	mlx_key_hook(game->win_ptr, hook_keydown, game);
	// Mouse-pressed user event
	//mlx_hook(mlx->window, 4, 0, hook_mousedown, game);
	// Mouse-up user event
	//mlx_hook(mlx->window, 5, 0, hook_mouseup, game);
	// Mouse movement user event
	//mlx_hook(mlx->window, 6, 0, hook_mousemove, game);
}
