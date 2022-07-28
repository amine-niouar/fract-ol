/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:13:20 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/27 13:11:40 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


//(n - start1) / (stop1 - start1) * (stop2 - start2) + start2

void complex(t_data *img,int x_win,int y_win,double xz,double yz)
{
    int x;
    double a;
    double b;
    double ca;
    double cb;
    double z;
    double aa;
    double bb;
    double ab_two;
    int bright;
    int color;
    int n;
    int y;


    x = 0;
    while(x < x_win)
    {
        y = 0;
        while (y < y_win)
        {
            a = map((double)x,200,x_win,-.5,.5);
            b = map((double)y,0,y_win,-.5,.5);
            ca = a;
            cb = b;
            z = 0;
            n = 0;
            while(n < 100)
            {
                aa = pow(a,2) - pow(b,2);
                bb = 2 * a * b;
        
                a = aa + ca;
                b = bb + cb;
                // Programe it better
                if(fabs(aa + bb) > 50)
                    break;
                n++;
            }
           if(n == 100)
            {
                 my_mlx_pixel_put(img,x,y,0);
            }

            else if(n >= 16 && n < 100)
                 my_mlx_pixel_put(img,x,y,WHITE);
            else    
                 my_mlx_pixel_put(img,x,y,MAD);

            y++;
        }
        x++;
    }    
}