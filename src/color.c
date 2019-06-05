/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:21:24 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/04 20:28:24 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Sets-up parameters to our color structure under the t_envars structure
 */
void	setup_color(t_envars *env)
{
	env->color_style = 0;
	env->c.cent = 127;
	env->c.wid = 128;
	env->c.r_freq = 0.33;
	env->c.g_freq = 0.33;
	env->c.b_freq = 0.33;
	env->c.r_phase = 0.00;
	env->c.g_phase = (2 * M_PI) / 3;
	env->c.b_phase = (4 * M_PI) / 3;
	env->psychedelic = 0;
}
