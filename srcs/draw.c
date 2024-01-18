/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:16:19 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/15 14:12:51 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fr(t_img *img, t_data *data, t_fractol *fractol)
{
	if (data->nfr == 2)
		data->name = &julia;
	if (data->nfr == 1)
		data->name = &mandelbrot;
	if (data->nfr == 3)
		data->name = &burning_ship;
	while (fractol->gx < fractol->size)
	{
		while (fractol->gy < fractol->size)
		{
			data->name(img, fractol);
			fractol->gy++;
		}
		fractol->gy = 0;
		fractol->gx++;
	}
	fractol->gx = 0;
	fractol->gy = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
}
