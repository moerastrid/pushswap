/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:42:01 by ageels            #+#    #+#             */
/*   Updated: 2022/08/10 16:37:14 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushlib.h"

int	main(int argc, char **argv)
{
	t_info	data;

	if (argc <= 1)
		return (1);
	if (ft_parse(argv, &data) != 0)
		return (1);
	if (argc <= 6)
		ft_smolsort(&data, 1);
	else
		ft_bigsort(&data, 1);
	return (0);
}
