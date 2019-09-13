/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:30:33 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 23:20:50 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		burningship_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
	v->d = 2;
	v->abs = 1;
	v->interactive = 0;
}

void		excalibur_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
	v->d = 3;
	v->abs = 1;
	v->interactive = 0;
}

void		enigma_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 1.0f;
	v->ymin = -2.0f;
	v->ymax = 1.0f;
	v->offx = -0.25f;
	v->d = 4;
	v->abs = 1;
	v->interactive = 0;
}
