/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:23:51 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:39:36 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_img(t_gfx **g)
{
	mlx_destroy_image((*g)->mlx, (*g)->img->ptr);
	free((*g)->img);
	(*g)->img = NULL;
}

void	ft_free_backbone(t_gfx **g)
{
	mlx_destroy_window((*g)->mlx, (*g)->win);
	free((*g)->opt);
	free((*g)->mlx);
	free(*g);
	*g = NULL;
}

void	ft_free_gfx(t_gfx **g)
{
	map_destroy(&(*g)->map);
	ft_free_img(g);
	ft_free_backbone(g);
}

void	em_exit(int code, t_gfx *g)
{
	ft_free_gfx(&g);
	exit(code);
}

void	error_close(char *msg)
{
	ft_putstr(msg);
	exit(FAIL);
}
