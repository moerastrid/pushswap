/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smolsort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 23:11:55 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 23:14:07 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_sort3(t_info *data)
{
	int	a;
	int	b;
	int	c;

	a = data->staa->con.inr;
	b = data->staa->nxt->con.inr;
	c = data->staa->nxt->nxt->con.inr;
	if (a < b && a < c && b > c)
	{
		ft_rra(data, 1);
		ft_sa(data, 1);
	}
	else if (b < a && b < c && a < c)
		ft_sa(data, 1);
	else if (b < a && b < c && a > c)
		ft_ra(data, 1);
	else if (a < b && a > c && b > c)
		ft_rra(data, 1);
	else if (a > b && a > c && b > c)
	{
		ft_ra(data, 1);
		ft_sa(data, 1);
	}
}

void	ft_smolsort(t_info *data)
{
	if (ft_issorted(data) == 1)
		return ;
	else if (ft_lstsize(data->staa) == 2)
		ft_ra(data, 1);
	else if (ft_lstsize(data->staa) == 3)
	{
		ft_sort3(data);
	}
}
