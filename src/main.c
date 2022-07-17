/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/01 15:42:01 by ageels        #+#    #+#                 */
/*   Updated: 2022/07/17 21:56:17 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

int	main(int argc, char **argv)
{
	t_info	data;

	if (ft_parse(argc, argv, &data) != 0)
	{
		//system("leaks push_swap");
		return (1);
	}
	//system("leaks push_swap");
	return (0);
}
