/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:34:50 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/19 17:47:51 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data, int x, int y)
{
	data->fractol->zoom += 0.003;
	data->fractol->gx = x;
	data->fractol->gy = y;
	get_real_index(data->fractol);
	data->fractol->tab = data->fractol->tab / data->fractol->zoom;
	data->fractol->scale = data->fractol->tab / data->fractol->size;
	data->fractol->zoom_x = data->fractol->x - (data->fractol->tab / 2);
	data->fractol->zoom_y = data->fractol->y + (data->fractol->tab / 2);
	data->fractol->gx = 0.0;
	data->fractol->gy = 0.0;
	data->fractol->limit += 1;
	draw_fr(data->img, data, data->fractol);
}

void	zoom_out(t_data *data, int x, int y)
{
	if (data->fractol->tab < 5 && data->fractol->zoom > 1)
	{
		data->fractol->zoom -= 0.003;
		data->fractol->gx = x;
		data->fractol->gy = y;
		get_real_index(data->fractol);
		data->fractol->tab = data->fractol->tab * data->fractol->zoom;
		data->fractol->scale = data->fractol->tab / data->fractol->size;
		data->fractol->zoom_x = data->fractol->x - (data->fractol->tab / 2);
		data->fractol->zoom_y = data->fractol->y + (data->fractol->tab / 2);
		data->fractol->gx = 0.0;
		data->fractol->gy = 0.0;
		data->fractol->limit -= 1;
		draw_fr(data->img, data, data->fractol);
	}
}
