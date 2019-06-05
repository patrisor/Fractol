/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:03:23 by patrisor          #+#    #+#             */
/*   Updated: 2019/06/04 21:01:15 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * Setup a jump table so we can grab the correct fractal function!
 */
/* TODO: Implement Fractols for this to work
static void     setup_fract_table(t_fract_jt j_table[25])
{
	j_table[0] = &julia;
	j_table[1] = &mandelbrot;
	j_table[2] = &mandelbrot;
	j_table[3] = &julia;
	j_table[4] = &mandelbrot;
	j_table[5] = &mandelbrot;
	j_table[6] = &julia;
	j_table[7] = &mandelbrot;
	j_table[8] = &mandelbrot;
}
*/

/*
 * Setup a jump table so we can grab the correct fractal function!
 */
/* TODO: Implement Fractols for this to work
static void     setup_fract_setup_table(t_f_set_jt j_table[25])
{
	j_table[0] = &setup_julia;
	j_table[1] = &setup_mandelbrot;
	j_table[2] = &setup_bship;
	j_table[3] = &setup_trijulia;
	j_table[4] = &setup_tribrot;
	j_table[5] = &setup_excalibur;
	j_table[6] = &setup_quadjulia;
	j_table[7] = &setup_quadrobrot;
	j_table[8] = &setup_quadroship;
}
*/

/*
 * Function sets-up a jump table so that we can get the relevant fractal function
 * we'd like to display.
 * We make our jumptable static so we only need to set it once per run of our 
 * fractal program.
 * We need to protect our jump table lookup by making sure our converted number
 * is actually a valid index into the jump table!
 */
/* TODO: Implement Fractols for this to work
int				get_fract_funct(void *environ, char *choice_str)
{
	static t_fract_jt   fractal_jt[25] = {NULL};
	static t_f_set_jt   fract_setup_jt[25] = {NULL};
	int                 choice;
	t_envars            *env;

	env = (t_envars *)environ;
	// sets-up a jump table so that we can get the relevant fractal to display
	if (fractal_jt[0] == NULL)
		setup_fract_table(fractal_jt);
	if (fract_setup_jt[0] == NULL)
		setup_fract_setup_table(fract_setup_jt);
	// Converts the number passed as parameter into a number
	choice = ft_atoi(choice_str);
	// Stores the correct fractal into t_fract_jt and t_f_set_jt
	if (choice >= 0 && choice < 9)
	{
		env->fract_func = fractal_jt[choice];
		env->fract_setup = fract_setup_jt[choice];
		return (choice);
	}
	else
		return (-1);
}
*/
