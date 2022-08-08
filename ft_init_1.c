/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:38:07 by srobt             #+#    #+#             */
/*   Updated: 2022/04/02 14:42:47 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	loop(int fd, char **str, char ***arr)
{
	while (*str)
	{
		free(*str);
		*str = get_next_line(fd);
		if (!(*str))
			break ;
		*arr = ft_arradd(arr, *str);
		if (!(*arr))
		{
			ft_free_array(arr);
			ft_free_string(str);
			return (false);
		}
	}
	return (true);
}

static int	parse_map(int fd, t_map **m)
{
	char	**arr;
	char	*str;

	arr = NULL;
	if (fd == -1)
		return (false);
	str = ft_strdup("");
	if (!str || !loop(fd, &str, &arr) || !map_init(arr, m))
		return (false);
	ft_free_array(&arr);
	return (true);
}

int	ft_init(char *filename, t_gfx **g)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (false);
	if (!ft_init_gfx(g))
		return (false);
	if (!parse_map(fd, &(*g)->map))
	{
		ft_free_gfx(g);
		return (false);
	}
	close(fd);
	return (true);
}
