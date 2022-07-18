/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/19 19:52:39 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 21:11:56 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnum_fd(long long int nbr, int fd)
{
	char	c;

	c = '0';
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		ft_putnum_fd(nbr / 10, fd);
	c += nbr % 10;
	write(1, &c, 1);
}

void	ft_putlst_fd(t_list *lst, int fd)
{
	while (lst)
	{
		write(fd, "OG nr\t", 6);
		ft_putnum_fd(lst->con.ognr, fd);
		write(fd, "\t\tI nr ", 7);
		ft_putnum_fd(lst->con.inr, fd);
		write(fd, "\n", 1);
		lst = lst->nxt;
	}
}

void	ft_putstacks(t_info *data, int fd)
{
	if (data->staa)
	{
		ft_putstr_fd("stack A:\n", fd);
		ft_putlst_fd(data->staa, fd);
	}
	else
		ft_putstr_fd("no stack A\n", fd);
	if (data->stab)
	{
		ft_putstr_fd("stack B:\n", fd);
		ft_putlst_fd(data->stab, fd);
	}
	else
		ft_putstr_fd("no stack B\n", fd);
}
