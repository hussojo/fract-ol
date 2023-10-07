/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhusso <jhusso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:37:23 by jhusso            #+#    #+#             */
/*   Updated: 2023/05/01 14:44:00 by jhusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	get_res(const char *nptr, double res)
{
	double	fac;

	fac = 0.1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	if (*nptr == '.')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res + ((*nptr - '0') * fac);
		fac = fac * 0.1;
		nptr++;
	}
	return (res);
}

double	ft_atof(const char *nptr)
{
	int		sign;
	double	res;

	sign = 1;
	res = 0.0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13) || *nptr == 46)
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	res = get_res(nptr, res);
	return ((double)res * sign);
}
