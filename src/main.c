/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:35:03 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/14 09:42:23 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

void	list_fractals(void)
{
	ft_putstr("\
____________________________________________\n\
Valid fractals:\n\
	J: Julia\n\
	M: Mandelbrot\n\
	B: Burning Ship\n\
	T: Trigonometric Julia\n\
____________________________________________\n\
");
	exit(0);
}

void	display_controls(void)
{
	ft_putstr("\
____________________________________________\n\
CONTROLS:\n\
 Zoom:\n\
    IN: Mouse: LClick\n\
      Will zoom at mouse coordinates.\n\
    OUT: Mouse: RClick\n\
____________________________________________\n\
");
}

void	set_fract(t_data *d, char *s)
{
	if (ft_strequ(s, "J"))
		d->fract = (fract_julia);
	else if (ft_strequ(s, "M"))
		d->fract = (fract_mb);
	else if (ft_strequ(s, "B"))
		d->fract = (fract_bs);
	else if (ft_strequ(s, "T"))
		d->fract = (fract_trig);

}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = (t_data *)ft_memalloc(sizeof(t_data));
		if (!data)
			ft_malloc_error();
		set_fract(data, av[1]);
		if (!data->fract)
			list_fractals();
		display_controls();
		draw_everything(data);
	}
	else
		list_fractals();
	return (0);
}
