/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:01:40 by srobt             #+#    #+#             */
/*   Updated: 2022/04/01 14:22:19 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_destroy(t_map **m)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*m)->h)
	{
		j = 0;
		while (j < (*m)->w)
			free((*m)->m[i][j++]);
		free((*m)->m[i]);
		i++;
	}
	free((*m)->m);
	free(*m);
	*m = NULL;
	return (false);
}

int	map_get_size(char **a, t_map *m)
{
	char	**line;

	m->h = 0;
	m->w = 0;
	line = ft_split(a[0], ' ');
	if (!line)
		return (false);
	while (line[m->w])
		m->w++;
	while (a[m->h])
		m->h++;
	ft_free_array(&line);
	return (true);
}
