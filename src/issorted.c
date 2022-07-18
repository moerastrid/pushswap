/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   issorted.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:42:01 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 21:44:42 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

int	ft_issorted_stb(t_list *lst)
{
	while (lst)
	{
		if (lst->nxt)
		{
			if (lst->nxt->con.ognr < lst->con.ognr)
				return (0);
		}
		lst = lst->nxt;
	}
	return (1);
}

int	ft_issorted_bts(t_list *lst)
{
	while (lst)
	{
		if (lst->nxt)
		{
			if (lst->nxt->con.ognr > lst->con.ognr)
				return (0);
		}
		lst = lst->nxt;
	}
	return (1);
}

int	ft_issorted(t_info *data)
{
	if (ft_issorted_stb(data->staa) == 1 && ft_issorted_bts(data->stab) == 1)
		return (1);
	return (0);
}
