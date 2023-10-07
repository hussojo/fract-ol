/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:50:18 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/04 08:14:26 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_mod(int keysym, t_mlx *mlx)
{
	if ((keysym == 27 || keysym == 78) && mlx->max_iter > 0)
		mlx->max_iter -= 10;
	if (keysym == 24 || keysym == 69)
		mlx->max_iter += 10;
	render_img(mlx);
}

void	arrow_moves(int keysym, t_mlx *mlx)
{
	double	range;

	range = mlx->max_r - mlx->min_r;
	if (keysym == 123 || keysym == 0)
	{
		mlx->min_r = mlx->min_r - 0.05 * range;
		mlx->max_r = mlx->max_r - 0.05 * range;
	}
	if (keysym == 124 || keysym == 2)
	{
		mlx->min_r = mlx->min_r + 0.05 * range;
		mlx->max_r = mlx->max_r + 0.05 * range;
	}
	if (keysym == 126 || keysym == 13)
	{
		mlx->min_i = mlx->min_i + 0.05 * range;
		mlx->max_i = mlx->max_i + 0.05 * range;
	}
	if (keysym == 125 || keysym == 1)
	{
		mlx->min_i = mlx->min_i - 0.05 * range;
		mlx->max_i = mlx->max_i - 0.05 * range;
	}
	render_img(mlx);
}

int	key_event(int keysym, t_mlx *mlx)
{
	if (keysym == 18)
	{
		mlx->palette = 1;
		render_img(mlx);
	}
	if (keysym == 19)
	{
		mlx->palette = 2;
		render_img(mlx);
	}
	if (keysym == 20)
	{
		mlx->palette = 3;
		render_img(mlx);
	}
	if ((keysym >= 123 && keysym <= 126) || (keysym >= 0 && keysym <= 2)
		|| keysym == 13)
		arrow_moves(keysym, mlx);
	if (keysym == 27 || keysym == 24 || keysym == 69 || keysym == 78)
		iter_mod(keysym, mlx);
	if (keysym == K_ESC)
		destroy_flag(mlx, 0);
	return (0);
}
