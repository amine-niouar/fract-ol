/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:59 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/31 19:21:31 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

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

typedef struct	s_mwi {
    void	*mlx;
	void	*win;
	t_data img;
} t_mwi;

typedef struct	s_fractol {
	int type;
	int value;
	int iteration;
	int max_iteration;
	int win_x;
	int win_y;
	double ca;
	double cb;
	double start;
	double end;
	struct	s_fractol *next;
}				t_fractol;


typedef struct	s_hook {
	t_fractol *f;
	t_mwi *m;
	t_data *i;
} t_hook;	




void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void square(t_data *img);
void circle(t_data *img,int x_win,int y_win);
void complex(t_data *img,int x_win,int y_win,double xz,double yz,int iteration,int low);
/* common */
double map(double n,double start1,double stop1,double start2,double stop2);
int    get_color(int i,int l);
/* end common */

/* Julia handle */
void julia(t_data *img,int x_win,int y_win,double r,double i,int iteration,int low,double xx,double yy);
t_fractol *set_multiple_fractol(int size);
t_fractol *choose_fractol(t_fractol *f,int index);
void print_fracts(t_fractol *current);
/* end Julia handle */

/* start math */
int *center_pixel(t_data *img,int x_win,int y_win);
/* end math */

/* libft */
int	ft_atoi(const char *str);
/* end libft */

void fractol(t_fractol *f,t_data *img);