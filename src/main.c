/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:42:01 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/18 21:37:26 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

void	ft_smallsort(t_info *data)
{
	if (ft_issorted(data) == 1)
		return ;
}

int	main(int argc, char **argv)
{
	t_info	data;

	if (ft_parse(argc, argv, &data) != 0)
	{
		ft_putstacks(&data, 1);
		//system("leaks push_swap");
		return (1);
	}
	ft_putstacks(&data, 1);
	ft_smallsort(&data);
	if (ft_issorted(&data) == 1)
		ft_putstr_fd("\nsorted\n\n", 1);
	//system("leaks push_swap");
	return (0);
}
