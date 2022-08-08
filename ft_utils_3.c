/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:51:18 by srobt             #+#    #+#             */
/*   Updated: 2022/03/29 23:48:08 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_skip_sign(const char **sp)
{
	const char	c = **sp;

	if (c == '+' || c == '-')
	{
		(*sp)++;
		if (c == '-')
			return (1);
	}
	return (0);
}

static long	ft_atol_nat_sign(const char *s, int neg)
{
	long	limit;
	long	limit_digit;
	long	res;
	int		digit;

	limit = neg * LONG_MIN + !neg * LONG_MAX;
	limit_digit = limit % 10;
	limit /= 10;
	res = 0;
	while (ft_isdigit(*s))
	{
		digit = *s - '0';
		if ((!neg * (res > limit) + neg * (res < limit))
			|| (res == limit && digit == limit_digit))
		{
			if (neg)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		res *= 10;
		res += digit;
		s++;
	}
	return (res * -(neg * 2 - 1));
}

static long	ft_atol(const char *s)
{
	int	neg;

	while (ft_isspace(*s))
		s++;
	neg = ft_skip_sign(&s);
	return (ft_atol_nat_sign(s, neg));
}

int	ft_atoi(const char *s)
{
	return (ft_atol(s));
}
