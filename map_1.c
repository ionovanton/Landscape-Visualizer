/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:01:55 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:33:21 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init(char **a, t_map **m)
{
	*m = malloc(sizeof(t_map));
	if (!(*m))
		return (false);
	if (!map_get_size(a, *m))
	{
		free(*m);
		return (false);
	}
	(*m)->m = (t_point ***)malloc(sizeof(t_point **) * (*m)->h);
	if (!((*m)->m))
	{
		free(*m);
		return (false);
	}
	return (true);
}

int	map_init(char **a, t_map **m)
{
	int	i;
	int	j;

	if (!init(a, m))
		return (false);
	i = 0;
	while (i < (*m)->h)
	{
		(*m)->m[i] = (t_point **)malloc(sizeof(t_point *) * (*m)->w);
		if (!((*m)->m[i]))
			return (map_destroy(m));
		j = 0;
		while (j < (*m)->w)
		{
			(*m)->m[i][j] = (t_point *)malloc(sizeof(t_point));
			if (!(*m)->m[i][j])
				return (map_destroy(m));
			j++;
		}
		i++;
	}
	if (!map_fill(i, j, a, *m))
		return (map_destroy(m));
	return (true);
}

static void	apply(float x, float y, char **args, t_point *p)
{
	p->x = x;
	p->y = y;
	p->z = ft_atoi(args[0]);
	if (args[1])
		p->color = ft_hextoint(args[1]);
	else
		p->color = COLOR_WHITE;
}

static int	loop(int *i, int *j, char **line, t_map *m)
{
	char	**args;

	*j = 0;
	while (*j < m->w)
	{
		args = ft_split(line[*j], ',');
		if (!args)
		{
			free(line);
			return (false);
		}
		apply(*j, *i, args, m->m[*i][*j]);
		(*j)++;
		ft_free_array(&args);
	}
	return (true);
}

int	map_fill(int i, int j, char **a, t_map *m)
{
	char	**line;

	i = 0;
	while (i < m->h)
	{
		line = ft_split(a[i], ' ');
		if (!line)
			return (false);
		j = 0;
		while (j < m->w)
		{
			if (!loop(&i, &j, line, m))
				return (false);
		}
		ft_free_array(&line);
		i++;
	}
	return (true);
}
