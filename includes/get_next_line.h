/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobt <srobt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:48:37 by srobt             #+#    #+#             */
/*   Updated: 2022/03/30 15:25:47 by srobt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

/* Linux specific */
# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_object
{
	char	*buffer;
	char	*line;
	char	*remainder;
	t_bool	*nl;
	ssize_t	n;
	size_t	i;
	size_t	j;
}	t_object;

void	*init_objects(t_object *o, char **store);
char	*split_method(t_object *o, char **store);
void	*concat_method(t_object *o, char **store);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
