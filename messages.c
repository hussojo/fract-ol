/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:03 by jhusso            #+#    #+#             */
/*   Updated: 2023/10/07 14:57:16 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_message(void)
{
	ft_putendl_fd("*******************************************************", 1);
	ft_putendl_fd("This program explores Mandelbrot and Julia set fractals", 1);
	ft_putendl_fd("in three color palettes (keys 1 / 2 / 3).", 1);
	ft_putendl_fd("*******************************************************", 1);
	ft_putendl_fd("To explore Mandelbrot:", 1);
	ft_putendl_fd(" ./fractol mandelbrot <color palette>", 1);
	ft_putendl_fd("*******************************************************", 1);
	ft_putendl_fd("To explore Julia set add two values as starting point:", 1);
	ft_putendl_fd(" ./fractol julia 2 <color palette> <value1> <value2>", 1);
	ft_putendl_fd("*******************************************************", 1);
	ft_putendl_fd("******************************************************", 1);
	ft_putendl_fd("starting value examples for Julia set:", 1);
	ft_putendl_fd("[0.355 0.355] [0.34 -0.05] [-0.54 0.54] [0 0.8]", 1);
	ft_putendl_fd("******************************************************", 1);
	help_julia();
	exit (0);
}

void	help_julia(void)
{
	ft_putendl_fd("******************************************************", 1);
	ft_putendl_fd("starting value examples for Julia set:", 1);
	ft_putendl_fd("[0.355 0.355] [0.34 -0.05] [-0.54 0.54] [0 0.8]", 1);
	ft_putendl_fd("******************************************************", 1);
	exit (0);
}

void	navigation(void)
{
	ft_putendl_fd("*******************	NAVIGATION	*****************", 1);
	ft_putendl_fd("Move left/right/up/down: arrow keys / wasd.", 1);
	ft_putendl_fd("Zoom in/out: mouse scroll.", 1);
	ft_putendl_fd("Decrease/increase iteratons: press + / -.", 1);
	ft_putendl_fd("Change between colors: press 1 or 2 or 3", 1);
	ft_putendl_fd("Rererender JULIA with left mouse click anywhere on image.", 1);
	ft_putendl_fd("*********************************************************", 1);
}
