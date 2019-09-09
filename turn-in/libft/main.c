/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:09:20 by patrisor          #+#    #+#             */
/*   Updated: 2019/07/17 20:17:18 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	char	*test;

	if (argc != 2)
		return (-1);
	ft_memcpy(test, (const void)argv[1], ft_strlen(argv[1]));
	ft_printf("%s", test);
	return (0);
}
