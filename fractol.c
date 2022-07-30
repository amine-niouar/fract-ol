/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:21:25 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/30 13:37:10 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int value;
	int iteration;
	int low;
	double ca;
	double cb;
	double xx;
	double yy;
	t_data *img;
}				t_vars;

int	mh(int keycode, t_vars *vars)
{
	// 69 +
	// 78
	if (keycode == 69)
	{
		vars->xx += 0.4;
		vars->yy -= 0.4;
		
	}
	else if(keycode == 78)
	{
		vars->xx -= 0.4;
		vars->yy += 0.4;
	}
	julia(vars->img,1920,1080,vars->ca,vars->cb,vars->iteration,vars->low,vars->xx,vars->yy);
		mlx_put_image_to_window(vars->mlx,vars->win, vars->img->img, 0, 0);
	return (0);
}

int	main(int ac,char **av)
{

	t_vars	vars;
	t_data	img;
	double **jls;
	double x;
	double y;
	int index;
	int value;

	value = 1;

	(void)ac;


	x =  -2;
	y = 2;
	index = ft_atoi(av[1]) - 1;

	jls = julia_set();
	
	vars.mlx = mlx_init();
	vars.value = 1;
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	vars.img  = &img;
	vars.iteration = ft_atoi(av[2]);
	vars.low = ft_atoi(av[3]);

	vars.xx = -2;
	vars.yy = 2;
	


	//my_mlx_pixel_put(&img, 0, 0,0x00FF0000);

	//square(mlx,mlx_win,&img);
	//circle(&img,1920,1080);
	mlx_key_hook(vars.win, mh, &vars);
	if(index >= 0)
	{
		vars.ca = jls[index][0];
		vars.cb = jls[index][1];
		julia(&img,1920,1080,jls[index][0],jls[index][1],ft_atoi(av[2]),ft_atoi(av[3]),-2,2);
	}
	else
		complex(&img,1920,1080,x,y,ft_atoi(av[2]),ft_atoi(av[3]));

		
	//complex(&img,1000,1000,x,y,ft_atoi(av[2]),ft_atoi(av[3]));
	mlx_put_image_to_window(vars.mlx,vars.win, img.img, 0, 0);


	
	

	
	mlx_loop(vars.mlx);
}