/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 04:47:42 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/14 08:27:25 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_reload(t_data *d)
{
	d->img = mlx_new_image(d->mlx, WINDOW_SIZE_X + 100, WINDOW_SIZE_Y + 100);
	d->pixel_img = mlx_get_data_addr(d->img, &(d->bpp), &(d->s_line), &(d->ed));
	draw_fract(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img);
}

int		expose_hook(t_data *d)
{
	draw_reload(d);
	return (0);
}

void	draw_everything(t_data *d)
{
	d->scale = 1.0;
	d->ytrans = 0;
	d->xtrans = 0;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Fractol");
	d->max = 48;
	d->ca = -0.7;
	d->cb = 0.27015;
	d->paused = 0;

	mlx_expose_hook(d->win, expose_hook, d);
	mlx_hook(d->win, 2, 3, key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_hook(d->win, 6, (1L << 6), mouse_move, d);
    mlx_loop(d->mlx);
}