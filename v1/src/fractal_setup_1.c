/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_setup_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 06:25:01 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// The d = 3 version of burning ship
void	setup_excalibur(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 3;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_quadjulia(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 4;
	env->f.abs = 0;
	env->f.interactive = 1;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_quadrobrot(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 4;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 3;
}

void	setup_quadroship(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 4;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}
