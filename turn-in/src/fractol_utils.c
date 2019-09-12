/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:21:00 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 21:40:30 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	abs_sqr(t_complex z)
{
	z.rsqr = (z.r * z.r);
	z.isqr = (z.i * z.i);
	return (z);
}

void	calc_z(t_viewport *env, t_complex *tmp_z, t_complex z, t_complex c)
{
	if (env->d == 2)
	{
		tmp_z->i = (z.r + z.i) * (z.r + z.i) - z.rsqr - z.isqr + c.i;
		tmp_z->r = z.rsqr - z.isqr + c.r;
	}
	else if (env->d == 3)
	{
		tmp_z->i = z.i * (3 * z.rsqr - z.isqr) + c.i;
		tmp_z->r = z.r * (z.rsqr - 3 * z.isqr) + c.r;
	}
	else if (env->d == 4)
	{
		tmp_z->i = (4 * z.r * z.i) * (z.rsqr - z.isqr) + c.i;
		tmp_z->r = (z.rsqr * z.rsqr) + z.isqr * (z.isqr - 6 * z.rsqr) + c.r;
	}
	/*
	if (env->f.abs == 1)
	{
		tmp_z->i = (tmp_z->i < 0.0f) ? -tmp_z->i : tmp_z->i;
		tmp_z->r = (tmp_z->r < 0.0f) ? -tmp_z->r : tmp_z->r;
	}
	*/
}
