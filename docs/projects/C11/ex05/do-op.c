/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhrif <aakhrif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:56:37 by aakhrif           #+#    #+#             */
/*   Updated: 2024/09/18 13:03:42 by aakhrif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	do_op(int nb1, int nb2, char *op)
{
	void	(*operation[5])(int, int);

	operation[0] = &ft_sum;
	operation[1] = &ft_sub;
	operation[2] = &ft_mult;
	operation[3] = &ft_div;
	operation[4] = &ft_mod;
	if (op[0] == '+')
		(*operation[0])(nb1, nb2);
	else if (op[0] == '-')
		(*operation[1])(nb1, nb2);
	else if (op[0] == '*')
		(*operation[2])(nb1, nb2);
	else if (op[0] == '/')
		(*operation[3])(nb1, nb2);
	else if (op[0] == '%')
		(*operation[4])(nb1, nb2);
	else
		write(1, "0", 1);
}

int	main(int ac, char **av)
{
	int	nb1;
	int	nb2;

	if (ac == 4)
	{
		nb1 = ft_atoi(av[1]);
		nb2 = ft_atoi(av[3]);
		if (ft_strlen(av[2]) != 1)
			write(1, "0\n", 2);
		else if (av[2][0] == '/' && nb2 == 0)
			write(1, "Stop : division by zero\n", 24);
		else if (av[2][0] == '%' && nb2 == 0)
			write(1, "Stop : modulo by zero\n", 22);
		else
		{
			do_op(nb1, nb2, av[2]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
