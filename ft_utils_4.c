/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:47:29 by srobt             #+#    #+#             */
/*   Updated: 2022/04/01 11:54:14 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_free_string(char **s)
{
	if (!(*s))
		return (NULL);
	free(*s);
	*s = NULL;
	return (NULL);
}

void	*ft_free_array(char ***a)
{
	int	i;

	i = 0;
	if (!(*a))
		return (NULL);
	while ((*a)[i])
		ft_free_string(&(*a)[i++]);
	free(*a);
	*a = NULL;
	return (NULL);
}

int	ft_hextoint(char *hex)
{
	int	byte;
	int	value;

	value = 0;
	hex++;
	hex++;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		value = (value << 4) | (byte & 0xF);
	}
	return (value);
}
