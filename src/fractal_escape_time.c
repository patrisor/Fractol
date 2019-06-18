/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_escape_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 05:39:07 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 05:48:28 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * The escape time algorithm is a technique for displaying certain aspects of 
 * system behavior under iteration. The escape time algorithm takes the locatio 
 * of each pixel in the map of possible system states and assigns it a color.
 * With each successive iteration, the escape time algorithm hides additional 
 * regions in the domain of the system, that do not contain any of the attractor
 */
float	escape_time(t_envars *env, t_fractal f)
{
	size_t		iter;
	t_dcmplx	z;
	t_dcmplx	c;
	t_dcmplx	tmp_z;

	z = f.z;
	c = f.c;
	iter = 0;
	z = abs_sqr(z);
	while (z.rsqr + z.isqr <= 4.0 && iter < env->iter_lim)
	{
		// 
		calc_z(env, &tmp_z, z, c);
		if (z.r == tmp_z.r && z.i == tmp_z.i)
		{
			iter = env->iter_lim;
			break ;
		}
		z = abs_sqr(tmp_z);
		iter++;
	}
	if (env->ccolor == 1 && iter != env->iter_lim)
		return ((float)iter + 1 - log(log(z.rsqr + z.isqr)) / log(env->f.d));
	return ((float)iter);
}
