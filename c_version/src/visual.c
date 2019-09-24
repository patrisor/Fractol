/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:19:20 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/23 23:56:13 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[7];

	array[0] =
		(t_palette){5, 0, {0x581845, 0x900C3F, 0xC70039, 0xFF5733, 0xFFC30F}};
	array[1] =
		(t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[2] =
		(t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[3] =
		(t_palette){5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[4] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[5] =
		(t_palette){5, 0, {0xFFFFFF, 0xa8d8ea, 0xaa96da, 0xfcbad3, 0xffffd2}};
	array[6] = (t_palette){0, 0, {0}};
	return (array);
}

void		put_instructions(int code)
{
	if (code == 0)
	{
		ft_putendl("\n-------INSTRUCTIONS-------\n");
		ft_putendl("ESC: exit");
		ft_putendl("P: Pause (Julia set)");
		ft_putendl("\n-----ADJUST ITERATIONS-----\n");
		ft_putendl("[ : Less Iterations");
		ft_putendl("] : More Iterations");
		ft_putendl("\n------ZOOM + MOVEMENT------\n");
		ft_putendl("- : Zoom Out");
		ft_putendl("= : Zoom In");
		ft_putendl("Scroll Wheel: Zoom where mouse is");
		ft_putendl("KEY_DOWN: Move Fractal Down");
		ft_putendl("KEY_UP: Move Fractal Up");
		ft_putendl("KEY_LEFT: Move Fractal Left");
		ft_putendl("KEY_RIGHT: Move Fractal Right");
		ft_putendl("Left Mouse Down: Pan in any direction");
		ft_putendl("0: reset fractal");
		ft_putendl("\n----------COLORS----------\n");
		ft_putendl("1 - 6: Change Colors");
		ft_putendl("L: Linear Colors\n");
	}
}
