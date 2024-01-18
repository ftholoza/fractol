/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:13:03 by ftholoza          #+#    #+#             */
/*   Updated: 2023/12/15 20:21:43 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_color(int iter, t_img *img)
{
	int		val;
	int		r;
	int		g;
	int		b;

	r = (iter * img->val_r) % 256;
	g = (iter * img->val_g) % 256;
	b = (iter * img->val_b) % 256;
	val = color(0, r, g, b);
	return (val);
}
