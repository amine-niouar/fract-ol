/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:21:25 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/30 19:42:58 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/*
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
*/

void set_mlx(t_mwi **m,t_fractol *f)
{
	
	(*m)->mlx = mlx_init();
	(*m)->win = mlx_new_window((*m)->mlx, f->win_x, f->win_y, "fract-ol");
	(*m)->img.img =  mlx_new_image((*m)->mlx, 1920, 1080);
	(*m)->img.addr =  mlx_get_data_addr(&(*m)->img, &(*m)->img.bits_per_pixel, &(*m)->img.line_length,
								&(*m)->img.endian);
}

int	main(int ac,char **av)
{
	/*
	t_vars	vars;
	t_data	img;
	double **jls;
	double x;
	double y;
	int index;
	int value;

	value = 1;

	


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


	
	

	
	
	*/

	
	t_fractol *fract;
	t_fractol *chosen;
	t_mwi *m;
	t_data img;
	int index;


	
	if(ac ==  2)
	{
		index = ft_atoi(av[1]);
		fract = set_multiple_fractol(8);
		chosen = choose_fractol(fract,index);
		if(chosen == 0)
			printf("not found\n");
		else
		{
			
			m = malloc(sizeof(t_mwi));
			img.img = mlx_new_image(m->mlx, chosen->win_x, chosen->win_y);
			img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
			set_mlx(&m,chosen);
			printf("test\n");
		     //fractol(chosen,m);
			  my_mlx_pixel_put(&img,5,5,BLUE);
			 mlx_put_image_to_window(m->mlx,m->win, img.img, 0, 0);
			mlx_loop(m->mlx);
		}
	}

}