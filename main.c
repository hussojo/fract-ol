/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:05:24 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/04 08:48:18 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_flag(t_mlx *mlx, int flag)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (flag == 1)
		exit(1);
	else
		exit (0);
}

int	destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

void	set_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 1, &destroy, mlx);
	mlx_key_hook(mlx->win_ptr, &key_event, mlx);
	mlx_mouse_hook(mlx->win_ptr, &mouse_event, mlx);
	mlx_hook(mlx->win_ptr, 06, 1, &mouse_params, &mlx);
}

void	init_mlx(t_mlx *mlx, int ac, char *av[])
{
	if (!ft_strncmp("mandelbrot", av[1], ft_strlen(av[1])))
	{
		if (ac > 3)
			help_message();
		mlx->name = 1;
		mlx->max_r = 1;
		mlx->min_r = -2;
		mlx->min_i = -1.5;
		mlx->max_i = mlx->min_i + (mlx->max_r - mlx->min_r) * WIN_H / WIN_W;
	}
	if (!ft_strncmp("julia", av[1], ft_strlen(av[1])))
	{
		mlx->name = 2;
		mlx->max_r = 2;
		mlx->min_r = -2;
		mlx->min_i = -2;
		mlx->max_i = mlx->min_i + (mlx->max_r - mlx->min_r) * WIN_H / WIN_W;
		get_julia_params(mlx, av);
	}
	mlx->palette = ft_atoi(av[2]);
	mlx->max_iter = 100;
	mlx->zoom_rate = 0.05;
}

int	main(int ac, char *av[])
{
	t_mlx	mlx;

	if (ac < 3 || ac > 5 || !check_av(av))
		help_message();
	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "fractol");
	if (mlx.win_ptr == NULL)
		destroy_flag(&mlx, 1);
	init_mlx(&mlx, ac, av);
	set_hooks(&mlx);
	new_img(&mlx);
	navigation();
	mlx_loop(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
