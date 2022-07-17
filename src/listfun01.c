/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   listfun01.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:42:01 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/17 20:37:58 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

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
