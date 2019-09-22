/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:29:19 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/14 01:21:09 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom(int x, int y, t_viewport *v, double z)
{
	v->zoom *= z;
	v->offx -= ((double)x / WIN_WIDTH) * ((v->xmax - v->xmin) *
			(v->zoom * z) - (v->xmax - v->xmin) * (v->zoom));
	v->offy -= ((double)y / WIN_HEIGHT) * ((v->ymax - v->ymin) *
			(v->zoom * z) - (v->ymax - v->ymin) * (v->zoom));
}
