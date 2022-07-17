/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfun00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:47:24 by ageels            #+#    #+#             */
/*   Updated: 2022/07/10 21:03:38 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		ft_lstlast(*lst)->nxt = new;
	}
	else
	{
		*lst = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->nxt = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(t_cont))
{
	t_list	*temp;

	if (!(*lst))
		return ;
	temp = *lst;
	while (temp)
	{
		temp = (*lst)->nxt;
		ft_putstr_fd("hoi4\n", 1);
		del((*lst)->con);
		ft_putstr_fd("hoi5\n", 1);
		free(*lst);
		*lst = temp;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(t_cont))
{
	if (!lst || !del)
		return ;
	del(lst->con);
	free(lst);
	lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(t_cont))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->con);
		temp = temp->nxt;
	}
}
