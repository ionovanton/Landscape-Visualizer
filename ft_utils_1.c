/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:08:19 by srobt             #+#    #+#             */
/*   Updated: 2022/03/30 16:09:43 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_arrlen(char **a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
		i++;
	i++;
	p = malloc(i * sizeof(char));
	if (!p)
		return ((void *)0);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_arradd(char ***a, char *s)
{
	const int	old_length = ft_arrlen(*a);
	char		**new;
	int			i;

	new = (char **)malloc(sizeof(char *) * (old_length + 1 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_length)
	{
		new[i] = (*a)[i];
		i++;
	}
	new[i++] = ft_strdup(s);
	if (!new[i - 1])
	{
		ft_free_array(&new);
		return (NULL);
	}
	new[i] = NULL;
	free(*a);
	*a = NULL;
	return (new);
}
