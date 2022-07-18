/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listfun00.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:42:01 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 22:58:48 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

t_list	*ft_lstnew(t_cont cont)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	newlst->con = cont;
	newlst->nxt = NULL;
	return (newlst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->nxt)
			break ;
		lst = lst->nxt;
	}
	return (lst);
}

t_list	*ft_lstonebeforelast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->nxt)
		return (NULL);
	while (lst)
	{
		if (!lst->nxt->nxt)
			break ;
		lst = lst->nxt;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->nxt = new;
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst)
		new->nxt = *lst;
	*lst = new;
}
