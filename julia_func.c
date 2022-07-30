/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:38:22 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/28 10:40:20 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void set_complex(double ***sets,double r,double i,int index)
{
    double **tab;

    tab = *sets;
    
    tab[index] = malloc(sizeof(double) * 2);
    
    if(tab[index])
    {
        tab[index][0] = r;
        tab[index][1] = i;
    }
}

void print_tabs(double **sets, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        printf("%lf %lf\n",sets[i][0],sets[i][1]);
        i++;
    }
}

double **julia_set()
{
    double **sets;
    int i;

    i = 0;
    sets = malloc(sizeof(double *) * 7);
    if (!sets)
        return (0);
    // −0.70176 − 0.3842i
    //  0.45 + 0.1428i
    // 0.285 + 0.01i
    //  0.285 + 0i
    // −0.8i
    // −0.7269 + 0.1889i
    //  −0.8 + 0.156i
    // −0.835 − 0.2321i 
    // −0.8 + 0.156i
    set_complex(&sets,0.45,0.142,i++);
    set_complex(&sets,0.285,0.01,i++);
    set_complex(&sets,0.285,0,i++);
    set_complex(&sets,0,-0.8,i++);
    set_complex(&sets,-0.7269,0.1889,i++);
    set_complex(&sets,-0.8,0.156,i++);
    set_complex(&sets,-0.4,0.6,i++);
    //print_tabs(sets,5);
    return (sets);
}
