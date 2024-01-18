/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:55:29 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/15 20:18:44 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*init_fractol(void)
{
	t_fractol	*fractol;

	fractol = malloc(sizeof(t_fractol));
	fractol->x = 0.0;
	fractol->y = 0.0;
	fractol->gx = 0;
	fractol->gy = 0;
	fractol->key_mvx = 0.0;
	fractol->key_mvy = 0.0;
	fractol->limit = 35;
	fractol->size = 1000;
	fractol->tab = 5;
	fractol->scale = fractol->tab / fractol->size;
	fractol->zoom = 1.0;
	fractol->zoom_x = -2.5;
	fractol->zoom_y = 2.5;
	fractol->cx = -0.75;
	fractol->cy = 0.0;
	return (fractol);
}

t_data	*init_data(t_fractol *fractol)
{
	t_data	*data;
	char	*n;

	n = "fractol";
	data = malloc(sizeof(t_data));
	data->fractol = fractol;
	data->nfr = 0;
	return (data);
}

t_img	*init_img(t_data *data)
{
	t_img	*img;
	int		temp;

	img = malloc(sizeof(t_img));
	img->line_len = 4 * 1000;
	img->bpp = 4;
	img->val_b = 10;
	img->val_g = 1;
	img->val_r = 3;
	img->mlx_img = mlx_new_image(data->mlx_ptr, 1000, 1000);
	img->addr
		= mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &temp);
	data->img = img;
	return (img);
}
