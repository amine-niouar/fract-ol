/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:36:24 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/27 13:16:14 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


//(n - start1) / (stop1 - start1) * (stop2 - start2) + start2


void julia(t_data *img,int x_win,int y_win)
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
    int maxiterations;
    int color;
    int n;
    int y;


    maxiterations = 60;
    x = 0;
    while(x < x_win)
    {
        y = 0;
        while (y < y_win)
        {
            a = map((double)x,200,x_win,-2,2);
            b = map((double)y,0,y_win,-2,2);
            // 0.3 + 0.5 i
            // 0.285 + 0.013 i
            //0.285 + 0.01
            //c = -0.4 + -0.59i
            ca =   -0.4;
            cb =  0.59;
            z = 0;
            n = 0;
            while(n < 100)
            {
                aa = pow(a,2) - pow(b,2);
                bb = 2 * a * b;
        
                a = aa + ca;
                b = bb + cb;
                // Programe it better
                if(fabs(aa + bb) > 20)
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
                 my_mlx_pixel_put(img,x,y,BLUE);

            
           
            y++;
        }
        x++;
    }    
    



    
   

    
    

    
    //printf("x:%i y:%i\n",center[0],center[1]);
   
}