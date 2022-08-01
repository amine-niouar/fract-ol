/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:21:25 by aniouar           #+#    #+#             */
/*   Updated: 2022/08/01 09:36:22 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int	mh(int keycode, int x, int y ,t_hook *h)
{
	// 69 +
	// 78
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		h->f->start += 0.4;
		h->f->end -= 0.4;
		//h->f->iteration -= 100;
		//h->f->max_iteration -= 100; 
	}
	else if(keycode == 4)
	{
		h->f->start -= 0.4;
		h->f->end += 0.4;
		//h->f->iteration += 100;
	}
	printf("typo %i\n",h->f->type);
	fractol(h->f,h->i);
	mlx_put_image_to_window(h->m->mlx,h->m->win, h->i->img, 0, 0);
	return (0);
}


int	kh(int keycode ,t_hook *h)
{
	if(keycode == 53)
	{
			mlx_destroy_window(h->m->mlx,h->m->win);
			exit (0);
	}
	return (0);
}

void set_mlx(t_mwi **m,t_fractol *f)
{
	
	(*m)->mlx = mlx_init();
	(*m)->win = mlx_new_window((*m)->mlx, f->win_x, f->win_y, "fract-ol");
	(*m)->img.img =  mlx_new_image((*m)->mlx, 1920, 1080);
	(*m)->img.addr =  mlx_get_data_addr(&(*m)->img, &(*m)->img.bits_per_pixel, &(*m)->img.line_length,
								&(*m)->img.endian);
}

void set_hook(t_hook **h,t_mwi *m,t_fractol *f,t_data *i)
{
	(*h)->f	= f;
	(*h)->m = m;
	(*h)->i = i;
}

t_data set_img(t_mwi **m,t_fractol *chosen)
{
	t_data img;

	img.img = mlx_new_image((*m)->mlx, chosen->win_x, chosen->win_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	return (img);
}

int	main(int ac,char **av)
{
	t_fractol *fract;
	t_fractol *chosen;
	t_hook *hook;
	t_mwi *m;
	t_data img;
	int index;


	if(ac ==  2)
	{
		index = ft_atoi(av[1]);
		fract = set_multiple_fractol(9);
		chosen = choose_fractol(fract,index);
		if(chosen == 0)
			printf("not found\n");
		else
		{
			hook =  malloc(sizeof(t_hook));
			m = malloc(sizeof(t_mwi));
			set_mlx(&m,chosen);
		    img = set_img(&m,chosen);
			set_hook(&hook,m,chosen,&img);
		    fractol(chosen,&img);
			mlx_put_image_to_window(m->mlx,m->win, img.img, 0, 0);
			mlx_mouse_hook(hook->m->win, mh, hook);
			mlx_key_hook(hook->m->win, kh, hook);
			mlx_loop(m->mlx);
		}
	}

}