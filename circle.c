/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:10:26 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/21 19:46:31 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int *center_pixel(t_data *img,int x_win,int y_win)
{
    int *center_xy;

    center_xy = malloc(sizeof(int) * 2);

    my_mlx_pixel_put(img, (x_win/2), (y_win/2),0x00FF0000);
    center_xy[0] = x_win / 2;
    center_xy[1] = y_win/2;
    return (center_xy);
}

void func(t_data *img,int *center_xy)
{
    // equation
    // (x−a)2 + (y−b)2 = r2
    // (y - b)2 = r2 - (x - a)2
    // (y - b) = square( r2 - (x - a)2 )
    // y = square( r2 - (x - a)2 ) + b
    // 

    int y;
    float z;
    float i;
    int ny;
    int r;
    int x;

   
    x = center_xy[0] - 100;
    i = 0.1;
    r = x + 200;
    while(x <= r)
    {
        //y = sqrt(ft_iterative_power(100,2) - ft_iterative_power((x - center_xy[0]),2)) + center_xy[1];
        z = x + y*i;
        ny = center_xy[1] + (center_xy[1] - y);
        printf("x:%i y:%i ny:%i z:%f\n",x,y,ny,z);
        if(y == -2147483648)
            break;
        my_mlx_pixel_put(img, x, y,0x00FF0000);
        if(z < 1062 )
            my_mlx_pixel_put(img, x, z,0x00FF0000);
        my_mlx_pixel_put(img, x, ny,0x00FF0000);
        x++;
    }
    
   
    
}


void circle(t_data *img,int x_win,int y_win)
{
    int *center_xy;
    center_xy = center_pixel(img,x_win,y_win);

    
    //draw_d(img,center_xy,400);

    /*
    half_rd(img,center_xy,400);
    half_bd(img,center_xy,400);
    small_sqaure(img,center_xy);
    */
    func(img,center_xy);
}
