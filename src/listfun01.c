/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listfun01.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/27 15:47:24 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/04 14:56:15 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

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

t_list	*ft_lstmap(t_list *lst, t_cont (*f)(t_cont), void (*del)(t_cont))
{
	t_list	*my_return_list;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	my_return_list = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->con));
		if (temp)
			ft_lstadd_back(&my_return_list, temp);
		else if (del)
		{
			ft_lstclear(&my_return_list, del);
			break ;
		}
		lst = lst->nxt;
	}
	return (my_return_list);
}

t_list	*ft_lstnew(t_cont cont)
{
	t_list	*myfirstlist;

	myfirstlist = malloc(sizeof(t_list));
	if (myfirstlist == 0)
		return (0);
	if (myfirstlist != NULL)
	{
		myfirstlist->con = cont;
		myfirstlist->nxt = NULL;
	}
	return (myfirstlist);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	i = 1;
	temp = lst;
	while (temp->nxt)
	{
		temp = temp->nxt;
		i++;
	}
	return (i);
}
