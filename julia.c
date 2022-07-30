/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:36:24 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/30 12:36:54 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


void julia(t_data *img,int x_win,int y_win,double r,double i,int iteration,int low,double xx,double yy)
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
            a = map((double)x,0,x_win,xx,yy);
            b = map((double)y,0,y_win,xx,yy);
            
            //dprintf(fd,"%lf %lf\n",a,b);
            // 0.3 + 0.5 i
            // 0.285 + 0.013 i
            //0.285 + 0.01
            //c = -0.4 + -0.59i
            ca =  r;
            cb =  i;
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
    //close(fd);    
}