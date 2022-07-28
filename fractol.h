/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:59 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/27 11:58:09 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define red  	0x00FF0000
#define BLUE 	0x000000FF
#define YELLOW  0x00FFFF00
#define WHITE 	0x00FFFFFF
#define MAD 	0x00061061
#define WIRED   0x009b6f8a


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void square(t_data *img);
void circle(t_data *img,int x_win,int y_win);
void complex(t_data *img,int x_win,int y_win,double xz,double yz);
/* common */
double map(double n,double start1,double stop1,double start2,double stop2);
int	create_trgb(int t, int r, int g, int b);
/* end common */

/* Julia handle */
void julia(t_data *img,int x_win,int y_win);
/* end Julia handle */

/* start math */
int *center_pixel(t_data *img,int x_win,int y_win);
/* end math */