/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sortfun00.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/18 21:53:38 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 23:10:38 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_pa(t_info *data, int fd)
{
	t_list	*temp;

	if (!data->stab)
		return ;
	temp = data->stab;
	data->stab = data->stab->nxt;
	temp->nxt = NULL;
	ft_lstadd_front(&data->staa, temp);
	ft_putstr_fd("pa\n", fd);
}

void	ft_pb(t_info *data, int fd)
{
	t_list	*temp;

	if (!data->staa)
		return ;
	if (data->staa->nxt == NULL)
		return ;
	temp = data->staa;
	data->staa = data->staa->nxt;
	temp->nxt = NULL;
	ft_lstadd_front(&data->stab, temp);
	ft_putstr_fd("pb\n", fd);
}

void	ft_ra(t_info *data, int fd)
{
	t_list	*temp;

	if (!data->staa)
		return ;
	temp = data->staa;
	data->staa = data->staa->nxt;
	temp->nxt = NULL;
	ft_lstadd_back(&data->staa, temp);
	ft_putstr_fd("ra\n", fd);
}

void	ft_rb(t_info *data, int fd)
{
	t_list	*temp;

	if (!data->stab)
		return ;
	temp = data->stab;
	data->stab = data->stab->nxt;
	temp->nxt = NULL;
	ft_lstadd_back(&data->stab, temp);
	ft_putstr_fd("rb\n", fd);
}
