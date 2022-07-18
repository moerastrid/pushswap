/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libfun01.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 17:22:02 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 21:10:45 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

int	ft_isdigit(int c)
{
	int	a;

	a = 0;
	if (c >= '0' && c <= '9')
		a = 1;
	return (a);
}

static int	ft_atoi_start(int *a, const char *s, int *rv)
{
	int	mc;

	mc = 1;
	if (!s)
		*rv = 1;
	while (s[*a] == ' ' || s[*a] == '\t' || s[*a] == '\v' \
		|| s[*a] == '\f' || s[*a] == '\r' || s[*a] == '\n')
	{
		(*a)++;
	}
	while ((s[*a] == '+') || (s[*a] == '-'))
	{
		if (s[*a] == '-')
			mc *= -1;
		(*a)++;
	}
	if (s[*a] == '\0')
		*rv = 1;
	return (mc);
}

int	ft_atoi(const char *s, int *rv)
{
	int				a;
	long long int	n;
	int				minc;

	a = 0;
	n = 0;
	minc = ft_atoi_start(&a, s, rv);
	while (s[a] != '\0')
	{
		if (ft_isdigit(s[a]) != 1)
		{
			*rv = 1;
			return (0);
		}
		n = (n * 10) + (s[a] - '0');
		if (n > 2147483648 || (minc == 1 && n > 2147483647))
		{
			*rv = 1;
			return (0);
		}
		a++;
	}
	return (n * minc);
}

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
