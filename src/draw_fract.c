/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 05:54:00 by mhurd             #+#    #+#             */
/*   Updated: 2016/11/08 10:46:24 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_chunk(void *args)
{
	t_args	*a;
	int		x;
	int		y;

	a = (t_args *)args;
	while (a->start <= a->end)
	{
		x = a->start % WINDOW_SIZE_X;
		y = a->start / WINDOW_SIZE_X;
		color_pixel(a->d, x, y, a->d->fract(a->d, x, y));
		a->start++;
	}
	return (NULL);
}

void	draw_fract(t_data *d)
{
	int		start;
	int		x;
	int		inc;
	t_args	*a;

	inc = WINDOW_SIZE_Y * WINDOW_SIZE_X / d->thread_count;
	x = -1;
	start = 0;
	while (++x < d->thread_count)
	{
		a = (t_args *)ft_memalloc(sizeof(t_args));
		a->d = d;
		a->start = start;
		a->end = start + inc;
		if (pthread_create(&d->render_threads[x], NULL, draw_chunk, a))
			ft_error();
		start += inc;
	}
}
