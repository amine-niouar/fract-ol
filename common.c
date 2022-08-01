/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:41:55 by aniouar           #+#    #+#             */
/*   Updated: 2022/08/01 08:41:13 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double n,double start1,double stop1,double start2,double stop2)
{
    return ((n - start1) / (stop1 - start1) * (stop2 - start2) + start2);
}


int    get_color(int i,int l)
{
    uint8_t    rgb[3];
    int it;
    int low;
    double    div;

   
    it = i * 9;
    low = l;
    div = (double)it/ (double)low ;
    rgb[0] = 9 * (1 - div) * pow(div, 3) * 255;
    rgb[1] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
    rgb[2] = 9 * pow((1 - div), 3) * div * 255;
    return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}






