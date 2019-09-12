/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 13:31:01 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/11 23:28:03 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	v->d = 2;
	v->abs = 0;
	v->interactive = 1;
}

void		trijulia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	v->d = 3;
	v->abs = 0;
	v->interactive = 1;
}

void		quadjulia_viewport(t_viewport *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
	v->d = 4;
	v->abs = 0;
	v->interactive = 1;
}
