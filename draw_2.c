/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:46:48 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:47:37 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point *p, t_gfx *g)
{
	const int	x = (int)p->x;
	const int	y = (int)p->y;
	char		*dst;

	if (x >= 0 && x < STD_WIDTH && y >= 0 && y < STD_HEIGHT)
	{
		dst = g->img->address + (int)(x * g->img->bpp / 8) \
		+ (int)(y * g->img->length);
		*(unsigned int *)dst = p->color;
	}
}

void	put_background(int color, t_gfx *g)
{
	t_point	ptr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ptr.color = color;
	ptr.z = 0;
	while (x < STD_WIDTH)
	{
		y = 0;
		while (y < STD_HEIGHT)
		{
			ptr.x = x;
			ptr.y = y;
			put_pixel(&ptr, g);
			y++;
		}
		x++;
	}	
}

static int	get_data(int start, int end, double pct)
{
	return ((int)((1 - pct) * start + pct * end));
}

static double	get_percent(int start, int end, int cur)
{
	double	dist;
	double	pos;

	dist = end - start;
	pos = cur - start;
	if (dist)
		return (pos / dist);
	else
		return (1.0);
}

int	gfx_get_color(t_point cur, t_point start, t_point end, t_point delta)
{
	double	pct;
	int		r;
	int		g;
	int		b;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		pct = get_percent(start.x, end.x, cur.x);
	else
		pct = get_percent(start.y, end.y, cur.y);
	r = get_data((start.color >> 16) & 255, (end.color >> 16) & 255, pct);
	g = get_data((start.color >> 8) & 255, (end.color >> 8) & 255, pct);
	b = get_data(start.color & 255, end.color & 255, pct);
	return ((r << 16) | (g << 8) | b);
}
