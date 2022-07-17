/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:42:01 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/17 22:07:35 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_calc_con(t_list *lst)
{
	int	size;

	size = ft_lstsize(lst);
	while (size >= 0)
	{
		//hier moeten alle getallen hun uiteindelijke plek in inr krijgen. ^^
	}
}

int	ft_error(t_info *data, int a)
{
	ft_putstr_fd("Error\n", 1);
	if (data->staa)
		ft_lstclear(&data->staa);
	if (data->stab)
		ft_lstclear(&data->stab);
	return (a);
}

int	ft_is_nr_double(int nr, t_info *data)
{
	t_list	*temp;

	temp = data->staa;
	while (temp)
	{
		if (temp->con.ognr == nr)
			return (1);
		temp = temp->nxt;
	}
	if (nr > data->bigst)
		data->bigst = nr;
	if (nr < data->smolst)
		data->smolst = nr;
	return (0);
}

int	ft_parse(int argc, char **argv, t_info *data)
{
	int		i;
	int		rv;
	int		nrfied;
	t_cont	con;

	if (argc <= 1)
		return (ft_error(data, 1));
	data->bigst = INT32_MIN;
	data->smolst = INT32_MAX;
	i = 1;
	rv = 0;
	while (argv[i] != NULL)
	{
		nrfied = ft_atoi(argv[i], &rv);
		if (rv != 0)
			return (ft_error(data, 1));
		if (ft_is_nr_double(nrfied, data) == 1)
			return (ft_error(data, 1));
		con.ognr = nrfied;
		con.inr = -1;
		ft_lstadd_back(&data->staa, ft_lstnew(con));
		i++;
	}
	ft_calc_con(data->staa);
	return (0);
}
