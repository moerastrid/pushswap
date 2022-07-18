/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sortfun01.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 23:10:08 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 23:10:42 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_rra(t_info *data, int fd)
{
	t_list	*temp;

	if (!data->staa)
		return ;
	if (data->staa->nxt == NULL)
		return ;
	temp = ft_lstlast(data->staa);
	ft_lstonebeforelast(data->staa)->nxt = NULL;
	ft_lstadd_front(&data->staa, temp);
	ft_putstr_fd("rra\n", fd);
}

void	ft_rrb(t_info *data, int fd)
{
	t_list	*temp;

	if (!data->stab)
		return ;
	if (data->stab->nxt == NULL)
		return ;
	temp = ft_lstlast(data->stab);
	ft_lstonebeforelast(data->stab)->nxt = NULL;
	ft_lstadd_front(&data->stab, temp);
	ft_putstr_fd("rrb\n", fd);
}

void	ft_sa(t_info *data, int fd)
{
	t_cont	temp;

	temp = data->staa->con;
	data->staa->con = data->staa->nxt->con;
	data->staa->nxt->con = temp;
	ft_putstr_fd("sa\n", fd);
}

void	ft_sb(t_info *data, int fd)
{
	t_cont	temp;

	temp = data->stab->con;
	data->stab->con = data->stab->nxt->con;
	data->stab->nxt->con = temp;
	ft_putstr_fd("sb\n", fd);
}
