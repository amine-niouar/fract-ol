/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:20:24 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/19 09:23:47 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb > 0)
	{
		i = 1;
		while (i * i != nb)
		{
			if (i >= 46340)
				return (0);
			i++;
		}
		return (i);
	}
	return (0);
}

int	ft_iterative_power(int nb, int power)
{
	int	r;

	r = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		r = r * nb;
		power--;
	}
	return (r);
}