/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:24:19 by ageels            #+#    #+#             */
/*   Updated: 2022/08/10 16:10:51 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"
#include <stdio.h>

int	ft_find_one(t_info *data)
{
	t_list	*temp;

	temp = data->staa;
	while (temp)
	{
		if (temp->con.inr > 0)
			return (1);
		temp = temp->nxt;
	}
	temp = data->stab;
	while (temp)
	{
		if (temp->con.inr > 0)
			return (1);
		temp = temp->nxt;
	}
	return (0);
}

void	ft_bigsort(t_info *data, int fd)
{
	int		i;
	t_list	*temp;

	while (ft_find_one(data) == 1 && ft_issorted(data) == 0)
	{
		i = 0;
		while (i < data->total)
		{
			if (data->staa->con.inr % 2 == 0)
				ft_pb(data, fd);
			else
				ft_ra(data, fd);
			i++;
		}
		while (data->stab)
			ft_pa(data, fd);
		temp = data->staa;
		while (temp)
		{
			temp->con.inr = temp->con.inr / 2;
			temp = temp->nxt;
		}
	}
	while (data->stab)
		ft_pa(data, fd);
}
