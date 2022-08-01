/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:51:33 by aniouar           #+#    #+#             */
/*   Updated: 2022/08/01 09:20:12 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_iterations(t_fractol *f,double a,double b)
{
    int n;
    double aa;
    double bb;

    if (f->type == 0)
    {
        f->ca = a;
        f->cb = b;
    }
    n = 0;
    while(n < f->iteration)
    {
        aa = pow(a,2) - pow(b,2);
        bb = 2 * a * b;

        a = aa + f->ca;
        b = bb + f->cb;
        if(fabs(aa + bb) > f->max_iteration)
            break;
        n++;
    }
    return (n);
}

void f_each_pixel(t_fractol *f,int x,t_data *img)
{
    int y;
    int result;
    double a;
    int color;
    double b;

    
    y = -1;
    while(++y < f->win_y)
    {
        a = map((double)x,0,f->win_x,f->start,f->end);
        b = map((double)y,0,f->win_y,f->start,f->end);
        result = get_iterations(f,a,b);

        if(result == f->iteration)
        {
             color = get_color(result,f->max_iteration);
              my_mlx_pixel_put(img,x,y,color);
        }
            
        else
        {
             color = get_color(result,f->max_iteration*10);
             my_mlx_pixel_put(img,x,y,color);
        }
    }
}

void fractol(t_fractol *f,t_data *img)
{
      int x;

     
      x = -1;
      while(++x < f->win_x)
          f_each_pixel(f,x,img);
}