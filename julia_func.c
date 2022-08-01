/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:38:22 by aniouar           #+#    #+#             */
/*   Updated: 2022/08/01 09:02:36 by aniouar          ###   ########.fr       */
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

void set_iteration(int ***sets,int it,int maxit,int index)
{
    int **tab;

    tab = *sets;
    
    tab[index] = malloc(sizeof(int) * 2);
    
    if(tab[index])
    {
        tab[index][0] = it;
        tab[index][1] = maxit;
    }
}


void set_fractol(t_fractol **f,double *complex,int *iterations,int type)
{
    t_fractol *fract;

    fract = *f;
    fract->type = type;
    fract->iteration = iterations[0];
    fract->max_iteration = iterations[1];
    fract->win_x = 1920;
    fract->win_y = 1080;
    fract->ca = complex[0];
    fract->cb = complex[1];
    fract->start = -2;
    fract->end = 2;
    fract->next = 0;  
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


void print_fracts(t_fractol *current)
{

    while (current)
    {
        printf("%lf %lf %i %i\n",current->ca,current->cb,current->iteration,current->max_iteration);
        current = current->next;
    }
}


double **set_complexes(int size)
{
    double **sets;
    int i;

    i = 0;
    sets = malloc(sizeof(double *) * size);
    if (!sets)
        return (0);
        //  0.45 + 0.1428i
        // -1.2 + 0.77
        // -1.476 + 0
        // 0.28 + 0.008
        // 0.355 + 0.355
        // -0.54 + 0.54i
        //  -0.4 + -0.59i
        //  -0.54 + 0.54i
        //  0.355534 - 0.337292i
    set_complex(&sets,(double)0,(double)0,i++);
    set_complex(&sets,0.45,0.1428,i++);
    set_complex(&sets,0.285,0.01,i++);
    set_complex(&sets,0.285,0,i++);
    set_complex(&sets,0,-0.8,i++);
    set_complex(&sets,-0.7269,0.1889,i++);
    set_complex(&sets,-0.8,0.156,i++);
    set_complex(&sets,-0.4,0.6,i++);
    set_complex(&sets, -0.355534,0.337292,i++);
    return (sets);
}

int **set_iterations(int size)
{
    int **sets;
    int i;

    i = 0;
    sets = malloc(sizeof(int *) * size);
    if (!sets)
        return (0);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    set_iteration(&sets,100,300,i++);
    return (sets);
}

t_fractol *set_multiple_fractol(int size)
{
    t_fractol *head;
    t_fractol *prev;
    double **complexes;
    int **iterations;
    t_fractol *current;
    int i;
    
    complexes = set_complexes(size);
    iterations = set_iterations(size);
    head = 0;
    i = -1;
    while(++i < size)
    {
    
        current =  malloc(sizeof(t_fractol));
        if(!current)
            return (0);
        set_fractol(&current,complexes[i],iterations[i],i);
        if(head == 0)
        {
            head = current;
            prev = head;
        }
        else
        {
            prev->next = current;
            prev = current;
        }
    }
    return (head);
}

t_fractol *choose_fractol(t_fractol *f,int index)
{
    int i;
    t_fractol *current;
    
    i = 0;
    current = f;
    while(current)
    {{
        if(i == index)
            return (current);
        current = current->next;
        i++;
    }}
    return (0);
}
