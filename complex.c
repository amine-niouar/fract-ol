/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:13:20 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/30 13:21:42 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


//(n - start1) / (stop1 - start1) * (stop2 - start2) + start2

void complex(t_data *img,int x_win,int y_win,double xz,double yz,int iteration,int low)
{
    int x;
    double a;
    double b;
    double ca;
    double cb;
    double z;
    double aa;
    double bb;
    int n;
    int y;
    int color;


    
    x = 0;
    while(x < x_win)
    {
        y = 0;
        while (y < y_win)
        {
            a = map((double)x,0,x_win,xz,yz);
            b = map((double)y,0,y_win,xz,yz);
            ca = a;
            cb = b;
            z = 0;
            n = 0;
            while(n < iteration)
            {
                aa = pow(a,2) - pow(b,2);
                bb = 2 * a * b;
        
                a = aa + ca;
                b = bb + cb;
                // Programe it better
                if(fabs(aa + bb) > low)
                    break;
                n++;
            }
            
               color = get_color(n,low);
                my_mlx_pixel_put(img,x,y,color);

            y++;
        }
        x++;
    }    
}