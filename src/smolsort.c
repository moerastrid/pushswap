/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smolsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:11:55 by ageels            #+#    #+#             */
/*   Updated: 2022/07/20 21:12:11 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_sort3(t_info *data, int fd)
{
	int	a;
	int	b;
	int	c;

	a = data->staa->con.inr;
	b = data->staa->nxt->con.inr;
	c = data->staa->nxt->nxt->con.inr;
	if (a < b && a < c && b > c)
	{
		ft_rra(data, fd);
		ft_sa(data, fd);
	}
	else if (b < a && b < c && a < c)
		ft_sa(data, fd);
	else if (b < a && b < c && a > c)
		ft_ra(data, fd);
	else if (a < b && a > c && b > c)
		ft_rra(data, fd);
	else if (a > b && a > c && b > c)
	{
		ft_ra(data, fd);
		ft_sa(data, fd);
	}
}

void	ft_sort4(t_info *data, int fd)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = data->staa->con.inr;
	b = data->staa->nxt->con.inr;
	c = data->staa->nxt->nxt->con.inr;
	d = data->staa->nxt->nxt->nxt->con.inr;
	if (b < a && b < c && b < d)
		ft_sa(data, fd);
	else if (c < a && c < b && c < d)
	{
		ft_ra(data, fd);
		ft_sa(data, fd);
	}
	else if (d < a && d < b && d < c)
		ft_rra(data, fd);
	if (ft_issorted(data) == 0)
	{
		ft_pb(data, fd);
		ft_sort3(data, fd);
		ft_pa(data, fd);
	}
}

static void	ft_fill_temparray(t_info *data, int *a)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = data->staa;
	while (i < 5)
	{
		a[i] = temp->con.inr;
		temp = temp->nxt;
		i++;
	}
}

void	ft_sort5(t_info *data, int fd)
{
	int		a[5];

	ft_fill_temparray(data, a);
	if (a[1] < a[0] && a[1] < a[2] && a[1] < a[3] && a[1] < a[4])
		ft_sa(data, fd);
	else if (a[2] < a[0] && a[2] < a[1] && a[2] < a[3] && a[2] < a[4])
	{
		ft_ra(data, fd);
		ft_sa(data, fd);
	}
	else if (a[3] < a[0] && a[3] < a[1] && a[3] < a[2] && a[3] < a[4])
	{
		ft_rra(data, fd);
		ft_rra(data, fd);
	}
	else if (a[4] < a[0] && a[4] < a[1] && a[4] < a[2] && a[4] < a[3])
		ft_rra(data, fd);
	if (ft_issorted(data) == 0)
	{
		ft_pb(data, fd);
		ft_sort4(data, fd);
		ft_pa(data, fd);
	}
}

void	ft_smolsort(t_info *data, int fd)
{
	if (ft_issorted(data) == 1)
		return ;
	else if (ft_lstsize(data->staa) == 2)
		ft_ra(data, fd);
	else if (ft_lstsize(data->staa) == 3)
		ft_sort3(data, fd);
	else if (ft_lstsize(data->staa) == 4)
		ft_sort4(data, fd);
	else if (ft_lstsize(data->staa) == 5)
		ft_sort5(data, fd);
}
