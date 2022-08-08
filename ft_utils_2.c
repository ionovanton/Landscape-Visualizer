/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:22:48 by srobt             #+#    #+#             */
/*   Updated: 2022/03/30 16:56:47 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == 0)
			break ;
		n++;
		while (s[i] != c && s[i])
			i++;
	}
	return (n);
}

static void	*parse_words(const char *s, char c, char ***a)
{
	int	shift;
	int	i;
	int	j;

	shift = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == 0)
			break ;
		shift = i;
		while (s[i] != c && s[i])
			i++;
		(*a)[j] = NULL;
		(*a)[j] = ft_strndup(s + shift, i - shift);
		if (!(*a)[j])
			return (ft_free_array(a));
		j++;
	}
	(*a)[j] = NULL;
	return ((void *)1);
}

char	**ft_split(const char *s, char c)
{
	char	**a;

	a = NULL;
	a = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!a)
		return (NULL);
	if (!parse_words(s, c, &a))
		return (NULL);
	return (a);
}

int	absi(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

float	absf(float n)
{
	if (n < 0)
		n = -n;
	return (n);
}
