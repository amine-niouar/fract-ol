/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:41:55 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/21 12:42:20 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double n,double start1,double stop1,double start2,double stop2)
{
    return ((n - start1) / (stop1 - start1) * (stop2 - start2) + start2);
}




int	create_trgb(int t, int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}