/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:19:32 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 15:23:52 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_point a, t_point b, t_gfx *g)
{
	t_point	step;
	t_point	cur;
	t_point	dif;
	int		max;

	gfx_options(&a, &b, g->opt);
	step.x = b.x - a.x;
	step.y = b.y - a.y;
	dif = step;
	max = (int)max2f(absf(step.x), absf(step.y));
	step.x /= max;
	step.y /= max;
	cur = a;
	while ((int)(cur.x - b.x) || (int)(cur.y - b.y))
	{
		cur.color = gfx_get_color(cur, a, b, dif);
		put_pixel(&cur, g);
		cur.x += step.x;
		cur.y += step.y;
	}
}

void	put_line(void (*f)(t_point, t_point, t_gfx *), \
t_point *a, t_point *b, t_gfx *g)
{
	f(*a, *b, g);
}

void	put_map(t_gfx *g)
{
	int	x;
	int	y;

	put_background(COLOR_BACKGROUND, g);
	y = 0;
	while (y < g->map->h)
	{
		x = 0;
		while (x < g->map->w)
		{
			if (x < g->map->w - 1)
				put_line(bresenham, g->map->m[y][x], g->map->m[y][x + 1], g);
			if (y < g->map->h - 1)
				put_line(bresenham, g->map->m[y][x], g->map->m[y + 1][x], g);
			x++;
		}
		y++;
	}
}
