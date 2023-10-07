/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:10:22 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/03 17:46:01 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i++ < mlx->max_iter)
	{
		mlx->z_r = mlx->z_rnew;
		mlx->z_i = mlx->z_inew;
		mlx->z_rnew = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_inew = 2 * mlx->z_r * mlx->z_i + mlx->c_i;
		if ((mlx->z_rnew * mlx->z_rnew + mlx->z_inew * mlx->z_inew) > 4)
			break ;
	}
	return (i);
}

void	mandelbrot(t_mlx *mlx, double r_f, double i_f)
{
	mlx->y = 0;
	while (mlx->y < WIN_H)
	{
		mlx->c_i = mlx->max_i - mlx->y * i_f;
		mlx->x = 0;
		while (mlx->x < WIN_W)
		{
			mlx->c_r = mlx->min_r + mlx->x * r_f;
			mlx->z_rnew = 0;
			mlx->z_inew = 0;
			mlx->iter = iterate(mlx);
			check_palette(mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}

void	julia(t_mlx *mlx, double r_f, double i_f)
{
	mlx->y = 0;
	while (mlx->y < WIN_H)
	{
		mlx->c_i = mlx->p2;
		mlx->x = 0;
		while (mlx->x < WIN_W)
		{
			mlx->c_r = mlx->p1;
			mlx->z_rnew = mlx->min_r + mlx->x * r_f;
			mlx->z_inew = mlx->max_i - mlx->y * i_f;
			mlx->iter = iterate(mlx);
			check_palette(mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}

void	render_img(t_mlx *mlx)
{
	double	r_f;
	double	i_f;

	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	r_f = (mlx->max_r - mlx->min_r) / (WIN_W - 1);
	i_f = (mlx->max_i - mlx->min_i) / (WIN_H - 1);
	if (mlx->name == 1)
		mandelbrot(mlx, r_f, i_f);
	if (mlx->name == 2)
		julia(mlx, r_f, i_f);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

int	new_img(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	if (!mlx->img_ptr)
		return (1);
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->img_bpp,
			&mlx->line_len, &mlx->endian);
	if (!mlx->img_addr)
		return (1);
	render_img(mlx);
	return (0);
}
