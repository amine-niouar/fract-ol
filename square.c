/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:08:34 by aniouar           #+#    #+#             */
/*   Updated: 2022/06/10 12:16:25 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void line_vertical(int x,t_data *img)
{
	int i;
	int y;
	int z;
	

	y = 100;
	i = 0;
	while(i < 500)
	{
		my_mlx_pixel_put(img, x, y,0x00FF0000);
		y += 1;
		i += 1;
	}
	
}
void line_horizontal(int y,t_data *img)
{
	int i;
	int x;
	int z;
	

	x = 500;
	i = 0;
	while(i < 500)
	{
		my_mlx_pixel_put(img, x, y,0x00FF0000);
		x += 1;
		i += 1;
	}
	
}


void square(t_data *img)
{
	line_vertical(500,img);
	line_vertical(1000,img);
	line_horizontal(100,img);
	line_horizontal(600,img);
}