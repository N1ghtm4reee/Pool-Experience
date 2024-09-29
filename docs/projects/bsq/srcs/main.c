/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:08:02 by yalazrek          #+#    #+#             */
/*   Updated: 2024/09/18 20:59:18 by yalazrek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_file();
		argv[0] = "francawiii";
		if (ft_bsq(argv[0]) == 1)
			write(2, "map error\n", 11);
	}
	while (i < argc)
	{
		if (i > 1)
			ft_putchar('\n');
		if (ft_bsq(argv[i]) == 1)
			write(2, "map error\n", 11);
		i++;
	}
	return (0);
}
