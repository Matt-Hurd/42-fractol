/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 07:36:45 by mhurd             #+#    #+#             */
/*   Updated: 2016/11/08 09:36:41 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fract_mb(t_data *d, double x, double y)
{
	double	zr;
	double	zi;
	double	zrsqr;
	double	zisqr;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	y = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y));
	zr = 0;
	zi = 0;
	zrsqr = zr * zr;
	zisqr = zi * zi;
	iters = -1;
	while (zrsqr + zisqr <= 4.0 && ++iters < d->max)
	{
		zi = (zr + zi) * (zr + zi) - zrsqr - zisqr;
		zi += y;
		zr = zrsqr - zisqr + x;
		zrsqr = zr * zr;
		zisqr = zi * zi;
	}
	return (iters);
}
