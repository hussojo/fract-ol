/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:20:08 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/04 08:40:17 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette_fire(t_mlx *mlx)
{
	if (mlx->iter < (mlx->max_iter * 0.02))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x030000);
	else if (mlx->iter < (mlx->max_iter * 0.04))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x260104);
	else if (mlx->iter < (mlx->max_iter * 0.06))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x410106);
	else if (mlx->iter < (mlx->max_iter * 0.08))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x5F0209);
	else if (mlx->iter < (mlx->max_iter * 0.10))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x7C020C);
	else if (mlx->iter < (mlx->max_iter * 0.20))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x98030F);
	else if (mlx->iter < (mlx->max_iter * 0.30))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xF98503);
	else if (mlx->iter < (mlx->max_iter * 0.40))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xC90314);
	else if (mlx->iter < (mlx->max_iter * 0.50))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xF90419);
	else
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x000000);
}

void	palette_hive(t_mlx *mlx)
{
	if (mlx->iter < (mlx->max_iter * 0.02))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFADDDC);
	else if (mlx->iter < (mlx->max_iter * 0.04))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xF6C5C3);
	else if (mlx->iter < (mlx->max_iter * 0.06))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x7FBC80);
	else if (mlx->iter < (mlx->max_iter * 0.08))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFFDD02);
	else if (mlx->iter < (mlx->max_iter * 0.10))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x92C8DF);
	else if (mlx->iter < (mlx->max_iter * 0.20))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xEAD4BB);
	else if (mlx->iter < (mlx->max_iter * 0.30))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x0C0C0A);
	else if (mlx->iter < (mlx->max_iter * 0.40))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xC2C2C2);
	else if (mlx->iter < (mlx->max_iter * 0.50))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFFFFFF);
	else
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x515251);
}

void	palette_joy(t_mlx *mlx)
{
	if (mlx->iter < (mlx->max_iter * 0.02))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x709DFF);
	else if (mlx->iter < (mlx->max_iter * 0.04))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x85ABFF);
	else if (mlx->iter < (mlx->max_iter * 0.06))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0x99B9FF);
	else if (mlx->iter < (mlx->max_iter * 0.08))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xAFC9FF);
	else if (mlx->iter < (mlx->max_iter * 0.10))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xC6D7FF);
	else if (mlx->iter < (mlx->max_iter * 0.20))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFBEF9D);
	else if (mlx->iter < (mlx->max_iter * 0.30))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xF8DF3A);
	else if (mlx->iter < (mlx->max_iter * 0.40))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFF9233);
	else if (mlx->iter < (mlx->max_iter * 0.50))
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xF57200);
	else
		my_mlx_pixel_put(mlx, mlx->x, mlx->y, 0xFFB30F);
}

void	check_palette(t_mlx *mlx)
{
	if (mlx->palette == 1)
		palette_fire(mlx);
	if (mlx->palette == 2)
		palette_hive(mlx);
	if (mlx->palette == 3)
		palette_joy(mlx);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img_addr + (y * mlx->line_len + x * (mlx->img_bpp / 8));
	*(unsigned int *)dst = color;
}
