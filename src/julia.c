/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 04:38:24 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/18 11:59:34 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			fract_julia(t_data *d, double x, double y)
{
	double	za;
	double	zb;
	double	temp;
	int		i;

	za = ((4 * x / WINDOW_SIZE_X - 2) / d->scale) +
		((d->xtrans / WINDOW_SIZE_X));
	zb = ((-4 * y / WINDOW_SIZE_Y + 2) / d->scale) +
		((d->ytrans / WINDOW_SIZE_Y));
	i = -1;
	while (za * za + zb * zb <= 4 && ++i < d->max)
	{
		temp = za;
		za = za * za - zb * zb + d->ca;
		zb = 2 * temp * zb + d->cb;
	}
	return (i);
}
