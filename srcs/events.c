/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:20:28 by ftholoza          #+#    #+#             */
/*   Updated: 2024/01/17 20:18:58 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_w(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img);
	free(data->fractol);
	free(data);
	exit(0);
}

void	key_moves(t_data *data, int code)
{
	get_real_index(data->fractol);
	if (code == 65361)
	{
		data->fractol->zoom_x -= data->fractol->scale * 10;
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65363)
	{
		data->fractol->zoom_x += data->fractol->scale * 10;
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65362)
	{
		data->fractol->zoom_y += data->fractol->scale * 10;
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65364)
	{
		data->fractol->zoom_y -= data->fractol->scale * 10;
		draw_fr(data->img, data, data->fractol);
	}
}

void	constant_chng(t_data *data, int code)
{
	if (code == 65432)
	{
		data->fractol->cx += 0.01;
		printf("%f\n", data->fractol->cx);
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65430)
	{
		data->fractol->cx -= 0.01;
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65431)
	{
		data->fractol->cy += 0.01;
		printf("%f\n", data->fractol->cy);
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65433)
	{
		data->fractol->cy -= 0.01;
		draw_fr(data->img, data, data->fractol);
	}
}

int	key_event(int code, t_data *data)
{
	key_moves(data, code);
	constant_chng(data, code);
	if (code == 99)
	{
		data->img->val_b += 5;
		data->img->val_g += 1;
		data->img->val_r += 10;
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65307)
		close_w(data);
	if (code == 65434)
	{
		data->fractol->limit += 10;
		draw_fr(data->img, data, data->fractol);
	}
	if (code == 65429)
	{
		data->fractol->limit -= 10;
		draw_fr(data->img, data, data->fractol);
	}
	return (0);
}

int	mouse_event(int code, int x, int y, t_data *data)
{
	if (code == 4)
		zoom_in(data, x, y);
	if (code == 5)
		zoom_out(data, x, y);
	return (0);
}
