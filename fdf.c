/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:56:43 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 16:09:04 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	error_check(int argc)
{
	if (argc != 2)
		error_close(MSG_ERROR_PATH);
}

static void	control(t_gfx *g)
{
	put_map(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img->ptr, 0, 0);
	mlx_key_hook(g->win, hook_dial_key, g);
	mlx_hook(g->win, EVENT_CLOSE, 0, hook_event_close, g);
	mlx_loop(g->mlx);
}

int	main(int argc, char **argv)
{
	t_gfx	*g;

	error_check(argc);
	if (!ft_init(*(++argv), &g))
		error_close(MSG_ERROR_INIT);
	control(g);
	ft_free_gfx(&g);
	exit(SUCCESS);
}
