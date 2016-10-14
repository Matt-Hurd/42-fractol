/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_spectrum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 04:47:51 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/14 07:59:51 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

//TODO
static int get_color(t_data *d, double iterations)
{
	double frequency;
	unsigned int red;
	unsigned int green;
	unsigned int blue;

	frequency = M_PI * 2.0;
	red = sin(frequency * iterations / d->max + 2) * 255;
	green = sin(frequency * iterations / d->max) * 255;
	blue = sin(frequency * iterations / d->max + 4) * 255;
	return (red << 16 | ((green << 8) & 0xFF00) | (blue & 0xFF));
}

void color_pixel(t_data *d, int x, int y, int iterations)
{
	int i;
	int color;

	if (iterations != d->max)
		color = get_color(d, iterations);
	else
		color = 0xFFFFFF;
	i = (x * 4) + (y * d->s_line);
	d->pixel_img[i] = color;
	d->pixel_img[++i] = color >> 8;
	d->pixel_img[++i] = color >> 16;
}