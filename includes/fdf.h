/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:46:02 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:39:57 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>		// malloc free exit
# include <unistd.h>		// close read write
# include <fcntl.h>			// open
# include <stdio.h>			// perror
# include "typedef.h"
# include "get_next_line.h"
# include "define.h"

// Draw
void	put_pixel(t_point *p, t_gfx *g);
void	put_line(void (*f)(t_point, t_point, t_gfx *), \
t_point *a, t_point *b, t_gfx *g);
void	bresenham(t_point a, t_point b, t_gfx *g);
void	put_background(int color, t_gfx *g);
void	put_map(t_gfx *g);
void	gfx_options(t_point *a, t_point *b, t_opt *opt);
int		gfx_get_color(t_point cur, t_point start, t_point end, t_point delta);

// Map
int		map_init(char **a, t_map **m);
int		map_get_size(char **a, t_map *m);
int		map_fill(int i, int j, char **a, t_map *m);
int		map_destroy(t_map **m);

// Hook
int		hook_dial_key(int key, t_gfx *g);
int		hook_event_close(t_gfx *g);

// Init & Free
int		ft_init(char *filename, t_gfx **g);
int		ft_init_gfx(t_gfx **g);
int		ft_init_img(t_gfx **g);
void	ft_free_gfx(t_gfx **g);
void	ft_free_img(t_gfx **g);
void	ft_free_backbone(t_gfx **g);
void	em_exit(int code, t_gfx *g);
void	error_close(char *msg);

// Utils
void	ft_putstr(char *str);
void	*ft_free_array(char ***a);
void	*ft_free_string(char **s);
char	**ft_arradd(char ***a, char *s);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int n);
int		ft_hextoint(char *hex);
int		ft_atoi(const char *s);
int		ft_arrlen(char **a);
int		ft_strlen(char *s);
int		ft_isspace(char c);
int		ft_isdigit(char c);
float	max2f(float a, float b);
float	absf(float n);
int		max2i(int a, int b);
int		absi(int n);

#endif // FDF_H
