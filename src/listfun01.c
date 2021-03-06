/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfun01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:42:01 by ageels            #+#    #+#             */
/*   Updated: 2022/07/20 19:08:04 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (size);
	while (lst != NULL)
	{
		lst = lst->nxt;
		size++;
	}
	return (size);
}

void	ft_lstdelone(t_list *lst)
{
	if (lst)
		free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!(*lst))
		return ;
	temp = *lst;
	while (temp)
	{
		temp = (*lst)->nxt;
		ft_lstdelone(*lst);
		*lst = temp;
	}
}
