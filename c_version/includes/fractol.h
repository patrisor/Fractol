/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:51:29 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/23 23:31:31 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keycode_mac.h"
# include <math.h>
# include <stdint.h>
# include <stddef.h>
# include <pthread.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define ZOOM 1.1f
# define THREADS 8

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct		s_complex
{
	double		r;
	double		i;
	double		rsqr;
	double		isqr;
}					t_complex;

typedef struct		s_viewport
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	int			d;
	int			abs;
	int			interactive;
	t_complex	mouse;
}					t_viewport;

typedef struct		s_pixel
{
	t_complex	c;
	long		i;
}					t_pixel;

typedef struct		s_palette
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palette;
typedef struct s_mlx	t_mlx;

typedef void		(*t_f_fn_v)(t_viewport *v);
typedef t_pixel		(*t_f_fn_p)(int x, int y, t_viewport *v, t_mlx *mlx);
typedef struct		s_fractol
{
	char		*name;
	t_f_fn_v	viewport;
	t_f_fn_p	pixel;
	int			mouse;
}					t_fractol;

typedef struct		s_thread
{
	int				id;
	t_mlx			*mlx;
}					t_thread;

typedef struct		s_render
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_render;

struct				s_mlx
{
	void		*mlx;
	void		*window;
	t_fractol	*fractal;
	t_pixel		*data;
	t_image		*image;
	t_mouse		mouse;
	t_viewport	viewport;
	t_palette	*palette;
	t_render	render;
	int			smooth;
	int			mouselock;
	pid_t		pid;
};

void				calc_z(t_viewport *env, t_complex *tmp_z,
		t_complex z, t_complex c);
t_complex			abs_sqr(t_complex z);
void				put_instructions(int code);
t_mlx				*mlxdel(t_mlx *mlx);
t_mlx				*init_mlx(t_fractol *f);
t_fractol			*init_fractol(char *name);
void				render(t_mlx *mlx);
void				draw(t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_expose(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
t_image				*new_image(t_mlx *mlx);
void				clear_image(t_image *img);
void				image_set_pixel(t_image *image, int x, int y, int color);
t_fractol			*fractol_match(char *str);
int					get_color(t_pixel p, t_mlx *mlx);
t_palette			*get_palettes();
void				zoom(int x, int y, t_viewport *v, double z);
void				viewport_fit(t_viewport *v);
void				reset_viewport(t_mlx *mlx);
t_complex			screen_to_complex(int x, int y, t_viewport *v);
t_pixel				escape_time(int x, int y, t_viewport *v, t_mlx *mlx);
void				mandelbrot_viewport(t_viewport *v);
void				bibrot_viewport(t_viewport *v);
void				tribrot_viewport(t_viewport *v);
void				burningship_viewport(t_viewport *v);
void				julia_viewport(t_viewport *v);
void				trijulia_viewport(t_viewport *v);
void				quadjulia_viewport(t_viewport *v);
void				excalibur_viewport(t_viewport *v);
void				enigma_viewport(t_viewport *v);

#endif
