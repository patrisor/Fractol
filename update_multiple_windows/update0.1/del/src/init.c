/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:16:55 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/25 21:32:44 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prac.h"

t_character		*init_character()
{
	t_character		*ret;

	if((ret = (t_character *)malloc(sizeof(t_character))) == NULL)
		return (NULL);
	ret->x = WIN_WIDTH / 2;
	ret->y = WIN_HEIGHT / 2;
	return (ret);
}
