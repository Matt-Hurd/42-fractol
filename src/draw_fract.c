/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 05:54:00 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/14 08:26:57 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fract(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < WINDOW_SIZE_Y)
	{
		x = -1;
		while (++x < WINDOW_SIZE_X)
			color_pixel(d, x, y, d->fract(d, x, y));
	}
}