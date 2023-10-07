/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:07:14 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/03 18:10:38 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_av(char **av)
{
	int	palette_num;

	if (ft_strncmp("mandelbrot", av[1], ft_strlen(av[1]))
		&& ft_strncmp("julia", av[1], ft_strlen(av[1])))
		help_message();
	palette_num = ft_atoi(av[2]);
	if (palette_num && palette_num < 4)
		return (1);
	else
		return (0);
}

void	get_julia_params(t_mlx *mlx, char **av)
{
	if (!av[3] || !av[4])
		help_julia();
	if (av[3] && av[4])
	{
		mlx->p1 = ft_atof(av[3]);
		mlx->p2 = ft_atof(av[4]);
	}
	else
		help_message();
}
