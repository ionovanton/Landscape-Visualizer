/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:22:46 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 01:49:03 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	refresh(t_gfx *g)
{
	mlx_clear_window(g->mlx, g->win);
	put_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img->ptr, 0, 0);
	return (0);
}

static void	projection(int key, t_gfx *g)
{
	if (key == KEY_1)
	{
		g->opt->projection = P_ISOMETRIC;
		g->opt->angle = STD_ANGLE;
	}
	else if (key == KEY_2)
	{
		g->opt->projection = P_SIDE;
		g->opt->angle = 0;
		g->opt->angle_shift = 0;
	}
	else if (key == KEY_3)
		g->opt->projection = P_FLAT;
}

int	hook_dial_key(int key, t_gfx *g)
{
	if (key == KEY_W || key == KEY_UP)
		g->opt->offset_y -= SHIFT_POS;
	else if (key == KEY_S || key == KEY_DOWN)
		g->opt->offset_y += SHIFT_POS;
	else if (key == KEY_D || key == KEY_RIGHT)
		g->opt->offset_x += SHIFT_POS;
	else if (key == KEY_A || key == KEY_LEFT)
		g->opt->offset_x -= SHIFT_POS;
	else if (key == KEY_Q)
		g->opt->angle -= SHIFT_ANGLE;
	else if (key == KEY_E)
		g->opt->angle += SHIFT_ANGLE;
	else if (key == KEY_PLUS)
		g->opt->zoom_shift += SHIFT_ZOOM;
	else if (key == KEY_MINUS)
		g->opt->zoom_shift -= SHIFT_ZOOM;
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3)
		projection(key, g);
	else if (key == KEY_ESC)
		em_exit(SUCCESS, g);
	return (refresh(g));
}

int	hook_event_close(t_gfx *g)
{
	em_exit(SUCCESS, g);
	return (0);
}
