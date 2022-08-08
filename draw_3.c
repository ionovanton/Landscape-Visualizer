/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:43:30 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 01:40:09 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric(t_point *a, t_point *b, t_opt *opt)
{
	float	angle;

	if (opt->projection == P_FLAT)
		return ;
	angle = opt->angle + opt->angle_shift;
	a->x = (a->x - a->y) * cos(angle);
	a->y = (a->x + a->y) * sin(angle) - a->z;
	b->x = (b->x - b->y) * cos(angle);
	b->y = (b->x + b->y) * sin(angle) - b->z;
}

static void	zoom(t_point *a, t_point *b, t_opt *opt)
{
	a->x *= (opt->zoom + opt->zoom_shift);
	a->y *= (opt->zoom + opt->zoom_shift);
	b->x *= (opt->zoom + opt->zoom_shift);
	b->y *= (opt->zoom + opt->zoom_shift);
}

static void	offset(t_point *a, t_point *b, t_opt *opt)
{
	a->x += opt->offset + opt->offset_x;
	a->y += opt->offset + opt->offset_y;
	b->x += opt->offset + opt->offset_x;
	b->y += opt->offset + opt->offset_y;
}

void	gfx_options(t_point *a, t_point *b, t_opt *opt)
{
	zoom(a, b, opt);
	isometric(a, b, opt);
	offset(a, b, opt);
}
