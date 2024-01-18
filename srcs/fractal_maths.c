/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:10 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/15 20:20:12 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_img *img, t_fractol *fractol)
{
	double	temp;
	int		iter;
	float	black;

	black = color(0, 0, 0, 0);
	get_real_index(fractol);
	iter = 0;
	while (iter < fractol->limit)
	{
		temp = (fractol->x * fractol->x) - (fractol->y * fractol->y);
		fractol->y = 2 * (fractol->x * fractol->y) + fractol->cy;
		fractol->x = temp + fractol->cx;
		if ((fractol->x * fractol->x) + (fractol->y * fractol->y) > __DBL_MAX__)
			break ;
		iter++;
	}
	if (iter == fractol->limit)
		img_pix_put(img, fractol->gx, fractol->gy, black);
	else
		img_pix_put(img, fractol->gx, fractol->gy, get_color(iter, img));
}

void	mandelbrot(t_img *img, t_fractol *fractol)
{
	double	temp;
	int		iter;
	float	black;

	black = color(0, 0, 0, 0);
	get_real_index(fractol);
	iter = 0;
	fractol->cx = fractol->x;
	fractol->cy = fractol->y;
	while (iter < fractol->limit)
	{
		temp
			= (fractol->x * fractol->x) - (fractol->y * fractol->y);
		fractol->y = 2 * (fractol->x * fractol->y) + fractol->cy;
		fractol->x = temp + fractol->cx;
		if ((fractol->x * fractol->x) > __DBL_MAX__)
			break ;
		iter++;
	}
	if (iter == fractol->limit)
		img_pix_put(img, fractol->gx, fractol->gy, black);
	else
		img_pix_put(img, fractol->gx, fractol->gy, get_color(iter, img));
}

void	burning_ship(t_img *img, t_fractol *fractol)
{
	double	temp;
	int		iter;
	float	black;

	black = color(0, 0, 0, 0);
	get_real_index(fractol);
	iter = 0;
	fractol->cx = fractol->x;
	fractol->cy = fractol->y;
	while (iter < fractol->limit)
	{
		temp
			= (fractol->x * fractol->x) - (fractol->y * fractol->y);
		fractol->y = fabs(2 * (fractol->x * fractol->y) + fractol->cy);
		fractol->x = fabs(temp + fractol->cx);
		if ((fractol->x * fractol->x) > __DBL_MAX__)
			break ;
		iter++;
	}
	if (iter == fractol->limit)
		img_pix_put(img, fractol->gx, fractol->gy, black);
	else
		img_pix_put(img, fractol->gx, fractol->gy, get_color(iter, img));
}

void	get_real_index(t_fractol *fractol)
{
	double	start_x;
	double	start_y;

	start_x = fractol->zoom_x;
	start_y = fractol->zoom_y;
	fractol->x = start_x + (fractol->gx * fractol->scale);
	fractol->y = start_y - (fractol->gy * fractol->scale);
}

void	get_index_zoom(t_fractol *fractol, int x, int y)
{
	fractol->zoom_x = fractol->tab / 2 + (x * fractol->scale);
	fractol->zoom_y = fractol->tab / 2 - (y * fractol->scale);
}
