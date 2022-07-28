/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:21:25 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/27 13:12:39 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data *img;
}				t_vars;

int	mouse_hook(int keycode, t_vars *vars)
{
	/*
	if  (keycode == 4)
	{
		vars->x = vars->x + 0.5;
		vars->y = vars->y - 0.5;
	}
	*/
	
	mlx_destroy_window(vars->mlx, vars->win);
	//printf("%i\n",vars->x)
	//complex(vars->img,1920,1080,-2,1);
	//mlx_put_image_to_window(vars->mlx,vars->win, vars->img->img, 0, 0);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_vars	vars;
	t_data	img;
	double x;
	double y;

	x = -2;
	y = 2;
	
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img  = &img;


	//my_mlx_pixel_put(&img, 0, 0,0x00FF0000);

	//square(mlx,mlx_win,&img);
	//circle(&img,1920,1080);
	
	julia(&img,1920,1080);
	//complex(&img,1920,1080,x,y);
	mlx_put_image_to_window(vars.mlx,vars.win, img.img, 0, 0);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}