/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 04:21:33 by mhurd             #+#    #+#             */
/*   Updated: 2016/11/09 18:22:17 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_all(t_data *d)
{
	int y;

	y = -1;
	while (++y <= WINDOW_SIZE_Y)
		free(d->image[y]);
}

void	ft_exit(void)
{
	exit(1);
}

void	ft_malloc_error(void)
{
	ft_putendl_fd("Malloc Failure", 2);
	ft_exit();
}

void	ft_arg_error(void)
{
	ft_putendl_fd("Missing filename.", 2);
	ft_exit();
}

void	ft_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	ft_exit();
}
