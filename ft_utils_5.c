/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:30:31 by srobt             #+#    #+#             */
/*   Updated: 2022/03/31 12:54:08 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

float	max2f(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	max2i(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
