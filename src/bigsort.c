/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:24:19 by ageels            #+#    #+#             */
/*   Updated: 2022/07/20 23:07:50 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_bigsort(t_info *data, int fd)
{
	int	i;
	int	half;

	i = 0;
	half = data->total / 2;
	while (i < data->total)
	{
		if (data->staa->con.inr > half)
			ft_pb(data, fd);
		else
			ft_ra(data, fd);
		i++;
	}
}
