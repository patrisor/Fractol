/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:10:13 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/18 06:25:01 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * 0 means no input was provided. 1 means input was provided and now can be played 
 * with. Static means that it is not visible to rest of project
 */
static void		disp_info(int mode)
{
	if (mode == 0)
	{
		write(2, "Usage: ./fractol [fractol option]\n\n", 35);
		write(2, "Fractol options (use number, not name!):\n", 41);
		write(2, "0) Julia\n1) Mandelbrot\n2) Burning Ship\n", 39);
		write(2, "3) Trijulia\n4) Tribrot\n5) Excalibur\n", 36);
		write(2, "6) Quadjulia\n7) Quadrobrot\n8) Ghosts\n", 36);
		write(2, "\nExample: './fractol 0' - Displays Julia set\n\n", 46);
	}
	else if (mode == 1)
	{
		ft_putstr("\n				Fract'ol 42!!\n\
		Mouse scroll up/down: Zoom in/out @ mouse position\n\
		Arrow keys: Translate real/imaginary axes\n\
		'+/-': Increase/decrease iteration limit\n\
		f: Freeze mouse cursor tracking (only works for Julia type fractals!)\n\
		p: Psychedelic mode!\n\
		l: linear continous color mode\n\
		c: Toggle color palettes\n\
		s: Color surprise!\n\
		d: Psychedelic surprise!\n\
		r: Reset active fractal!\n\
		esc: Quit :(\n\n");
	}
}

/*
 * Specifies our hooks for the loop (all buttons to be pressed)
 */
void		start_hooks(t_envars *env)
{
	mlx_key_hook(env->win, keydown_hook, env);
	mlx_hook(env->win, 2, 0, key_pressed_hook, env);
	mlx_hook(env->win, 4, 0, mouse_pressed_hook, env);
	mlx_hook(env->win, 5, 0, mouse_released_hook, env);
	mlx_hook(env->win, 6, 0, mouse_moved_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
}

/*
 * Function fills the parameters of our t_envars structure. We start our MLX
 */
void			setup_env(t_envars *env)
{
	env->w = WIN_WIDTH;
	env->h = WIN_HEIGHT;
	// Area of our Window
	env->size = WIN_WIDTH * WIN_HEIGHT;
	env->x_t = 0;
	env->y_t = 0;
	env->ccolor = 0;
	// Iteration limit
	env->iter_lim = 50;
	// Our malloced buffer is the same size of the area of our window
	env->iter_buf = (float *)malloc(env->size * sizeof(float));
	// Jump tables 
	env->fract_setup(env);
	// Sets-up parameters to our color structure under the t_envars structure
	setup_color(env);
	// Initializes our mlx environment
	env->mlx = mlx_init();
	// Creates a new window
	env->win = mlx_new_window(env->mlx, env->w, env->h, "Fractol 42");
	// use mlx functions to initialize our image that we will be drawing on 
	init_img(env);
	// Initializes hooks for our mouse 
	init_mouse(env);
	// Specifies our hooks for the loop (all buttons to be pressed)
	start_hooks(env);
	// 

	// Infinite Loop
	mlx_loop(env->mlx);
}

int				main(int argc, char **argv)
{
	t_envars	env;

	env.fract_choice = -1;
	// TODO: Implement multiple Fract`ol input
	// Input check, and 
	if (argc > 1 && (env.fract_choice = get_fract_funct(&env, argv[1])) != -1)
	{
		disp_info(1);
		// Function fills the parameters of our t_envars structure. We start 
		// our MLX environment
		setup_env(&env);
		return (0);
	}
	else
	{
		disp_info(0);
		return (-1);
	}
}
