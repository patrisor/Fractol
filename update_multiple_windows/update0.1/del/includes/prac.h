/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:51:29 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/08 04:44:22 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include "colors.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAX_ITERATIONS 100

// Game Structs
typedef struct	s_character
{
	int	x;
	int	y;
}				t_character;

typedef struct	s_game
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_character	*character;

	int		test;
}				t_game;

// TODO: Delete
typedef struct	s_vec3d
{
	float x;
	float y;
	float z;
}				t_vec3d;

typedef struct	s_triangle
{
	t_vec3d		v[3];
}				t_triangle;

typedef struct	s_vector
{
	float		**data;
	int			size;
	int			count;
}				t_vector;

typedef struct	s_mesh
{
	t_vector	tris;
}				t_mesh;

// FUNCTIONS
// FRACTOL
void			mandelbrot(t_game *game);
// SHAPES
void			rect(void *mlx_ptr, void *win_ptr, int init_x, int init_y, int height, int width, int color);
void			hypnotic_1(void *mlx_ptr, void *win_ptr, int init_x, int init_y, int width, int height);
void			circle(void *mlx_ptr, void *win_ptr, int xc, int yc, int radius, int color);
// GAME
t_character     *init_character();
void			render(t_game *game);
// CONTROLS
void			setup_controls(t_game *game);

#endif
