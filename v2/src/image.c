/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:09:40 by patrisor          #+#    #+#             */
/*   Updated: 2019/08/12 15:17:11 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Sets a certain color for the pixel at that particular x and y location on image 
// pointer
void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = color;
}

t_image	*del_image(t_mlx *mlx, t_image *img)
{
	if (img != NULL)
	{
		if (img->image != NULL)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image	*new_image(t_mlx *mlx)
{
	t_image		*img;

	// allocates memory for image struct
	if ((img = ft_memalloc(sizeof(t_image))) == NULL)
		return (NULL);
	// Returns the address of a new image which can be manipulated later (void *)
	if ((img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)) == NULL)
		return (del_image(mlx, img)); // else, the image address will be deleted
	// address that represents the begining of the memory area where the image is stored.
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
			&img->endian);
	// Converts bytes to bits (bits per pixel)
	img->bpp /= 8;
	return (img);
}
