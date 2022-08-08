/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:51:58 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:11:52 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "fdf.h"

# ifdef T_BOOL
#  undef T_BOOL

typedef enum e_bool
{
	false,
	true
}	t_bool;
# endif

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	***m;
	int		w;
	int		h;
}	t_map;

typedef struct s_image
{
	void	*ptr;
	char	*address;
	int		bpp;
	int		length;
	int		endian;
}	t_image;

typedef struct s_opt
{
	float	angle_shift;
	float	angle;
	int		zoom;
	int		zoom_shift;
	int		offset_x;
	int		offset_y;
	int		offset;
	int		projection;
}	t_opt;

typedef struct s_gfx
{
	t_image	*img;
	t_map	*map;
	t_opt	*opt;
	void	*mlx;
	void	*win;
}	t_gfx;

#endif // TYPEDEF_H
