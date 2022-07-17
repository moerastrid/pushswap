/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libfun.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:51:25 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/01 15:53:45 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

size_t	ft_strlen(const char *string)
{
	int	a;

	a = 0;
	if (!string)
		return (0);
	while (string[a] != 0)
		a++;
	return (a);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
