/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:49:53 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/08 06:04:22 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prac.h"

struct thread_args
{
    t_game	*game;
    char	*title;
};

typedef struct thread_args	thread_arguments;



int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

// Determines endian of machine
int		determine_endian()
{
	int		ret;

	unsigned int i = 1;
	char *c = (char*) & i;
	if (*c)
		ret = 0;
	else
		ret = 1;
	return (ret);
}

void	drawStrip(void *mlx_ptr, void *win_ptr, int y, int color)
{
	int x = -1;
	while (++x != WIN_WIDTH)
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
}

// TODO: Delete
void	polska(void *mlx_ptr, void *win_ptr)
{
	int y = -1;
	int color;
	while (++y != WIN_HEIGHT)
	{
		if (y < WIN_HEIGHT / 2)
			color = 0xFFFFFF;
		if (y >= WIN_HEIGHT / 2)
			color = 0xFF0000;
		drawStrip(mlx_ptr, win_ptr, y, color);
	}
}

void	engine(t_game *game)
{
	// Draw things
	// Function will continuously update our image
	render(game);
	// Handles hook events
	setup_controls(game);
}

/* MULTITHREADING?
void	*init_game(void *a)
{
	thread_arguments *b;
	
	b = (thread_arguments *)a;
	// Initialize library and New window created with width and height, and title
	if ((b->game->mlx_ptr = mlx_init()) == NULL || (b->game->win_ptr = mlx_new_window(b->game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, b->title)) == NULL)
		die("Failed to initialize library, or window.");
	// Draw things
	mandelbrot(b->game);
	// Infinite loop (needed to keep updating the screen)
	mlx_loop(b->game->mlx_ptr);
	return(NULL);
}
*/

void	*init_game(t_game *g, char *title)
{
	// Initialize library and New window created with width and height, and title
	if ((g->mlx_ptr = mlx_init()) == NULL || (g->win_ptr = mlx_new_window(g->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title)) == NULL)
		die("Failed to initialize library, or window.");
	// Draw things
	mandelbrot(g);
	// Infinite loop (needed to keep updating the screen)
	//mlx_loop(g->mlx_ptr);
	return(NULL);
}

// TODO: Rainbow
#include <stdio.h>
#include <pthread.h>
int		main(int argc, char **argv)
{
	t_game			*game;
	t_game			*game2;

	// Initia;ize two threads
	//pthread_t		*tid;
	// Initialize arguments to thread 
	//thread_arguments a[2];

	if (argc < 2 || argc > 3)
		return (die("usage: ./prac [name_of_window]"));
	if (((game = (t_game *)malloc(sizeof(t_game))) == NULL) || ((game2 = (t_game *)malloc(sizeof(t_game))) == NULL))
		return(die("Failed to allocate space for game."));


	/* TESTING POINTERS
	char *ptr;
	ptr = (char *)malloc(sizeof(char) * 2);
	ptr = "niuuuuuuuuuuuuuTESTINGTESTINGG";
	while(*ptr)
	{
		//printf("%p\n", ptr);
		printf("%c\n", *ptr);
		(ptr)++;
	}
	*/
	/* NOTE: This code proves multiple game objects exist in one game pointer
	(*game).test = 42;
	printf("VALUE1: %d\n", (*game).test);
	printf("ADDRESS1: %p\n", &((*game).test));
	game++;
	(*game).test = 1;
	printf("VALUE2: %d\n", (*game).test);
	printf("ADDRESS2: %p\n", &((*game).test));
	game++;
	*/

	/*
	char **ptr = argv;
	int i = 0;

	tid = (pthread_t *)malloc(sizeof(pthread_t) * 2);
	//a = (thread_arguments *)malloc(sizeof(thread_arguments) * 2);
	ptr++;
	while(*ptr)
	{
		//printf("%s\n", *ptr);
		a[i].title = *ptr;
		a[i].game = game;
		pthread_create(&(tid[i]), NULL, init_game, &(a[i]));
		game++;
		ptr++;
		i++;
	}

	i = 0;
	while(i < 1) 
	{
		// THIS IS WHERE IT KEEPS BREAKING
		pthread_join(tid[i], NULL);
		i++;
	}*/

	init_game(game, argv[1]);
	init_game(game2, argv[2]);
	while(1);
	return (0);
}
