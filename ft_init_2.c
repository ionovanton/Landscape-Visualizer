/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:52:53 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 01:39:28 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_img(t_gfx **g)
{
	(*g)->img = malloc(sizeof(t_image));
	if (!(*g)->img)
	{
		ft_free_backbone(g);
		return (false);
	}
	(*g)->img->ptr = mlx_new_image((*g)->mlx, STD_WIDTH, STD_HEIGHT);
	if (!(*g)->img->ptr)
	{
		free((*g)->img);
		ft_free_backbone(g);
		return (false);
	}
	(*g)->img->address = mlx_get_data_addr((*g)->img->ptr, &(*g)->img->bpp, \
	&(*g)->img->length, &(*g)->img->endian);
	if (!(*g)->img->address)
	{
		ft_free_img(g);
		ft_free_backbone(g);
		return (false);
	}
	return (true);
}

static int	init_opt(t_gfx **g)
{
	(*g)->opt = malloc(sizeof(t_opt));
	if (!(*g)->opt)
		return (false);
	(*g)->opt->projection = P_ISOMETRIC;
	(*g)->opt->offset = STD_OFFSET;
	(*g)->opt->zoom = STD_ZOOM;
	(*g)->opt->angle = STD_ANGLE;
	(*g)->opt->offset_x = 100;
	(*g)->opt->offset_y = 0;
	(*g)->opt->zoom_shift = 0;
	(*g)->opt->angle_shift = 0;
	return (true);
}

static int	init_win(t_gfx **g)
{
	(*g)->win = mlx_new_window((*g)->mlx, STD_WIDTH, STD_HEIGHT, WINDOW_NAME);
	if (!(*g)->win)
	{
		free((*g)->mlx);
		free(*g);
		return (false);
	}
	return (true);
}

static int	init_mlx(t_gfx **g)
{
	(*g)->mlx = mlx_init();
	if (!((*g)->mlx))
	{
		free(*g);
		return (false);
	}
	return (true);
}

int	ft_init_gfx(t_gfx **g)
{
	*g = malloc(sizeof(t_gfx));
	if (!(*g))
		return (false);
	(*g)->mlx = NULL;
	(*g)->win = NULL;
	(*g)->img = NULL;
	(*g)->opt = NULL;
	if (!init_mlx(g) || !init_win(g) || !init_opt(g))
		return (false);
	if (!ft_init_img(g))
		return (false);
	return (true);
}
