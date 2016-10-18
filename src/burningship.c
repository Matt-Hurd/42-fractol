/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 04:38:24 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/18 11:59:30 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fract_bs(t_data *d, double x, double y)
{
	double	zr;
	double	zi;
	double	zrsqr;
	double	zisqr;
	int		iters;

	x = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	y = ((-4 * (1 - y / WINDOW_SIZE_Y) + 2) / d->scale) -
		((d->ytrans / WINDOW_SIZE_Y));
	zr = 0;
	zi = 0;
	zrsqr = zr * zr;
	zisqr = zi * zi;
	iters = -1;
	while (zrsqr + zisqr <= 4.0 && ++iters < d->max)
	{
		zi = (fabs(zr) + fabs(zi)) * (fabs(zr) + fabs(zi)) - zrsqr - zisqr;
		zi += y;
		zr = zrsqr - zisqr + x;
		zrsqr = zr * zr;
		zisqr = zi * zi;
	}
	return (iters);
}
