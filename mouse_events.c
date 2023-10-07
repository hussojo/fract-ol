/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 08:37:41 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/03 18:27:15 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_params(int x, int y, t_mlx *mlx)
{
	if (mlx->name == 2)
	{
		mlx->p1 = x;
		mlx->p2 = y;
		mlx->p1 = mlx->min_r + mlx->x
			* ((mlx->max_r - mlx->min_r) / (WIN_W - 1));
		mlx->p2 = mlx->max_i - mlx->y
			* ((mlx->max_i - mlx->min_i) / (WIN_H - 1));
		render_img(mlx);
	}
	return (0);
}

void	zoom_in(t_mlx *mlx)
{
	mlx->max_r = mlx->max_r - (mlx->center_r * mlx->zoom_rate);
	mlx->min_r = mlx->min_r + (mlx->center_r * mlx->zoom_rate);
	mlx->max_i = mlx->max_i - (mlx->center_i * mlx->zoom_rate);
	mlx->min_i = mlx->min_i + (mlx->center_i * mlx->zoom_rate);
	render_img(mlx);
}

void	zoom_out(t_mlx *mlx)
{
	mlx->max_r = mlx->max_r + (mlx->center_r * mlx->zoom_rate);
	mlx->min_r = mlx->min_r - (mlx->center_r * mlx->zoom_rate);
	mlx->max_i = mlx->max_i + (mlx->center_i * mlx->zoom_rate);
	mlx->min_i = mlx->min_i - (mlx->center_i * mlx->zoom_rate);
	render_img(mlx);
}

int	mouse_event(int button, int x, int y, t_mlx *mlx)
{
	mlx->x = x;
	mlx->y = y;
	mlx->center_r = mlx->max_r - mlx->min_r;
	mlx->center_i = mlx->max_i - mlx->min_i;
	if (button == 1)
		mouse_params(x, y, mlx);
	if (button == 4)
		zoom_in(mlx);
	if (button == 5)
		zoom_out(mlx);
	return (0);
}
