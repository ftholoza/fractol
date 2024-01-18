/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:19:58 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/15 20:54:37 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	detector(char *name, t_data *data, int argc)
{
	int	i;

	i = 0;
	if (argc > 2 || argc < 2)
		i = 1;
	else
	{
		if (ft_strncmp(name, "mandelbrot", 10) == 0)
			data->nfr = 1;
		else if (ft_strncmp(name, "julia", 5) == 0)
			data->nfr = 2;
		else if (ft_strncmp(name, "burning_ship", 12) == 0)
			data->nfr = 3;
		else
			i = 1;
	}
	if (i == 1)
	{
		write(1, "Available fractals:\nmandelbrot\njulia\nburning_ship", 49);
		free(data->fractol);
		free(data);
		exit(0);
	}
	return (1);
}

int	close_win(t_data *data)
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

int	main(int argc, char **argv)
{
	t_fractol		*fractol;
	t_data			*data;
	t_img			*img;
	char			*n;

	n = NULL;
	fractol = init_fractol();
	data = init_data(fractol);
	if (!detector(argv[1], data, argc))
		exit(0);
	data->mlx_ptr = mlx_init();
	data->win_ptr
		= mlx_new_window(data->mlx_ptr, fractol->size, fractol->size, n);
	img = init_img(data);
	draw_fr(img, data, fractol);
	mlx_mouse_hook(data->win_ptr, &mouse_event, data);
	mlx_key_hook(data->win_ptr, &key_event, data);
	mlx_hook(data->win_ptr, 17, 0, &close_win, data);
	mlx_loop(data->mlx_ptr);
}
