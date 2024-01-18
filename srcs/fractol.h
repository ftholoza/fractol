/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:04:40 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/15 20:48:00 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "math.h"
# include "stdlib.h"
# include <mlx.h>
# include <stdio.h>
# include <limits.h>
# include <X11/keysym.h>
# include <stddef.h>
# include <unistd.h>

typedef struct t_fractol
{
	double					x;
	double					y;
	int						limit;
	int						gx;
	int						gy;
	int						size;
	double					scale;
	double					zoom;
	double					tab;
	double					zoom_x;
	double					zoom_y;
	double					key_mvx;
	double					key_mvy;
	double					cx;
	double					cy;
}	t_fractol;

typedef struct t_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		val_r;
	int		val_g;
	int		val_b;
}	t_img;

typedef struct t_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			nfr;
	void		(*name)(t_img *, t_fractol *);
	t_img		*img;
	t_fractol	*fractol;
}	t_data;

t_fractol	*init_fractol(void);
t_data		*init_data(t_fractol *fractol);
t_img		*init_img(t_data *data);
void		julia(t_img *img, t_fractol *fractol);
int			color(int t, int r, int g, int b);
int			get_color(int iter, t_img *img);
void		draw_fr(t_img *img, t_data *data, t_fractol *fractol);
void		*create_image(void *init);
void		img_pix_put(t_img *img, int x, int y, int color);
int			mouse_event(int code, int x, int y, t_data *data);
int			key_event(int code, t_data *data);
void		get_real_index(t_fractol *fractol);
void		get_index_zoom(t_fractol *fractol, int x, int y);
void		mandelbrot(t_img *img, t_fractol *fractol);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		burning_ship(t_img *img, t_fractol *fractol);
void		zoom_in(t_data *data, int x, int y);
void		zoom_out(t_data *data, int x, int y);

#endif